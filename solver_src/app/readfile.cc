#include "readfile.hh"
#include "state.hh"
#include "tasks/initialcondition.hh"
#include "input.hh"
#include <string>

using namespace flecsi;

void springmass::action::readfile(control_policy &cp) {
  
  // readfile and return all vectors
  readinput("spring_system_4000000.txt", masses, stiffnesses, displacements, velocities);
} // initreadfile
