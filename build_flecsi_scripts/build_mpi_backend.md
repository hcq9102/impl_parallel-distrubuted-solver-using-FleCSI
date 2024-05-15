### build mpi backend of flecsi
chuanqiu@rostam1:/work/chuanqiu/zzzzzzzzzzsimulation/mybuild$ srun -p medusa -N 1 --pty /bin/bash -l

module load gcc/12.2.0 cmake/3.23.2 git openmpi

chuanqiu@medusa00:/work/chuanqiu/zzzzzzzzzzsimulation/mybuild$ git clone https://github.com/spack/spack.git 
source spack/share/spack/setup-env.sh          
spack env create qenv
spack env activate -p qenv  

chuanqiu@medusa00:/work/chuanqiu/zzzzzzzzzzsimulation/mybuild$ spack add flecsi@2.2 backend=mpi
chuanqiu@medusa00:/work/chuanqiu/zzzzzzzzzzsimulation/mybuild$ spack install

### run

[myenv] chuanqiu@medusa00:/work/chuanqiu/zzzzzzzzzzsimulation/mybuild$ cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=/work/chuanqiu/zzzzzzzzzzsimulation_multi/mybuild/.spack-env/view -DFleCSI_DIR=/work/chuanqiu/zzzzzzzzzzsimulation_multi/mybuild/.spack-env/view/lib64/cmake/FleCSI ..

[myenv] chuanqiu@medusa00:/work/chuanqiu/zzzzzzzzzzsimulation/mybuild$ make

[myenv] chuanqiu@medusa00:/work/chuanqiu/zzzzzzzzzzsimulation/mybuild$ mpirun -n 1 ./euler1D
