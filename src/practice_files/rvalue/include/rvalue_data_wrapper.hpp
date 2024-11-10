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
  T *m_data{nullptr};

public:
  DataWrapper();
  DataWrapper(T data);
  DataWrapper(const DataWrapper &p);
  DataWrapper(DataWrapper &&p);
  virtual ~DataWrapper();

  DataWrapper &operator=(const DataWrapper &source);
  DataWrapper &operator=(DataWrapper &&source);

  std::string string();
  void invalidate();
};

template <typename T> DataWrapper<T>::DataWrapper() : m_data{new T()} {
  fmt::print(fg(fmt::color::green), "Default constructor!\n");
}

template <typename T>
DataWrapper<T>::DataWrapper(T data) : m_data{new T(data)} {
  fmt::print(fg(fmt::color::green), "Full constructor!\n");
}

template <typename T>
DataWrapper<T>::DataWrapper(const DataWrapper &p) : DataWrapper(*(p.m_data)) {
  fmt::print(fg(fmt::color::blue), "Copy constructor!\n");
}

template <typename T>
DataWrapper<T>::DataWrapper(DataWrapper &&p) : m_data{p.m_data} {
  fmt::print(fg(fmt::color::blue), "Move constructor!\n");
  p.invalidate();
}

template <typename T> DataWrapper<T>::~DataWrapper() {
  fmt::print(fg(fmt::color::orange),
             "Object destructed with data[address]: {}!\n",
             reinterpret_cast<uintptr_t>(this->m_data));
  delete m_data;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const DataWrapper<T> &d) {
  os << fmt::format(fg(fmt::color::blue), "m_data: {}\n", d.m_data);
  return os;
}

template <typename T>
DataWrapper<T> &DataWrapper<T>::operator=(const DataWrapper<T> &source) {
  fmt::print(fg(fmt::color::blue), "Copy assignment!\n");
  *m_data = *source.m_data;
  return *this;
}
template <typename T>
DataWrapper<T> &DataWrapper<T>::operator=(DataWrapper<T> &&source) {
  fmt::print(fg(fmt::color::blue), "Move assignment!\n");
  m_data = source.m_data;
  source.invalidate();
  return *this;
}

template <typename T> std::string DataWrapper<T>::string() {
  return fmt::format(fg(fmt::color::cyan), "m_data: {}\n", *(this->m_data));
}

template <typename T> void DataWrapper<T>::invalidate() { m_data = nullptr; }

DataWrapper<int> create_data_wrapper(int amount, int modifier);

} // namespace Rvalue

#endif // end of DATA_WRAPPER_RVALUE_HPP