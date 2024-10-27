#include "person.h"
#include <cstdint>
#include <format>
#include <iostream>
/* member wise copy initialization
Person::Person(std::string name_param, unsigned int age_param) {
  this->set_age(age_param);
  this->set_name(name_param);
} */

namespace Oop {

Person::Person(std::string_view nid_param)
    : Person{nid_param, 0} /* initializer lists with constructor delegation */ {
}

Person::Person(std::string_view nid_param, unsigned int age_param,
               std::string_view name_param)
    : m_nid{nid_param}, m_name{name_param},
      m_age{age_param} /* initializer lists */ {}

Person::Person(const Person &p) : Person(p.m_nid, p.m_age, p.m_name) {}

Person::~Person() {
  std::cout << "person with name " << this->m_name << " has been deleted!"
            << std::endl;
}

Person *Person::set_name(std::string_view name_param) {
  this->m_name = name_param;
  return this;
}

Person *Person::set_age(unsigned int age_param) {
  this->m_age = age_param;
  return this;
}
Person *Person::set_nid(std::string_view nid_param) {
  this->m_nid = nid_param;
  return this;
}

std::string_view Person::get_nid() const { return this->m_nid; }

std::string_view Person::get_name() const { return this->m_name; }

unsigned int Person::get_age() const { return this->m_age; }

std::string Person::get_info() const {
  ++this->m_count_print_info;
  return std::format(
      "from non const func Person {} : nid: {} name: {}, age: {}. You "
      "have called the print function {} time\n",
      reinterpret_cast<std::uintptr_t>(this), this->get_nid(), this->get_name(),
      this->get_age(), this->m_count_print_info);
}

std::string Person::get_info() {
  ++this->m_count_print_info;
  return std::format("Person {} : nid: {} name: {}, age: {}. You "
                     "have called the print function {} time\n",
                     reinterpret_cast<std::uintptr_t>(this), this->get_nid(),
                     this->get_name(), this->get_age(),
                     this->m_count_print_info);
}
size_t Person::get_count_print_info() const { return m_count_print_info; }
} // namespace Oop
