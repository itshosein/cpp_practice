#include "namespace.h"
#include <fmt/color.h>
#include <fmt/core.h>

inline int age{
    28}; // because of order of cpp files in folders 27 saved in memory first!

namespace InlineVsNamespace2 {
namespace {
int age{9};
} // namespace

void inline_printer() {
  fmt::print(fg(fmt::color::blue), "inline_printer2: age is: {}\n", ::age);
  fmt::print(fg(fmt::color::cyan), "inline_printer2: &age is: {}\n",
             reinterpret_cast<uintptr_t>(&::age));
}
void namespace_printer() {
  fmt::print(fg(fmt::color::blue), "namespace_printer2: age is: {}\n", age);
  fmt::print(fg(fmt::color::cyan), "namespace_printer2: &age is: {}\n",
             reinterpret_cast<uintptr_t>(&age));
}
} // namespace InlineVsNamespace2

namespace NamespaceFile {

void namespace_func() {

  namespace FmtName = fmt;
  double num1{515.123};
  double num2{939.12394};

  auto res1{NamespaceFile::add(num1, num2)};
  auto res2{::add(num1, num2)};

  FmtName::print(fg(FmtName::color::blue), "res1 is: {}\n", res1);
  FmtName::print(fg(FmtName::color::blue), "res2 is: {}\n", res2);

  test();
}

double add(const double &x, const double &y) {
  fmt::print(fg(fmt::color::orange), "In NamespaceFile add function\n");
  return x + y;
}

} // namespace NamespaceFile

double add(const double &x, const double &y) {
  fmt::print(fg(fmt::color::orange), "In global add function\n");
  return x + y;
}

namespace {
void test() { fmt::print(fg(fmt::color::orange), "In anonymous function\n"); }
} // namespace