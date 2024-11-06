#ifndef ENGINEER_HPP
#define ENGINEER_HPP

#include "person.hpp"
#include <cstdlib>
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>
#include <string_view>

namespace Oop {
// base class access modifier:
//  public ->  everything as base class
//  protected -> public members become protected in derived class
//  private -> all public and protected members become private to derived class
class Engineer
    : public Oop::Person { // in protected=>test property will be protected!
  friend std::ostream &operator<<(std::ostream &os, const Engineer &e);

public:
  static size_t m_count;

protected:
  std::string_view m_field{};

public:
  Engineer() = default;
  Engineer(std::string_view nid_param, unsigned int age_param,
           std::string_view name_param, std::string_view field);

  Engineer(const Engineer &e);

  ~Engineer();

  Engineer *set_field(std::string_view field);

  std::string_view get_field() const;

  virtual void work() const override;
  /*
    if we want to use other overloads of work function we have to implement
    them, otherwise they are hidden by default
  */
  virtual void work(int start_hour) const override;
  virtual void work(double end_hour) const;
  virtual void work(std::string_view work_param) const;
};

inline std::ostream &operator<<(std::ostream &os, const Engineer &e) {

  os << fmt::format(fg(fmt::color::cyan),
                    "Engineer: [id: {}, name: {}, age: {}, field: {} ]\n",
                    e.get_nid(), e.m_name, e.m_age, e.m_field);
  return os;
}

} // namespace Oop

#endif