#include "cat.h"
#include <fmt/color.h>
#include <fmt/core.h>

namespace CostumeClasses {
Cat::Cat(std::string_view name) : m_name{name} {
  fmt::print(fg(fmt::color::blue), "{} constructed!\n", m_name);
}

Cat::~Cat() {
  fmt::print(fg(fmt::color::orange), "{} deconstructed!\n", m_name);
}
void Cat::print_info() {
  fmt::print(fg(fmt::color::cyan), "Cat obj has name {} and stored in {}!\n",
             m_name, reinterpret_cast<uintptr_t>(this));
}

Cat *CostumeClasses::Cat::set_name(std::string_view name) {
  this->m_name = name;
  return this;
}
} // namespace CostumeClasses
