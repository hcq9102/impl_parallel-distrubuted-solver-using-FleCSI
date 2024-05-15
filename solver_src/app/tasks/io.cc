#include "tasks/io.hh"

#include <sstream>

using namespace flecsi;

void springmass::task::io(mesh::accessor<ro> m,
                          field<double>::accessor<ro, ro> da,
                          field<double>::accessor<ro, ro> va,
                          std::string filebase) {
  auto d = m.mdspan<mesh::vertices>(da);
  auto v = m.mdspan<mesh::vertices>(va);





  // std::stringstream ss;
  // ss << filebase;
  // if (processes() == 1) {
  //   ss << ".csv";
  // } else {
  //   ss << "-" << process() << ".csv";
  // } // if

  // std::ofstream solution(ss.str(), std::ofstream::out);
  ///////modify here

  //   for(auto j : m.vertices<mesh::y_axis, mesh::logical>()) {
  //     const double y = m.value<mesh::y_axis>(j);
  //     for(auto i : m.vertices<mesh::x_axis, mesh::logical>()) {
  //       const double x = m.value<mesh::x_axis>(i);
  //       solution << x << " " << y << " " << u[j][i] << std::endl;
  //     } // for
  //   } // for
} // io

