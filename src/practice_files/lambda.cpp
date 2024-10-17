#include <iostream>

void lambda() {
  /*
  []() { std::cout << "hello from lambda!" << std::endl; }();
  auto func = []() {
    std::cout << "hello from named func1 lambda!" << std::endl;
  };
  func();
  auto result = [](double a, double b) { return a + b; }(12.3, 12.4);
  std::cout << "result from lambda is: " << result << std::endl;

  auto func1 = [](double a, double b) { return a + b; };
  auto result1 = func1(22, 33);
  std::cout << "result1 from named func1 lambda is: " << result1 << std::endl;

  auto result2 = [](double a, double b) -> int { return a + b; }(12.3, 12.4);
  std::cout << "result2 from return type specific lambda is: " << result2
            << std::endl;
  */

  int a{22};
  int b{99};

  /* auto func2 = [a, b]() {
    std::cout << "a + b is : " << a + b << std::endl;
    std::cout << "&a and &b in func2 : " << &a << "   " << &b << std::endl;
  };
  func2(); */
  /* auto func3 = [&a, &b]() {
    std::cout << "a + b is : " << a + b << std::endl;
    std::cout << "&a and &b in func3 : " << &a << "   " << &b << std::endl;
  };
  func3();

  std::cout << "&a and &b in outside : " << &a << "   " << &b << std::endl;

  a += 10;
  func3(); */

  auto func4 = [=]() { std::cout << "[=] a + b is : " << a + b << std::endl; };
  func4();

  [&]() {
    std::cout << "[&] a + b is : " << a + b << std::endl;
    a += 10;
  }();
  std::cout << "a + b outside : " << a + b << std::endl;
}
