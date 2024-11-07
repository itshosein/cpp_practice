#include "IStreamInsertable.hpp"

std::ostream &operator<<(std::ostream &os, const IStreamInsertable &si) {
  si.stream_insert(os);
  return os;
}