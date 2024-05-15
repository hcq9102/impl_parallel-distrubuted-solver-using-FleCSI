#include "initialize.hh"
#include "readfile.hh"
#include "state.hh"
#include "tasks/initialcondition.hh"
#include "specialization/mesh1D.hh"
#include <vector>


using namespace flecsi;
std::vector<double> masses, stiffnesses, displacements, velocities;
void springmass::action::init_mesh(control_policy &cp) {

  mesh::gcoord axis_extents{masses.size()}; // size of masses
  std::cout << "masses.size() = " << masses.size() << std::endl;
  mesh::cslot coloring;
  coloring.allocate(flecsi::processes(), axis_extents);

  cp.m.allocate(coloring.get());

} // init_mesh