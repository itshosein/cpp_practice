#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

namespace Oop {
class Person {
public:
  int test{};

protected:
  unsigned int m_age{};
  std::string_view m_name{};

private:
  std::string_view m_nid{};
  mutable size_t m_count_print_info{}; /*  not recommended to use! */

public:
  Person() = default;
  explicit Person(std::string_view nid_param);
  explicit Person(std::string_view nid_param, unsigned int age_param,
                  std::string_view name_param = "no_name");
  Person(const Person &p);
  ~Person();

  Person *set_name(std::string_view name_param);
  Person *set_age(unsigned int age_param);
  Person *set_nid(std::string_view nid_param);

  std::string_view get_name() const; // we can have overload with const
  unsigned int get_age() const;
  std::string_view get_nid() const;
  size_t get_count_print_info() const;

  std::string get_info() const;
  std::string get_info();
};

} // namespace Oop

#endif