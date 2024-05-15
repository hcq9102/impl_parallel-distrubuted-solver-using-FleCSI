#ifndef SPRINGMASS_FINALIZE_HH
#define SPRINGMASS_FINALIZE_HH

#include "specialization/control.hh"

namespace springmass {
namespace action {

void finalize(control_policy &);
inline control::action<finalize, cp::finalize> finalize_action;

} // namespace action
} // namespace springmass

#endif