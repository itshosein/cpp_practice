#include "enum.hpp"
#include <iostream>
#include <string_view>

void enum_func() {
  Month month{Month::Jan};

  // std::cout << "month: " << month << std::endl;
  std::cout << "static_cast<int>(month): " << static_cast<int>(month)
            << std::endl;
  std::cout << "sizeof(month): " << sizeof(month) << std::endl;

  std::cout << "month_to_str(month): " << month_to_str(month) << std::endl;

  using HugeInt = unsigned long long int;
  // typedef unsigned long long int HugeInt; // Old way
  HugeInt number{1212131313};
  std::cout << "number: " << number << std::endl;
  std::cout << "sizeof(unsigned long long int): "
            << sizeof(unsigned long long int) << std::endl;
  std::cout << "sizeof(number): " << sizeof(number) << std::endl;
}

std::string_view month_to_str(Month m) {
  switch (m) {
    using enum Month; // shortened the Month::Jan //c++ 20
  case Jan:
    return "January";
  case Mar:
    return "January";
  case Apr:
    return "January";
  case May:
    return "January";
  case Oct:
    return "January";
  case Sep:
    return "January";
  default:
    return "Not yet implemented!";
  }
}