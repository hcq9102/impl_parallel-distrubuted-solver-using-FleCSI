#ifndef SPRINGMASS_SOLVE_HH
#define SPRINGMASS_SOLVE_HH

#include "specialization/control.hh"

namespace springmass::action{
    
    void solve(control_policy &);
    inline control::action<solve, cp::solve> solve_action;

} // namespace springmass

#endif