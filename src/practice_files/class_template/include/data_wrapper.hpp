#ifndef PERSON_TEMPLATE_HPP
#define PERSON_TEMPLATE_HPP

#include "IStreamInsertable.hpp"
#include <fmt/color.h>
#include <fmt/core.h>
#include <ostream>

/*
  we have to put definition into header file because the compiler should see and
  generate templates and all the methods are inline in template classes by
  default
 */

namespace ClassTemplates {
template <typename T = int /*, size_t maximum -> None Type template argument! BAD: multiple instances and ugly code base! */>
class DataWrapper /*  : IStreamInsertable */ {
  // friend std::ostream &operator<<(std::ostream &os, const DataWrapper<T> &d);

private:
  T m_data{};

public:
  DataWrapper() = default;
  DataWrapper(T data);
  DataWrapper(const DataWrapper &p);
  virtual ~DataWrapper();

  T get_data() const;

  // virtual void stream_insert(std::ostream &os) const override;
};

/*
  specialize template class
  is a full class and separate from template class and it is not inline by
  default
 */
template <> class DataWrapper<char *> {

private:
  char *m_data{};

public:
  DataWrapper() = default;
  DataWrapper(char *data);
  DataWrapper(const DataWrapper &p);
  virtual ~DataWrapper();

  char *get_data() const;

  // virtual void stream_insert(std::ostream &os) const override;
};

template <typename T> DataWrapper<T>::DataWrapper(T data) : m_data{data} {}

template <typename T>
DataWrapper<T>::DataWrapper(const DataWrapper &p) : DataWrapper(p.m_data) {}

template <typename T> DataWrapper<T>::~DataWrapper() {}

template <typename T> T DataWrapper<T>::get_data() const {
  return this->m_data;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const DataWrapper<T> &d) {
  os << fmt::format(fg(fmt::color::blue), "m_data: {}\n", d.get_data());
  return os;
}

// template <typename T>
// void DataWrapper<T>::stream_insert(std::ostream &os) const {
//   os << fmt::format(fg(fmt::color::blue), "DataWrapper has: {}\n",
//                     this->m_data);
// }

} // namespace ClassTemplates

#endif