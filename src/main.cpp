#include "rvalue.hpp"
// #include "unix_time.hpp"
#include <fmt/color.h>
#include <fmt/core.h>

// #include <fstream>

int main(int argc, char *argv[]) {

  // fmt::print(fg(fmt::color::pink), "miliseconds: {}",
  //            UnixTime::get_unix_time());
  // FunctionMisfits::functions_misfit();
  // OpOverload::operator_overloading_func();
  // ThreeWayOp::three_way_func();

  Rvalue::rvalue_func();
  // try {
  //   std::ofstream file{"test.txt"};
  //   file << "Hello, World!\nso niiiiiiiiiiiiice";
  //   file.close();
  //   fmt::print(fg(fmt::color::green),
  //              "the file writing operation was successful");
  // } catch (const std::exception &e) {
  //   fmt::print(fg(fmt::color::red),
  //              "the file writing operation faced an errro: {}",
  //              e.what());
  // }

  return 1;
}