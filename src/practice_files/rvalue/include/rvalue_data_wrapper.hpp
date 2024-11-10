#ifndef DATA_WRAPPER_RVALUE_HPP
#define DATA_WRAPPER_RVALUE_HPP

#include <fmt/color.h>
#include <fmt/core.h>
#include <ostream>
#include <string>

/*
  we have to put definition into header file because the compiler should see and
  generate templates and all the methods are inline in template classes by
  default
 */

namespace Rvalue {
template <typename T = int /*, size_t maximum -> None Type template argument! BAD: multiple instances and ugly code base! */>
class DataWrapper {

  friend std::ostream &operator<< <T>(std::ostream &os,
                                      const DataWrapper<T> &d);

private:
  T m_data{};

public:
  DataWrapper() = default;
  DataWrapper(T data);
  DataWrapper(const DataWrapper &p);
  virtual ~DataWrapper();

  DataWrapper &operator=(const DataWrapper &source);

  std::string string();
};

template <typename T> DataWrapper<T>::DataWrapper(T data) : m_data{data} {
  fmt::print(fg(fmt::color::green), "Full constructor!\n");
}

template <typename T>
DataWrapper<T>::DataWrapper(const DataWrapper &p) : DataWrapper(p.m_data) {
  fmt::print(fg(fmt::color::blue), "Copy constructor!\n");
}

template <typename T> DataWrapper<T>::~DataWrapper() {
  fmt::print(fg(fmt::color::orange), "Object destructed!\n");
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const DataWrapper<T> &d) {
  os << fmt::format(fg(fmt::color::blue), "m_data: {}\n", d.m_data);
  return os;
}

template <typename T>
DataWrapper<T> &DataWrapper<T>::operator=(const DataWrapper<T> &source) {
  fmt::print(fg(fmt::color::blue), "Copy assignment!\n");
  this->m_data = source.m_data;
  return *this;
}

template <typename T> std::string DataWrapper<T>::string() {
  return fmt::format(fg(fmt::color::cyan), "m_data: {}\n", this->m_data);
}

DataWrapper<int> create_data_wrapper(int amount, int modifier);

} // namespace Rvalue

#endif // end of DATA_WRAPPER_RVALUE_HPP