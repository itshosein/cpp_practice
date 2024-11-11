#include "function_entities.hpp"
#include <fmt/color.h>
#include <fmt/core.h>

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
  fmt::print(fg(fmt::color::blue), "msg is best or msg2: {}\n",
             get_best(str_v, large_in_size));
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

} // namespace FunctionEntities
