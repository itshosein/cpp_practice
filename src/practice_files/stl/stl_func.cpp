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


  std::vector<int> vec1{1, 2, 3, 4};
  // (amount of variable, default value)
  std::vector<int> vec2(10, 10000);

  fmt::print(fg(fmt::color::green), "vec1: ");
  for (auto &&el : vec1) {
    fmt::print(fg(fmt::color::green), "{} ", el);
  }

  fmt::print(fg(fmt::color::green), "\nvec2: ");
  print_raw_array(vec2.data(), vec2.size());



  std::array<int, 5> arr1{1, 2, 3, 4};
  std::array arr2{23.4, 21.45, 1245.22};

  fmt::print(fg(fmt::color::green), "arr1: ");
  print_raw_array(arr1.data(), arr1.size());

  fmt::print(fg(fmt::color::green), "\narr2: ");
  print_array(arr2);
  */

  std::stack<int> stack1;
  stack1.push(1);
  stack1.push(13030);
  std::stack<double> stack2;
  stack2.push(13.131);
  stack2.push(983.1233);

  fmt::print(fg(fmt::color::green), "stack1: ");
  print_stack(stack1);

  fmt::print(fg(fmt::color::green), "stack2: ");
  print_stack(stack2);
}

template <typename T> void print_raw_array(const T *p, size_t size) {
  for (size_t i{}; i < size; i++) {
    fmt::print(fg(fmt::color::green), "{} ", p[i]);
  }
}

template <typename T, size_t Size>
void print_array(const std::array<T, Size> &arr) {
  for (auto &i : arr) {
    fmt::print(fg(fmt::color::green), "{} ", i);
  }
}

template <typename T> void print_stack(std::stack<T> stack) {
  while (!stack.empty()) {
    fmt::print(fg(fmt::color::green), "{} ", stack.top());
    stack.pop();
  }
}
} // namespace StlExercise
