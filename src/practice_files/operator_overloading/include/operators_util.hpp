#ifndef OPERATORS_UTIL_HPP
#define OPERATORS_UTIL_HPP

namespace OpOverload {
template <class T> bool operator!=(const T &lhs, const T &rhs) {
  return !(lhs == rhs);
}
template <class T> bool operator>(const T &lhs, const T &rhs) {
  return rhs < lhs;
}
template <class T> bool operator<=(const T &lhs, const T &rhs) {
  return !(rhs < lhs);
}
template <class T> bool operator>=(const T &lhs, const T &rhs) {
  return !(lhs < rhs);
}
} // namespace OpOverload

#endif
