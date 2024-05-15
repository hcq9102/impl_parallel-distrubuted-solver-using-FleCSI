#ifndef SPRINGMASS_READFILE_HH
#define SPRINGMASS_READFILE_HH

#include "specialization/control.hh"

namespace springmass {
namespace action {

void readfile(control_policy &);

inline control::action<readfile, cp::readfile> readfile_action;

} // namespace action
} // namespace springmass

#endif