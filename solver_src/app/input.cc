#include "input.hh"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <flecsi/execution.hh>


using namespace flecsi;


namespace springmass{
void readinput(const std::string &filename,
                                    std::vector<double> &masses,
                                    std::vector<double> &stiffnesses,
                                    std::vector<double> &displacements,
                                    std::vector<double> &velocities) {

  std::ifstream inputFile(filename);
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return;
  }
  

  double mass, stiffness, displacement, velocity;
  while (inputFile >> mass >> stiffness >> displacement >> velocity) {
    masses.push_back(mass);
    stiffnesses.push_back(stiffness);
    displacements.push_back(displacement);
    velocities.push_back(velocity);
  }

  inputFile.close();
  std::cout << "readinput.cc " << std::endl;
}
}
