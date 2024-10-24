#include "engineer.h"
#include <string_view>

namespace Oop {

Engineer::Engineer(std::string_view name, unsigned int age,
                   std::string_view field)
    : m_field(field) {
  m_age = age;
  m_name = name;
}

Engineer::~Engineer() {}

std::string_view Engineer::get_field() const { return this->m_field; }

Engineer *Engineer::set_field(std::string_view field) {
  this->m_field = field;
  return this;
}

} // namespace Oop
