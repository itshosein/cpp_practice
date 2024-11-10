#include "rvalue_data_wrapper.hpp"

namespace Rvalue {
DataWrapper<int> create_data_wrapper(int data, int modifier) {
  DataWrapper<int> data1(data * modifier);
  return data1;
}

} // namespace Rvalue
