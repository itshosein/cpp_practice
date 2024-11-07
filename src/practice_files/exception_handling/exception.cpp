#include "costume_exception.hpp"
#include <fmt/color.h>
#include <fmt/core.h>
#include <string>

namespace ExceptionHandling {
void exception() {
  int a{63};
  int b{10};
  try {
    if (a == 0) {
      throw "wrong value for a";
    }

    if (a % b) {
      throw CostumeException("a / b has reminder!!");
    }

    fmt::print(fg(fmt::color::green), "End of try block!\n");
  } catch (const char *e) {
    fmt::print(fg(fmt::color::red), "Error: {}\n", e);
  } catch (const CostumeException &ce) {
    fmt::print(fg(fmt::color::red), "Error: {}\n", ce.what());
  }
  fmt::print(fg(fmt::color::green), "after try catch block!\n");
}
} // namespace ExceptionHandling
