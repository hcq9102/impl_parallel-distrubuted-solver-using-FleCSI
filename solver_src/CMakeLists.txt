cmake_minimum_required(VERSION 3.12...3.19)

# Set project name
project(Euler1D LANGUAGES CXX C)

# FleCSI currently depends on C++ 17
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# Find the FleCSI installation.
#
# The easiest way to help CMake find FleCSI is to install it,
# and add the location to the CMAKE_PREFIX_PATH environment variable.

find_package(FleCSI REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(euler1D_for_4000000 app/input.cc app/readfile.cc app/initialize.cc app/tasks/initialcondition.cc  app/initialcondition.cc    app/tasks/compute.cc app/solve.cc app/tasks/io.cc app/finalize.cc Euler1D.cc) 
target_link_libraries(euler1D_for_4000000 FleCSI::FleCSI)
set(CMAKE_BUILD_TYPE "Release")
#target_compile_options(euler1D PRIVATE -g)


# APP
#add_subdirectory(app)