#include <fmt/color.h>
#include <fmt/core.h>

namespace ThreeWayOp {

void three_way_func() {

  int num1{10};
  int num2{90};

  auto compare{num1 <=> num2};

  fmt::print(fg(fmt::color::blue), "num1 > num2: {}\n", compare > 0);
}
} // namespace ThreeWayOp