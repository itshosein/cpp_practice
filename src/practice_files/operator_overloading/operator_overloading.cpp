#include "point-ov.h"
#include <fmt/core.h>
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
}
} // namespace OpOverload
