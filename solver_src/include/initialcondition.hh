#ifndef SPRINGMASS_INITIALCONDITION_HH
#define SPRINGMASS_INITIALCONDITION_HH

#include "initialize.hh"
#include "specialization/control.hh"

namespace springmass {
namespace action {

void initialcondition(control_policy &);

inline control::action<initialcondition, cp::initialize> initialcondition_act;
inline auto const initial_cond_dep = initialcondition_act.add(init_mesh_action); 
// initial dependency, first init mesh, then initial_cond action.

} // namespace action
} // namespace springmass

#endif