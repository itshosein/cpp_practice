#include <fmt/color.h>
#include <fmt/core.h>

inline int age{27};

namespace InlineVsNamespace1 {
namespace {
int age{8};
} // namespace

void inline_printer() {
  fmt::print(fg(fmt::color::blue), "inline_printer1: age is: {}\n", ::age);
  fmt::print(fg(fmt::color::cyan), "inline_printer1: &age is: {}\n",
             reinterpret_cast<uintptr_t>(&::age));
}
void namespace_printer() {
  fmt::print(fg(fmt::color::blue), "namespace_printer1: age is: {}\n", age);
  fmt::print(fg(fmt::color::cyan), "namespace_printer1: &age is: {}\n",
             reinterpret_cast<uintptr_t>(&age));
}
} // namespace InlineVsNamespace1
