#ifndef PERSON_TEMPLATE_HPP
#define PERSON_TEMPLATE_HPP

#include "IStreamInsertable.hpp"
#include <concepts>
#include <fmt/color.h>
#include <fmt/core.h>
#include <ostream>
#include <type_traits>

/*
  we have to put definition into header file because the compiler should see and
  generate templates and all the methods are inline in template classes by
  default
 */

namespace ClassTemplates {
template <typename T = int /*, size_t maximum -> None Type template argument! BAD: multiple instances and ugly code base! */>
requires std::is_default_constructible_v<T> // concepts!
class DataWrapper /*  : IStreamInsertable */ {

  // static_assert(std::is_arithmetic_v<T>,
  //               "DataWrapper should only have arithmetic type");
  // have to say this function is template with <T> after name!
  friend std::ostream &operator<< <T>(std::ostream &os,
                                      const DataWrapper<T> &d);

private:
  T m_data{};

public:
  DataWrapper() = default;
  DataWrapper(T data);
  DataWrapper(const DataWrapper &p)
    requires std::copyable<T>;
  ;
  virtual ~DataWrapper();

  // virtual void stream_insert(std::ostream &os) const override;
};

/*
  specialize template class
  is a full class and separate from template class and it is not inline by
  default
 */
template <> class DataWrapper<char *> {
  friend std::ostream &operator<<(std::ostream &os,
                                  const DataWrapper<char *> &d);

private:
  char *m_data{};

public:
  DataWrapper() = default;
  DataWrapper(char *data);
  DataWrapper(const DataWrapper &p);
  virtual ~DataWrapper();

  // virtual void stream_insert(std::ostream &os) const override;
};

template <typename T>
  requires std::is_default_constructible_v<T>
DataWrapper<T>::DataWrapper(T data) : m_data{data} {}

template <typename T>
  requires std::is_default_constructible_v<T>
DataWrapper<T>::DataWrapper(const DataWrapper &p)
  requires std::copyable<T>
    : DataWrapper(p.m_data) {}

template <typename T>
  requires std::is_default_constructible_v<T>
DataWrapper<T>::~DataWrapper() {}

template <typename T>
  requires std::is_default_constructible_v<T>
std::ostream &operator<<(std::ostream &os, const DataWrapper<T> &d) {
  os << fmt::format(fg(fmt::color::blue), "m_data: {}\n", d.m_data);
  return os;
}

// template <typename T>
// void DataWrapper<T>::stream_insert(std::ostream &os) const {
//   os << fmt::format(fg(fmt::color::blue), "DataWrapper has: {}\n",
//                     this->m_data);
// }

} // namespace ClassTemplates

#endif