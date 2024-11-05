#include "functions_misfit.hpp"
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>

void FunctionMisfits::functions_misfit() {
  int result(sum(2, 3));
  // sum(2, 3);
  // sum(2, 3);
  // sum(2, 3);
  // sum(2, 3);
  // sum(2, 3);

  // auto printer = FunctionMisfits::wrapper(sum_double);
  // printer("Hossein!");
  auto printer = FunctionMisfits::function_wrapper(sum_double);
  printer("hossein");
}

int FunctionMisfits::sum(int a, int b) {
  static unsigned int number_of_calls{};

  number_of_calls++;
  std::cout << number_of_calls << std::endl;
  return a + b;
}

double FunctionMisfits::sum_double(const double &num1, const double &num2) {
  return num1 + num2;
}

void (*FunctionMisfits::wrapper(double (*sum)(
    const double &num1, const double &num2)))(const std::string &name) {
  double num1{12.3};
  double num2{313.22};
  double res{sum(num1, num2)};
  fmt::print(fg(fmt::color::blue), "in wrapper: res:\n", res);

  auto printer =
      [](const std::string &name) { // can't pass capture list because of
                                    // returning as function poiner
        fmt::print(fg(fmt::color::blue), "in printer: hi {}\n", name);
      };

  return printer;
}

std::function<void(const std::string &)> FunctionMisfits::function_wrapper(
    std::function<double(const double &num1, const double &num2)> sum) {
  double num1{12.3};
  double num2{313.22};
  double res{sum(num1, num2)};
  auto printer =
      [res](const std::string &name) { // all ok thanks to std::function!
        fmt::print(fg(fmt::color::blue), "in printer: hi {}\tres is: {:.3f}\n",
                   name, res);
      };

  return printer;
}