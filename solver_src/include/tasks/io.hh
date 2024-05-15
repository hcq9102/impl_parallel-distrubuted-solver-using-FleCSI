#ifndef SPRINGMASS_TASKS_IO_HH
#define SPRINGMASS_TASKS_IO_HH

#include "specialization/mesh1D.hh"

#include <string>

namespace springmass {
namespace task {

void io(mesh::accessor<ro> m, field<double>::accessor<ro, ro> da,
        field<double>::accessor<ro, ro> va, std::string filebase);

// void print(mesh::accessor<ro> m, field<double>::accessor<ro, ro> fa);

} // namespace task
} // namespace springmass

#endif