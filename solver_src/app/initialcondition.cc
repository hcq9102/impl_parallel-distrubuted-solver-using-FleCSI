#include "initialcondition.hh"
#include "specialization/control.hh"
#include "state.hh"
#include "tasks/initialcondition.hh"
#include "input.hh"

using namespace flecsi;

void springmass::action::initialcondition(control_policy &cp) {
  flecsi::execute<task::initialcondition>(cp.m, displacementsd(cp.m),velocitiesd(cp.m),massesd(cp.m),stiffnessesd(cp.m), masses, stiffnesses, displacements, velocities);

  std::cout << "excute initcondition task" << std::endl;

} // init_condition