#ifndef SPRINGMASS_TASKS_COMPUTE_HH
#define SPRINGMASS_TASKS_COMPUTE_HH

#include "specialization/mesh1D.hh"

namespace springmass {
namespace task {

void solver_d(mesh::accessor<ro> m, field<double>::accessor<rw, ro> da,
            field<double>::accessor<rw, ro> va);


void solver_v(mesh::accessor<ro> m, field<double>::accessor<rw, ro> da,
            field<double>::accessor<rw, ro> va, field<double>::accessor<ro, ro> ka, field<double>::accessor<ro, ro> ma);

} // namespace task
} // namespace springmass

#endif
