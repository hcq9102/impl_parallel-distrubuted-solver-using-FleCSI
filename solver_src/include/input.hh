#ifndef SPRINGMASS_INPUT_HH
#define SPRINGMASS_INPUT_HH

#include <string>
#include <vector>

    // global variables
extern std::vector<double> masses, stiffnesses, displacements, velocities;
namespace springmass {

extern void readinput(const std::string &filename,
                                    std::vector<double> &masses,
                                    std::vector<double> &stiffnesses,
                                    std::vector<double> &displacements,
                                    std::vector<double> &velocities);

}
#endif