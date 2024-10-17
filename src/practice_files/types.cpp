#include <iostream>
#include <limits>

const constinit int testInit{255};

void types() {
  int number1{3};
  int number2(1.5);
  int number3 = 4.5;
  std::cout << "number1: " << number1 << std::endl;
  std::cout << "number2: " << number2 << std::endl;
  std::cout << "number3: " << number3 << std::endl;
  std::cout << "sizeof(int): " << sizeof(int) << std::endl;

  int ten1{10};
  int ten2{012};
  int ten3{0xA};
  int ten4{0b1010};
  std::cout << "ten1: " << ten1 << std::endl;
  std::cout << "ten2: " << ten2 << std::endl;
  std::cout << "ten3: " << ten3 << std::endl;
  std::cout << "ten4: " << ten4 << std::endl;

  auto marziyeh{'m'};
  // std::cout << "marziyeh is:" << static_cast<int>(marziyeh) << std::endl;
  std::cout << "marziyeh is:" << marziyeh << std::endl;
  // marziyeh = -200;
  std::cout << "marziyeh is:" << marziyeh << std::endl;

  auto unInt{333u};
  std::cout << "unInt is:" << unInt << std::endl;
  unInt = -1545;
  std::cout << "unInt is:" << unInt << std::endl;

  std::cout << "unInt is:" << sizeof(unInt) << " bytes" << std::endl;

  short int variable1{10000};
  short int variable2{32000};
  char chr1{70};
  auto res{variable1 + variable2};
  std::cout << sizeof(variable1) << std::endl;
  std::cout << sizeof(chr1) << std::endl;
  std::cout << std::numeric_limits<short int>::max() << std::endl;
  std::cout << sizeof(res) << " " << res << std::endl;

  const int age{27};
  constexpr int VERSION{age};
  std::cout << "VERSION is " << VERSION << std::endl;
  static_assert(VERSION == age);

  std::cout << "testInit is " << testInit << std::endl;
  static_assert(testInit == 255);
  // for sake of const and not constinit. => const init
  // means just have to initialize it.
}