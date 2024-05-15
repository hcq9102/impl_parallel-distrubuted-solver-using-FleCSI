#include "finalize.hh"
#include "state.hh"
#include "tasks/io.hh"

using namespace flecsi;

void springmass::action::finalize(control_policy &cp) {
  execute<task::io, mpi>(cp.m, displacementsd(cp.m), velocitiesd(cp.m),
                         "solution_euler"); // mpi???
} // finalize