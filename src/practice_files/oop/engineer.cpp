#include "engineer.hpp"
#include <string_view>

namespace Oop {

size_t Engineer::m_count{};

Engineer::Engineer(std::string_view nid_param, unsigned int age_param,
                   std::string_view name_param, std::string_view field)
    : Person(nid_param, age_param, name_param), m_field{field} {
  m_count++;
}

Engineer::Engineer(const Engineer &e) : Person(e), m_field{e.m_field} {
  m_count++;
}

Engineer::~Engineer() {
  std::cout << "engineer with name " << this->m_name << " has been deleted!"
            << std::endl;
}

std::string_view Engineer::get_field() const { return this->m_field; }

Engineer *Engineer::set_field(std::string_view field) {
  this->m_field = field;
  return this;
}

// void Engineer::work() const {
//   // this->Person::work();
//   fmt::print(fg(fmt::color::blue),
//              "Engineer::work: Engineer with name {} is working\n",
//              this->get_name());
// }

void Engineer::work(int start_hour) const {
  fmt::print(fg(fmt::color::blue),
             "Engineer::work: Engineer with name {} is working start_hour {}\n",
             this->get_name(), start_hour);
}

void Engineer::work(double end_hour) const {
  fmt::print(fg(fmt::color::blue),
             "Engineer::work: Engineer with name {} is working end_hour {}\n",
             this->get_name(), end_hour);
}
void Engineer::work(std::string_view work_param) const {
  fmt::print(fg(fmt::color::blue),
             "Engineer::work: Engineer with name {} is working work_param {}\n",
             this->get_name(), work_param);
}

} // namespace Oop
