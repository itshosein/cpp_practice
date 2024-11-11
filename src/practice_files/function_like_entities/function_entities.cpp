#include "function_entities.hpp"
#include <fmt/color.h>
#include <fmt/core.h>
#include <functional>

namespace FunctionEntities {
void function_entities() {
  /* add or &add or with = */
  /* double (*add_ptr1)(double, double){&add};
  double (*add_ptr2)(double, double){nullptr};
  add_ptr2 = &add;

  auto *add_ptr3{&add};

  fmt::print(fg(fmt::color::blue), "add_ptr1(10,1212.13): {}\n",
             add_ptr1(10, 1212.13));
  fmt::print(fg(fmt::color::blue), "add_ptr2(10,1212.13): {}\n",
             add_ptr2(10, 1212.13));
  fmt::print(fg(fmt::color::blue), "add_ptr3(10,1212.13): {}\n",
             add_ptr3(10, 1212.13)); */

  std::string msg{"I am c++ developer!"};
  std::string msg1{"I am a better c++ developer!"};

  modify(msg, encrypt);
  fmt::print(fg(fmt::color::blue), "msg encrypted: {}\n", msg);
  modify(msg, decrypt);
  fmt::print(fg(fmt::color::blue), "msg decrypted: {}\n", msg);

  std::vector<std::string> str_v{};
  str_v.push_back(msg);
  str_v.push_back(msg1);
  str_v.emplace_back("WOw that is awesome");
  std::string &&best_str{get_best(str_v, large_in_size)};
  fmt::print(fg(fmt::color::blue), "msg is best or msg2: {}\n",
             std::move(best_str));
  fmt::print(fg(fmt::color::chocolate), "---------------\n");

  std::plus<int> char_adder;

  fmt::print(fg(fmt::color::blue), "1 + 2: {}\n",
             static_cast<int>(char_adder(1, 2)));

  std::vector<int> int_v{11, 4, 6, 40, 50};

  int &&v_sum{sumInRange<int>(int_v, IsInRange<int>(0, 10))};
  fmt::print(fg(fmt::color::blue), "sum of int_v: {}\n", v_sum);
}

double add(double a, double b) { return a + b; }

char encrypt(const char &input) { return static_cast<char>(input + 3); }
char decrypt(const char &input) { return static_cast<char>(input - 3); }

std::string &modify(std::string &input, fn_t fn) {
  for (size_t i{}; i < input.size(); i++) {
    input[i] = fn(input[i]);
  }
  return input;
}

bool large_in_size(const std::string &a, const std::string &b) {
  return a.size() > b.size();
}

std::string get_best(std::vector<std::string> str_v, comparator_t comparator) {
  std::string best{};
  for (size_t i{}; i < str_v.size(); i++) {
    for (auto &j : str_v) {
      if (comparator(str_v[i], j)) {
        best = str_v[i];
      }
    }
  }
  return best;
}

template <typename T>
  requires std::is_arithmetic_v<T>
T sumInRange(std::vector<T> &v, IsInRange<T> is_in_range) {
  T res{0};
  for (auto &el : v) {
    if (is_in_range(el)) {
      res += el;
    }
  }
  return res;
}

} // namespace FunctionEntities
