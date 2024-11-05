#include "template.hpp"
#include <cstring>
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

template <typename T, typename U>
auto /* decltype(auto) is explicit decltype but nothing more gained */
minimum(T a, U b) {
  unsigned int test1{11313};
  long long int test2{1};
  return test1 < test2
             ? test1
             : test2; // implicit decltype! -> always returns biggest type
}

auto minimum(auto a, auto b) {
  return a < b ? a : b;
} // same as above declaration!!!!

void template_func() {
  double num1{20.0022};
  double num2{90.3237};
  int num3{23};
  int num4{1313};
  char num5{68};
  char num6{55};

  std::string str1{"str1"};
  std::string str2{"str2"};
  /*
    double *p_num1{&num1};
    double *p_num2{&num2};

    std::cout << std::format(
                     "{} + {} is: {}", num1, num2,
                     add<int>(num1, num2)) // explicit template argument can
    cause
                                           // implicit conversion
              << std::endl;
    std::cout << std::format("{} + {} is: {}", num1, num2,
                             maximum<const double &>(num3, num4))
              << std::endl;
     std::cout << "" << p_num1 << " VS " << p_num2
              << " is!!: " << maximum(p_num1, p_num2) << std::endl;


  const char *char1{"hello"};
  const char *char2{"test"};
  auto res = maximum<const char>(
      char1, char2); // we need return Type because compiler can't deduce
  std::cout << std::format("{} > {} ?: {}\n", char1, char2, res);


  auto res{minimum(num1, num3)};
  std::cout << std::format("which one is smaller? {} or {} ? => {}\n", num1,
                           num3, res);

  auto res1{add(1, 2)};
  std::cout << res1 << std::endl;


  std::cout << minimum(1, 23) << std::endl;

  std::cout << sizeof(decltype(num1 > num3 ? num1 : num3))
            << std::endl; // decltype always returns biggest type

  auto add_res{add(num3, num1)};

  std::cout << "add_res : " << add_res << std::endl;
  std::cout << "sizeof(add_res) : " << sizeof(add_res) << std::endl;


  auto res2{maximum(num3, num4)};
  std::cout << "res2 : " << res2 << std::endl;


  auto multiplier1 = [](auto a, auto b) { return a * b; };
  auto multiplier2 = []<typename T, typename U = int>(
      T a, T b) { // from c++ 20 we can have multiple typename in lambda
    return a * b;
  };
  auto res3{multiplier1(num1, num2)};
  auto res4{multiplier2(num3, num4)};
  std::cout << "res3: " << res3 << std::endl;
  std::cout << "sizeof(res3) : " << sizeof(res3) << std::endl;
  std::cout << "res4: " << res4 << std::endl;
  std::cout << "sizeof(res4) : " << sizeof(res4) << std::endl;
  */

  auto printer = []<typename T>(T first) {
    using DecayedType = std::decay<T>::type; // will simplify the type e.g const
                                             // char[] => const char*
    if constexpr (std::is_integral<T>::value) {
      integral_printer(first);
    } else if constexpr (std::is_floating_point<T>::value) {
      floating_printer(first);
    } else if constexpr (std::is_same<DecayedType, const char *>::value ||
                         std::is_same<DecayedType, char *>::value) {
      string_printer(first);
    } else {
      static_assert(false,
                    "You can not use printer lambda func with given type");
    }
  };
  printer("test");
}

template <typename R, typename T, typename U>
R maximum(const T &a, const U &b) {
  return a > b ? a : b;
}

template <typename R, typename T, typename U> R *maximum(T *a, U *b) {
  return *a > *b ? a : b;
}

// template <> const char *maximum<const char *>(const char *a, const char *b) {
//   return (std::strcmp(a, b) > 0) ? a : b;
// }

// high priority than templates
const char *maximum(const char *a, const char *b) {
  return (std::strcmp(a, b) > 0) ? a : b;
}

template <typename T, typename U>
auto add(const T &a, const U &b) -> decltype(a + b) {
  return a + b;
}

void floating_printer(double a) {
  std::cout << "floating point is: " << a << std::endl;
}
void integral_printer(int a) {
  std::cout << "floating point is: " << a << std::endl;
}
void string_printer(std::string_view a) {
  std::cout << "string_view is: " << a << std::endl;
}
