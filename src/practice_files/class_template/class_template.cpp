#include "data_wrapper.hpp"
#include <iostream>

namespace ClassTemplates {

// explicit template instantiating with all methods only for debug purposes
template class DataWrapper<int>;

void class_templates() {
  DataWrapper p1(20);

  std::cout << fmt::format(fg(fmt::color::blue), "p1: ") << p1 << std::endl;

  DataWrapper<double> p2(14.124);

  std::cout << fmt::format(fg(fmt::color::blue), "p2: ") << p2 << std::endl;
}
} // namespace ClassTemplates
