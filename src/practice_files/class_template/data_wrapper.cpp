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

DataWrapper<char *>::DataWrapper(char *data) : m_data{data} {}

DataWrapper<char *>::DataWrapper(const DataWrapper &p)
    : DataWrapper(p.m_data) {}

DataWrapper<char *>::~DataWrapper() {}

char *DataWrapper<char *>::get_data() const { return this->m_data; }

} // namespace ClassTemplates
