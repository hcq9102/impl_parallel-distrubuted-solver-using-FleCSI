#ifndef SPRINGMASS_TASKS_INITIALCONDITION_HH
#define SPRINGMASS_TASKS_INITIALCONDITION_HH

#include "specialization/mesh1D.hh"
#include "input.hh"
#include "readfile.hh"
#include <string>
#include <vector>

namespace springmass {
namespace task {

void initialcondition(mesh::accessor<ro> m, field<double>::accessor<wo, na> da,
              field<double>::accessor<wo, na> va,
              field<double>::accessor<wo, na> ma,
              field<double>::accessor<wo, na> ka, 
              const std::vector<double>& masses,
              const std::vector<double>& stiffnesses,
              const std::vector<double>& displacements,
              const std::vector<double>& velocities);

} // namespace task
} // namespace springmass

#endif