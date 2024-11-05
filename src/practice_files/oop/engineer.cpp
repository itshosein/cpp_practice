#include "engineer.h"
#include <string_view>

namespace Oop {

Engineer::Engineer(std::string_view nid_param, unsigned int age_param,
                   std::string_view name_param, std::string_view field)
    : Person(nid_param, age_param, name_param), m_field{field} {}

Engineer::Engineer(const Engineer &e) : Person(e), m_field{e.m_field} {}

Engineer::~Engineer() {}

std::string_view Engineer::get_field() const { return this->m_field; }

Engineer *Engineer::set_field(std::string_view field) {
  this->m_field = field;
  return this;
}

void Engineer::work() const {
  fmt::print(fg(fmt::color::blue),
             "Engineer::work: Engineer with name {} is working\n",
             this->get_name());
}

void Engineer::work(double end_hour) const {
  fmt::print(fg(fmt::color::blue),
             "Engineer::work: Engineer with name {} is working until {}\n",
             this->get_name(), end_hour);
}
void Engineer::work(std::string_view work_param) const {
  fmt::print(fg(fmt::color::blue),
             "Engineer::work: Engineer with name {} is working with param {}\n",
             this->get_name(), work_param);
}

} // namespace Oop
