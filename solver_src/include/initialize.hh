#ifndef SPRINGMASS_INITIALIZE_HH
#define SPRINGMASS_INITIALIZE_HH

#include "specialization/control.hh"


namespace springmass {
namespace action {

void init_mesh(control_policy &);

inline control::action<init_mesh, cp::initialize> init_mesh_action;

} // namespace action
} // namespace springmass

#endif

