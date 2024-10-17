#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

class Person {
  std::string_view m_nid{};
  std::string_view m_name{};
  unsigned int m_age{};
  mutable size_t m_count_print_info{}; /*  not recommended to use! */

public:
  Person() = default;
  explicit Person(std::string_view nid_param);
  explicit Person(std::string_view nid_param, unsigned int age_param,
                  std::string_view name_param = "no_name");
  ~Person();

  Person *set_name(std::string_view name_param);
  Person *set_age(unsigned int age_param);
  Person *set_nid(std::string_view nid_param);

  std::string_view get_name() const; // we can have overload with const
  unsigned int get_age() const;
  std::string_view get_nid() const;

  std::string get_info() const;
  std::string get_info();
};

#endif