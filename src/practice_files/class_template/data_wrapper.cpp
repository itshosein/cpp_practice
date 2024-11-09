#include "data_wrapper.hpp"

namespace ClassTemplates {

/* template <typename T> DataWrapper<T>::DataWrapper(T data) : m_data{data} {}

template <typename T>
DataWrapper<T>::DataWrapper(const DataWrapper &p) : DataWrapper(p.m_data) {}

template <typename T> DataWrapper<T>::~DataWrapper() {}

template <typename T>
void DataWrapper<T>::stream_insert(std::ostream &os) const {

  os << "test";
}
*/

// template specialized implementations because they are inline!
DataWrapper<char *>::DataWrapper(char *data) : m_data{data} {}

DataWrapper<char *>::DataWrapper(const DataWrapper &p)
    : DataWrapper(p.m_data) {}

DataWrapper<char *>::~DataWrapper() {}

// specialized << for char *
std::ostream &operator<<(std::ostream &os, const DataWrapper<char *> &d) {
  os << fmt::format(fg(fmt::color::blue), "m_data: {}\n", d.m_data);
  return os;
}

} // namespace ClassTemplates
