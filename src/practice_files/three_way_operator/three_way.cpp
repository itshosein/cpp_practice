#include "item.h"
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>

namespace ThreeWayOp {

void three_way_func() {

  int num1{10};
  int num2{90};

  auto compare{num1 <=> num2};

  fmt::print(fg(fmt::color::blue), "num1 > num2: {}\n", compare > 0);

  Item i1;
  Item i2{20, 10, -1, 10};
  Item i3;

  std::cout << i1;
  std::cout << i2;
  std::cout << i3;

  fmt::print(fg(fmt::color::blue), "i1 > i2: {}\n",
             i1 > i2); // ((i1 <=> i2 ) > 0)

  fmt::print(fg(fmt::color::blue), "i1 == i2: {}\n",
             i1 == i3); // ((i1 <=> i2 ) == 0)

  fmt::print(fg(fmt::color::blue), "80 > i2: {}\n",
             80 > i3); // ((80 <=> i2 ) > 0) -> ((i2 <=> 80) < 0)

  fmt::print(fg(fmt::color::blue), "80 != i2: {}\n",
             80 != i3); // ((80 <=> i2 ) != 0) -> !((i2 <=> 80) == 0)
}
} // namespace ThreeWayOp