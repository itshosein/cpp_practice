#include "function_entities.hpp"
#include <fmt/color.h>
#include <fmt/core.h>

namespace FunctionEntities {
void function_entities() {
  /* add or &add or with = */
  double (*add_ptr1)(double, double){&add};
  double (*add_ptr2)(double, double){nullptr};
  add_ptr2 = &add;

  auto *add_ptr3{&add};

  fmt::print(fg(fmt::color::blue), "add_ptr1(10,1212.13): {}\n",
             add_ptr1(10, 1212.13));
  fmt::print(fg(fmt::color::blue), "add_ptr2(10,1212.13): {}\n",
             add_ptr2(10, 1212.13));
  fmt::print(fg(fmt::color::blue), "add_ptr3(10,1212.13): {}\n",
             add_ptr3(10, 1212.13));
}

double add(double a, double b) { return a + b; }
} // namespace FunctionEntities
