#ifndef SPRINGMASS_SPECIALIZATION_CONTROL_HH
#define SPRINGMASS_SPECIALIZATION_CONTROL_HH

#include <flecsi/flog.hh>
#include <flecsi/run/control.hh>

#include "mesh1D.hh"

namespace springmass {

// Define 4 FleCSI control-point identifiers.
enum class cp { readfile, initialize, solve, finalize };

// Overload "*" to convert a control-point identifier to a string.
// In a larger program in which this function appeared in a header
// file, it could be declared inline.
inline const char *
operator*(cp control_point) {
  switch (control_point) {
    case cp::readfile:
      return "readfile";
    case cp::initialize:
      return "initialize";
    case cp::solve:
      return "solve";
    case cp::finalize:
      return "finalize";
  }
  flog_fatal("invalid control point");
}

// Define a control policy that specifies that "initialize" should run
// first, then "preprocess, solve,and finally "finalize".
struct control_policy : flecsi::run::control_base {
  using control_points_enum = cp;
  struct node_policy {
  };

  using control_points =
      list<point<cp::readfile>, point<cp::initialize>, point<cp::solve>, point<cp::finalize>>;

  mesh::slot m; // initial mesh
};

// Define a fully qualified control type that implements our control policy.
using control = flecsi::run::control<control_policy>;

} // namespace springmass

#endif