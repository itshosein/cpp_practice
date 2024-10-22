#include "operator_overloading.h"
#include "point-ov.h"
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>
#include <memory>

namespace OpOverload {

void operator_overloading_func() {
  auto p_point1{std::make_unique<Point>(12.231, 44.23)};
  (*p_point1)[0] = 13;
  (*p_point1)[1] = 15.99;
  auto p_point2{std::make_unique<Point>(33.11, 99.11)};
  auto p_point3{std::make_unique<Point>(*p_point1 + *p_point2)};
  auto p_point4{std::make_unique<Point>(*p_point1 - *p_point2)};
  auto p_point5{std::make_unique<Point>(*p_point1 * *p_point2)};

  fmt::println("p1[0]: {}", (*p_point1)[0]);
  fmt::println("p1[1]: {}", (*p_point1)[1]);
  fmt::println("(*p_point1).operator[](0): {}", (*p_point1).operator[](0));
  fmt::print("(*p_point1).operator+(*p_point2): ");
  (*p_point1).operator+(*p_point2).print_info();

  std::cin >> (*p_point5);
  std::cout << "you entered: " << (*p_point5);

  fmt::println("\n\n***************************\n");

  check_even(static_cast<std::vector<double>>(*p_point5));
  (*p_point5)++;
  ++(*p_point5);
  (*p_point5)--;
  --(*p_point5);
  std::cout << (*p_point5);

  *p_point4 = *p_point3; // copy assignment!
}

void check_even(const std::vector<double> &v) {

  for (size_t i{}; i < v.size(); i++) {
    bool is_even{static_cast<int>(v[i]) % 2 == 0};
    fmt::print(fg(fmt::color::blue), "{} is{} even\n", v[i],
               is_even ? "" : " not");
  }

  //
}
} // namespace OpOverload
