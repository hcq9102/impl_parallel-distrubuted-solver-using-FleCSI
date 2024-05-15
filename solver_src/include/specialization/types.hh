/*
   Copyright (c) 2016, Triad National Security, LLC
   All rights reserved.
*/
#ifndef SPRINGMASS_SPECIALIZATION_TYPES_HH
#define SPRINGMASS_SPECIALIZATION_TYPES_HH

#include <flecsi/data.hh>

namespace springmass {

inline constexpr flecsi::partition_privilege_t na = flecsi::na, ro = flecsi::ro,
                                               wo = flecsi::wo, rw = flecsi::rw;

template <typename T, flecsi::data::layout L = flecsi::data::layout::dense>
using field = flecsi::field<T, L>;

} // namespace springmass

#endif