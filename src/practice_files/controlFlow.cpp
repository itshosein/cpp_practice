#include <iostream>

void controlFlow() {
  const int a{16};
  const int b{10};

  constexpr bool condition{a >= b};

  if constexpr (condition) {
    std::cout << "if constexpr is true!" << std::endl;
  } else {
    std::cout << "if constexpr is false!" << std::endl;
  }

  if (int test{22}; a > b) {
    std::cout << "If with initializer and test value is => " << test
              << std::endl;
  }

  if constexpr (int test{22}; a > b) {
    std::cout << "If constexpr with initializer and test value is => " << test
              << std::endl;
  }

  switch (int test{8}; a) {
    // int x {11}; never will run
  case 15:
    // int x; dont do. will have garbage value in other part of switch
    std::cout << "switch with initializer and test value is => " << test
              << std::endl;
    break;

  default:
    std::cout << "switch with initializer (a not found) and test value is => "
              << test << std::endl;
    break;
  }
}