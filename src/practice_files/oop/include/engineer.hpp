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
class Engineer final
    : public Oop::Person { // in protected=>test property will be protected!

public:
  static size_t m_count;

protected:
  std::string_view m_field{};

public:
  Engineer() = default;
  Engineer(std::string_view nid_param, unsigned int age_param,
           std::string_view name_param, std::string_view field);

  Engineer(const Engineer &e);

  virtual ~Engineer();

  Engineer *set_field(std::string_view field);

  std::string_view get_field() const;

  /*
    virtual methods access modifier are ignored! only the base class is
    important
   */
private:
  // /* virtual doesn't makes sense with final */ void work() const override
  // final;
  /*
    if we want to use other overloads of work function we have to implement
    them, otherwise they are hidden by default
  */
  /*
    in polymorphism default argument of child is ignored because it is compile
    time
  */
  /* virtual */ void work(int start_hour = 10) const override final;

  /* virtual -> doesn't makes sense with class being final */
  virtual void work(double end_hour) const;
  virtual void work(std::string_view work_param) const;

  virtual void stream_insert(std::ostream &os) const;
};

// inline std::ostream &operator<<(std::ostream &os, const Engineer &e) {

//   os << fmt::format(fg(fmt::color::cyan),
//                     "Engineer: [id: {}, name: {}, age: {}, field: {} ]\n",
//                     e.get_nid(), e.m_name, e.m_age, e.m_field);
//   return os;
// }

} // namespace Oop

#endif