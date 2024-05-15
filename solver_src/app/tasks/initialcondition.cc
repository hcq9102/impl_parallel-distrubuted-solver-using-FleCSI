#include "specialization/mesh1D.hh"
#include "readfile.hh"
#include "input.hh"
#include "tasks/initialcondition.hh"

using namespace flecsi;

// fill span using given vertors
void springmass::task::initialcondition(mesh::accessor<ro> m,
                                        field<double>::accessor<wo, na> da,
                                        field<double>::accessor<wo, na> va,
                                        field<double>::accessor<wo, na> ma,
                                        field<double>::accessor<wo, na> ka,
                                        const std::vector<double>& masses,
                                        const std::vector<double>& stiffnesses,
                                        const std::vector<double>& displacements,
                                        const std::vector<double>& velocities) {
                                        
  auto d = m.mdspan<mesh::vertices>(da);
  auto v = m.mdspan<mesh::vertices>(va);
  auto mas = m.mdspan<mesh::vertices>(ma);
  auto k = m.mdspan<mesh::vertices>(ka);


  // clang-format off
    // initialize real elements
    for(auto i: m.vertices<mesh::x_axis, mesh::logical>()) {
      d[i] = displacements[m.global_id<mesh::x_axis>(i)];
      v[i] = velocities[m.global_id<mesh::x_axis>(i)];
      mas[i] = masses[m.global_id<mesh::x_axis>(i)];
      k[i] = stiffnesses[m.global_id<mesh::x_axis>(i)];
      //std::cout << "i = " << i << "= " <<d[i] << std::endl;
      // std::cout << "logical d[i] = " << d[i] << std::endl;
    } // for

    // initialize boundary_left + real elements
    for(auto l: m.vertices<mesh::x_axis, mesh::boundary_low>()) { 
      d[l] = 0.0 ;
      v[l] = 0.0 ;
      mas[l] = 0.0 ;
      k[l] = 0.0 ; 
    } // for

    // initialize boundary_right + real elements
    for(auto h: m.vertices<mesh::x_axis, mesh::boundary_high>()) { 
      d[h] = 0.0 ;
      v[h] = 0.0 ;
      mas[h] = 0.0 ;
      k[h] = 0.0 ;
    } // for


  // clang format on
  
} // initialize condition