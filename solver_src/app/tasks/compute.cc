#include "tasks/compute.hh"
#include "readfile.hh"
#include "tasks/initialcondition.hh"
#include "specialization/mesh1D.hh"
#include <fstream>
#include <iomanip>
#include <flecsi/execution.hh>

using namespace flecsi;

constexpr double dt = 0.01; // time step
double output_dt = 0.0; 

// Euler solver
namespace springmass::task {

void 
solver_d(mesh::accessor<ro> m,
                              field<double>::accessor<rw, ro> da,
                              field<double>::accessor<rw, ro> va
                              ) {
  auto d = m.mdspan<mesh::vertices>(da);
  auto v = m.mdspan<mesh::vertices>(va);
  // auto mas = m.mdspan<mesh::vertices>(ma);
  // auto k = m.mdspan<mesh::vertices>(ka);

    // update d use old_d and old_v  
    forall( i , (m.vertices<mesh::x_axis, mesh::logical>()),"integrate_d") {
       
        d[i] = d[i] + dt * v[i]; // right side:d[i] is old, v[i] is new
    };
}

void 
solver_v(mesh::accessor<ro> m,
                              field<double>::accessor<rw, ro> da,
                              field<double>::accessor<rw, ro> va,
                              field<double>::accessor<ro, ro> ka,
                              field<double>::accessor<ro, ro> ma) {
  auto d = m.mdspan<mesh::vertices>(da);
  auto v = m.mdspan<mesh::vertices>(va);
  auto mas = m.mdspan<mesh::vertices>(ma);
  auto k = m.mdspan<mesh::vertices>(ka);

    /// update v use new displacement. Since acc[i] depends on
    // d[i-1], d[i] and d[i+1], a ghost copy is needed before launching the kernel
    // (done by FleCSI before the invocation of this function).
    forall( i , (m.vertices<mesh::x_axis, mesh::logical>()),"integrate_v") {  
       //std::cout << "i_ = " << i << std::endl;
        v[i] = v[i] + dt * ((-k[i] * (d[i] - d[i-1]) + k[i+1] * (d[i+1] - d[i])) /mas[i]); 

    };
  }

}


    
    
    
     
    //}
    // close file;
    //outputFile.close();
  //} // solver


  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
  optimize1:
  
  // update value for each mass at each time step.
  //std::ofstream outputFile("springmass_2rank_size=50.csv", std::ios::app); 
  
  //if (!outputFile.is_open()) {
    // update v use old d all the time
    for (auto i : m.vertices<mesh::x_axis, mesh::logical>()) {  
       //std::cout << "i_ = " << i << std::endl;
        v[i] = v[i] + dt * ((-k[i] * (d[i] - d[i-1]) + k[i+1] * (d[i+1] - d[i])) /mas[i]); 

    }
    
    //outputFile << std::fixed << std::setprecision(2) << output_dt << "," << std::setprecision(6) << d[8] << "\n";

    // update d use old_d and new v  
    for (auto i : m.vertices<mesh::x_axis, mesh::logical>()) {  
       
        d[i] = d[i] + dt * v[i]; // right side:d[i] is old, v[i] is new
         //  under 1 rank, output rightmost mass 
        // outputFile << std::fixed << std::setprecision(2) << output_dt << "," << std::setprecision(6) << d[8] << "\n";
        // output_dt += dt;
    }
      
      //output_dt += dt; 
     
    //}
    // close file;
    //outputFile.close();
  */
 

// origin

/*
#include "tasks/compute.hh"
#include "readfile.hh"
#include "tasks/initialcondition.hh"
#include "specialization/mesh1D.hh"
#include <fstream>
#include <iomanip>
#include <flecsi/execution.hh>

using namespace flecsi;

constexpr double dt = 0.01; // time step
double output_dt = 0.0; 

// Euler solver
void springmass::task::solver_d(mesh::accessor<ro> m,
                              field<double>::accessor<rw, ro> da,
                              field<double>::accessor<rw, ro> va,
                              field<double>::accessor<ro, ro> ka,
                              field<double>::accessor<ro, ro> ma) {
  auto d = m.mdspan<mesh::vertices>(da);
  auto v = m.mdspan<mesh::vertices>(va);
  auto mas = m.mdspan<mesh::vertices>(ma);
  auto k = m.mdspan<mesh::vertices>(ka);

  // update value for each mass at each time step.
  //std::ofstream outputFile("springmass_2rank_size=50.csv", std::ios::app); 
  
  //if (!outputFile.is_open()) {
    
    //outputFile << std::fixed << std::setprecision(2) << output_dt << "," << std::setprecision(6) << d[8] << "\n";

    // update d use old_d and old_v  
    forall( i , (m.vertices<mesh::x_axis, mesh::logical>()),"integrate_d") {
       
        d[i] = d[i] + dt * v[i]; // right side:d[i] is old, v[i] is new
         //  under 1 rank, output rightmost mass 
        // outputFile << std::fixed << std::setprecision(2) << output_dt << "," << std::setprecision(6) << d[8] << "\n";
        // output_dt += dt;
    };
      
    //output_dt += dt; 

    // update v use new displacement. Since acc[i] depends on
    // d[i-1], d[i] and d[i+1], a ghost copy is needed before launching the kernel
    // (done by FleCSI before the invocation of this function).
    forall(i , (m.vertices<mesh::x_axis, mesh::logical>()), "integrate_v") {  
       //std::cout << "i_ = " << i << std::endl;
        v[i] = v[i] + dt * ((-k[i] * (d[i] - d[i-1]) + k[i+1] * (d[i+1] - d[i])) /mas[i]); 

    };
    
    
     
    //}
    // close file;
    //outputFile.close();
  } // solver


  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
  optimize1:
  
  // update value for each mass at each time step.
  //std::ofstream outputFile("springmass_2rank_size=50.csv", std::ios::app); 
  
  //if (!outputFile.is_open()) {
    // update v use old d all the time
    for (auto i : m.vertices<mesh::x_axis, mesh::logical>()) {  
       //std::cout << "i_ = " << i << std::endl;
        v[i] = v[i] + dt * ((-k[i] * (d[i] - d[i-1]) + k[i+1] * (d[i+1] - d[i])) /mas[i]); 

    }
    
    //outputFile << std::fixed << std::setprecision(2) << output_dt << "," << std::setprecision(6) << d[8] << "\n";

    // update d use old_d and new v  
    for (auto i : m.vertices<mesh::x_axis, mesh::logical>()) {  
       
        d[i] = d[i] + dt * v[i]; // right side:d[i] is old, v[i] is new
         //  under 1 rank, output rightmost mass 
        // outputFile << std::fixed << std::setprecision(2) << output_dt << "," << std::setprecision(6) << d[8] << "\n";
        // output_dt += dt;
    }
      
      //output_dt += dt; 
     
    //}
    // close file;
    //outputFile.close();
  */


