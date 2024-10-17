#include <cstring>
#include <format>
#include <iostream>
#include <string_view>

void calc(int argc, char *argv[]) {

  if (argc != 4) {
    std::cerr << "Please enter valid options like:\nprogram 20 * 2\n";
    return;
  }

  const double number1{atof(argv[1])};
  const double number2{atof(argv[3])};
  const char *op{argv[2]};
  const std::string_view valid_ops{"+-x/"};

  if (number1 == 0.0 || number2 == 0.0) {
    std::cerr << "Please enter valid number except 0 like:\nprogram 20 * 2\n";
    return;
  } else if (std::strlen(op) != 1 ||
             valid_ops.find(op) == std::string_view::npos) {
    std::cerr << "Please enter valid operators like:\n";
    for (auto &valid_op : valid_ops) {
      std::cerr << std::format("{} ", valid_op);
    }
    std::cout << std::endl;
    return;
  }
  const char c_op{op[0]};
  std::string_view res{};
  if (c_op == '+') {
    res = std::format("{} + {} is: {}", number1, number2, number1 + number2);
  } else if (c_op == '-') {
    res = std::format("{} + {} is: {}", number1, number2, number1 - number2);
  } else if (c_op == 'x') {
    res = std::format("{} x {} is: {}", number1, number2, number1 * number2);
  } else if (c_op == '/') {
    res = std::format("{} / {} is: {}", number1, number2, number1 / number2);
  }

  std::cout << res << std::endl;

  // std::cout << std::format("number of args {}", argc) << std::endl;

  // for (int i{}; i < argc; i++) {
  //   std::cout << std::format("arg{} is {}", i, argv[i]) << std::endl;
  // }
}