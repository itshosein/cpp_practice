#include "data_wrapper.hpp"
#include <iostream>

namespace ClassTemplates {

// explicit template instantiating with all methods only for debug purposes
template class DataWrapper<int>;

void class_templates() {
  DataWrapper d1(20);

  std::cout << fmt::format(fg(fmt::color::blue), "d1: ") << d1 << std::endl;

  DataWrapper<double> d2(14.124);

  std::cout << fmt::format(fg(fmt::color::blue), "d2: ") << d2 << std::endl;

  char c_str[]{"Hello world!"};
  DataWrapper<char *> d3(c_str);

  std::cout << fmt::format(fg(fmt::color::blue), "d3: ") << d3 << std::endl;
}
} // namespace ClassTemplates
