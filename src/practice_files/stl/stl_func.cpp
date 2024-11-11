#include "stl_func.hpp"
#include <fmt/color.h>
#include <fmt/core.h>

namespace StlExercise {
void stl_func() {
  /*
  stl contains three parts:
  1) containers
  2) algorithms
  3) iterators
  */

  std::vector<int> vec1{1, 2, 3, 4};
  // (amount of variable, default value)
  std::vector<int> vec2(10, 10000);

  fmt::print(fg(fmt::color::green), "vec1: ");
  for (auto &&el : vec1) {
    fmt::print(fg(fmt::color::green), "{} ", el);
  }

  fmt::print(fg(fmt::color::green), "\nvec2: ");
  print_raw_array(vec2.data(), vec2.size());
}

template <typename T> void print_raw_array(const T *p, size_t size) {
  for (size_t i{}; i < size; i++) {
    fmt::print(fg(fmt::color::green), "{} ", p[i]);
  }
}
} // namespace StlExercise
