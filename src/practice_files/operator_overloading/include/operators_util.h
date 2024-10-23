#ifndef OPERATORS_UTIL_H
#define OPERATORS_UTIL_H

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
