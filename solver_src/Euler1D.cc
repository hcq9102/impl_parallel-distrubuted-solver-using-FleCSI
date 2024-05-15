#include "flecsi/flog.hh"
#include "readfile.hh"
#include "specialization/control.hh"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace flecsi;

int main(int argc, char **argv) {
  // Initialize the FleCSI run-time system.
  auto status = flecsi::initialize(argc, argv);
  status = springmass::control::check_status(status);
  if (status != flecsi::run::status::success) {
    return status < flecsi::run::status::clean ? 0 : status;
  }
  flecsi::flog::add_output_stream("clog", std::clog, true);

  // Execute our code control point by control point.
  // 获取当前时间点
  auto t0 = std::chrono::high_resolution_clock::now();
  status = flecsi::start(springmass::control::execute);
  // 获取当前时间点
  auto t1 = std::chrono::high_resolution_clock::now();

  // 计算运行时间
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
  // 输出运行时间
  std::cout << "total运行时间 in main: " << duration.count() << " ms" << std::endl;


  // Finalize the FleCSI run-time system.
  flecsi::finalize();
  return status;
}