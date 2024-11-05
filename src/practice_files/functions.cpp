#include "functions.hpp"
#include <array>
#include <cstring>
#include <iostream>
#include <string>
#include <string_view>

void functions() {

  double arr[]{12.44, 134.45, 123.45, 3, 4};
  double sum_out{};

  sum_of_arr(arr, sum_out);

  std::cout << "sum_out is: " << sum_out << std::endl;

  // std::cout << "sum is: " << res << std::endl;
  // std::cout << "arr[0] is: " << arr[0] << std::endl;

  // increment(res); // compiler error

  int value{90};
  increment(value);
  std::string name{"hossein"};
  say_hello(name); // ok
  // say_hello("Hossein");// compile error if non const reference
  say_hello("Hossein");

  constexpr int value1{20};
  constexpr int value2{30};
  constexpr int result1{multiply(2, 3)};
  constexpr int result2{multiply(value1, value2)};

  std::cout << "result1 is: " << result1 << std::endl;
  std::cout << "result2 is: " << result2 << std::endl;

  constexpr int result3{multiply_to_two(20)};
  // constexpr int result4{multiply_to_two(value)};  // compile error

  std::cout << "result3 is: " << result3 << std::endl;

  int a{22};
  int b{10};

  int *res_max_ref = max_ref(&a, &b);
  // int max_value = max_ref(a, b); only for reference return functions

  std::cout << "*res_max_ref is: " << *res_max_ref << std::endl;
  // std::cout << "max_value is: " << max_value << std::endl;

  res_max_ref += 10;

  double array[]{1, 2, 3, 4, 5, 44, 124, 535, 1, 42124};

  const double *max_value = find_max(array, std::size(array));

  std::cout << "max_value is: " << *max_value << std::endl;
}

// double sum_of_arr(
//     double /* arr[13123123 junk value] */ *arr /* like *arr in functions */,
//     size_t size_of_array) {
//   // std::cout << std::size(arr) << std::endl; // compile error
//   double sum{};

//   for (size_t i = 0; i < size_of_array; i++) {
//     sum += arr[i];
//     // sum += *(arr + i);
//   }

//   return sum;
// }

void sum_of_arr(const double (&arr)[5], double &sum_output,
                double initial_value) {
  sum_output = initial_value;
  for (size_t i = 0; i < std::size(arr); ++i) {
    sum_output += arr[i];
  }

  // arr[0] = 25;

  // return sum;
}

void increment(int &value) {
  ++value;

  std::cout << "value: " << value << std::endl;
}

void say_hello(std::string_view name) {
  std::cout << "your name is: " << name << std::endl;
}

// constexpr int multiply(int value1, int value2) { return value1 * value2; }
// only one spot for definition and that is .hpp file

// Return by reference
int &max_ref(int &num1, int &num2) {
  if (num1 > num2) {
    return num1;
  } else {
    return num2;
  }
}
// int &max_ref(int num1, int num2) { // bad behavior CRASH
//   if (num1 > num2) {
//     return num1;
//   } else {
//     return num2;
//   }
// }
// int &max_ref(int &num1, int &num2) { // bad behavior CRASH
//   int result{};
//   if (num1 > num2) {
//     result = num2;
//     return result;
//   } else {
//     result = num1;
//     return result;
//   }
// }

// Return by pointer
int *max_ref(int *num1, int *num2) {
  if (*num1 > *num2) {
    return num1;
  } else {
    return num2;
  }
}
// int *max_ref(int num1, int num2) { // bad behavior CRASH
//   if (num1 > num2) {
//     return &num1;
//   } else {
//     return &num2;
//   }
// }
// int *max_ref(int *num1, int *num2) { // bad behavior CRASH
//   int result{};
//   if (*num1 > *num2) {
//     result = *num2;
//     return &result;
//   } else {
//     result = *num1;
//     return &result;
//   }
// }

const double *find_max(const double array[], size_t size) {
  size_t max_index{};
  double max{};
  for (size_t i{}; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
      max_index = i;
    }
  }
  return &array[max_index];
}