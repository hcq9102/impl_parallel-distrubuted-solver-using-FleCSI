#include "solve.hh"
#include "state.hh"
#include "input.hh"
#include "tasks/compute.hh"
#include "specialization/types.hh"
#include "tasks/initialcondition.hh"
#include <flecsi/execution.hh>

#include <chrono>
#include <fstream>

using namespace flecsi;


constexpr size_t ndt = 64000; // number of time steps
constexpr double dt = 0.01; // time step

// Euler solver
void springmass::action::solve(control_policy &cp) {

  std::cout << "my solver" << std::endl;
  // solver_获取当前时间点
  auto solver_t0 = std::chrono::high_resolution_clock::now();
 
    for (int t = 0; t < ndt; ++t) {
      
      flecsi::execute<task::solver_d, default_accelerator>(cp.m, displacementsd(cp.m), velocitiesd(cp.m));
      flecsi::execute<task::solver_v, default_accelerator>(cp.m, displacementsd(cp.m), velocitiesd(cp.m), stiffnessesd(cp.m), massesd(cp.m));
    }

    //solver_ 获取当前时间点
  auto solver_t1 = std::chrono::high_resolution_clock::now();

  // solver_计算运行时间
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(solver_t1 - solver_t0);
  // solver_输出运行时间
  std::cout << "运行时间 in solver: " << duration.count() << " ms" << std::endl;
    // how to output at each time step seperately?
  //}
  
} // solve
