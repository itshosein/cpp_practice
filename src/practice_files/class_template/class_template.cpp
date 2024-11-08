#include "person.hpp"
#include <iostream>

namespace ClassTemplates {
void class_templates() {
  DataWrapper<int> p(20);

  std::cout << fmt::format(fg(fmt::color::blue), "p: ") << p << std::endl;
}
} // namespace ClassTemplates
