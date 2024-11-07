#include "exception.hpp"
#include "costume_exception.hpp"
#include <chrono>
#include <fmt/color.h>
#include <fmt/core.h>
#include <string>
#include <thread>

namespace ExceptionHandling {
void exception() {
  // the function will be called if program exit with uncaught exceptions
  std::set_terminate(&terminate_func);

  int a{63};
  int b{10};
  try {
    if (a == 0) {
      throw "wrong value for a";
    }

    try {
      if (a % b) {
        throw CostumeException("a / b has reminder!!");
      }
    } catch (...) {
      fmt::print(fg(fmt::color::red), "catch all block\n");
      throw; // rethrow the exception
    }

    fmt::print(fg(fmt::color::green), "End of try block!\n");
  } catch (const char *e) {
    fmt::print(fg(fmt::color::red), "Error: {}\n", e);
  } catch (const std::exception &e) {
    fmt::print(fg(fmt::color::red), "Error: {}\n", e.what());
  } catch (...) {
    fmt::print(fg(fmt::color::red), "outer catch all block!\n");
  }
  fmt::print(fg(fmt::color::green), "after try catch block!\n");
  throw 1;
}

void terminate_func() {
  for (size_t i{}; i < 5; i++) {
    fmt::print(fg(fmt::color::orange),
               "program will be killed in {} seconds!\n", 5 - i);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  std::abort();
}

} // namespace ExceptionHandling
