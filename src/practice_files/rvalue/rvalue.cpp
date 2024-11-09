#include "rvalue.hpp"
#include <fmt/color.h>
#include <fmt/core.h>

namespace Rvalue {
void rvalue_func() {
  double a{3414};

  int b{230};

  int c{255};

  /*
    res is a rvalue reference because a+b produces a temporary memory location
    so we use it
   */
  double &&res{a / b};

  int &&result_of_add_func{add(a, b)};

  fmt::print(fg(fmt::color::blue), "res: {:.3f}\n", res);
  fmt::print(fg(fmt::color::blue), "result_of_add_func: {}\n",
             result_of_add_func);

  int &&moved_c{std::move(c)};

  c = 1;

  fmt::print(fg(fmt::color::blue), "c: {}\n", c);
  fmt::print(fg(fmt::color::blue), "moved_c: {}\n", moved_c);
}

int add(const int &a, const int &b) { return a + b; }
} // namespace Rvalue
