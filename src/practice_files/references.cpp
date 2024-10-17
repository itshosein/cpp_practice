#include <iostream>

void references() {
  int number1{1212};

  int &r_number1{number1};

  std::cout << "number1: " << number1 << std::endl;
  std::cout << "&number1: " << &number1 << std::endl;
  std::cout << "r_number1: " << r_number1 << std::endl;
  std::cout << "&r_number1: " << &r_number1 << std::endl;

  int arr[]{1, 2, 3, 4, 5, 6};

  for (auto &num : arr) {
    num = num % 2;
  }

  for (auto &num : arr) {
    std::cout << "num: " << num << std::endl;
  }
}