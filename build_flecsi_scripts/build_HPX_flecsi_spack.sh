#!/bin/bash -e

#SBATCH --job-name=flecsi_spack_build
#SBATCH --output=flecsi_spack_build.out
#SBATCH --nodes=1
#SBATCH --time=05:00:00
#SBATCH --partition=medusa

# set -xe
module purge
module load gcc/12.2.0 cmake git 

BASE_DIR=$(pwd)
SPACK_DIR=${BASE_DIR}/spack
FLECSI_DIR=${BASE_DIR}/../flecsi2

mkdir -p ${BASE_DIR}

if [ ! -d ${FLECSI_DIR} ]; then
  git clone --branch task_local2 https://github.com/STEllAR-GROUP/flecsi2.git ${FLECSI_DIR}
fi
if [ ! -d ${SPACK_DIR} ]; then
git clone https://github.com/spack/spack.git ${SPACK_DIR}
source ${SPACK_DIR}/share/spack/setup-env.sh
spack env create -d ${BASE_DIR}
spack env activate -p ${BASE_DIR}
sed -i 's/unify: false/unify: true/' ${BASE_DIR}/spack.yaml
spack repo add ${FLECSI_DIR}/spack-repo/
spack external find ninja cmake python autoconf automake perl m4 ca-certificates-mozilla
#build type options(1,2,3):
#1. explicitly specify build type--Debug for both
# spack add flecsi%gcc@12.2.0 backend=hpx +flog build_type=Debug ^hpx@master build_type=Debug ^boost@1.80.0
#2. explicitly specify build type--Release for both
# spack add flecsi%gcc@12.2.0 backend=hpx +flog build_type=Release ^hpx@master build_type=Release ^boost@1.80.0

#3. dont explicitly specify build type
spack add flecsi%gcc@12.2.0 backend=hpx +flog ^hpx@master ^boost@1.80.0
spack concretize -f
spack install
else
  source ${SPACK_DIR}/share/spack/setup-env.sh
  spack env activate -p ${BASE_DIR}
fi


#Release type
cmake -S ${FLECSI_DIR} -B ${FLECSI_DIR}/cmake-build_release -DFLECSI_BACKEND=hpx -DENABLE_FLOG=ON -DENABLE_UNIT_TESTS=ON -DCMAKE_BUILD_TYPE=Release 
cmake --build ${FLECSI_DIR}/cmake-build_release/ --parallel

#Debug type
cmake -S ${FLECSI_DIR} -B ${FLECSI_DIR}/cmake-build_debug -DFLECSI_BACKEND=hpx -DENABLE_FLOG=ON -DENABLE_UNIT_TESTS=ON -DCMAKE_BUILD_TYPE=Debug 
cmake --build ${FLECSI_DIR}/cmake-build_debug/ --parallel


#ctest
cd ${FLECSI_DIR}/cmake-build_release/
ctest

cd ${FLECSI_DIR}/cmake-build_debug/
ctest

#exit spack
despacktivate



