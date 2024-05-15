#ifndef SPRINGMASS_STATE_HH
#define SPRINGMASS_STATE_HH

#include "specialization/mesh1D.hh"

// filed definition
namespace springmass {

inline const field<double>::definition<mesh, mesh::vertices> displacementsd;
inline const field<double>::definition<mesh, mesh::vertices> velocitiesd;

inline const field<double>::definition<mesh, mesh::vertices> massesd; // m1, m2
inline const field<double>::definition<mesh, mesh::vertices> stiffnessesd; // k1, k2

} // namespace springmass

#endif
