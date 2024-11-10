#include "rvalue.hpp"
#include "rvalue_data_wrapper.hpp"
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>

namespace Rvalue {
void rvalue_func() {
  double a{3414};

  int b{230};

  int c{255};

  /*
    res is a rvalue reference because a+b produces a temporary memory location
    so we use it
   */
  /* double &&res{a / b};

  int &&result_of_add_func{add(a, b)};

  fmt::print(fg(fmt::color::blue), "res: {:.3f}\n", res);
  fmt::print(fg(fmt::color::blue), "result_of_add_func: {}\n",
             result_of_add_func);

  int &&moved_c{std::move(c)};

  c = 1;

  fmt::print(fg(fmt::color::blue), "c: {}\n", c);
  fmt::print(fg(fmt::color::blue), "moved_c: {}\n", moved_c);

  int *int_ptr{new int{20123}};
  int *&&moved_ptr{std::move(int_ptr)};

  *int_ptr = 2;

  fmt::print(fg(fmt::color::blue), "int_ptr: {}\n", *int_ptr);
  fmt::print(fg(fmt::color::blue), "moved_ptr: {}\n", *moved_ptr);

  delete int_ptr;
  // delete moved_ptr; // crash! releasing one memory twice!


  DataWrapper<int> data1(10);
  DataWrapper<int> data2(50);

  fmt::print(fg(fmt::color::chocolate), "-----------------\n");

  // here a rvalue of DataWrapper being destructed
  // but with move assignment we can trigger a pointer steal
  // and prevent from losing dynamic data!
  // data1 = create_data_wrapper(10, 20);

  fmt::print(fg(fmt::color::chocolate), "-----------------\n");

  fmt::print(fg(fmt::color::blue), "data1: {}\n", data1.string());

  fmt::print(fg(fmt::color::chocolate),
             "----------------- swap_data_wrapper_copy -----------------\n");

  swap_data_wrapper_copy(data1, data2);

  fmt::print(fg(fmt::color::blue), "data1: {}\n", data1.string());
  fmt::print(fg(fmt::color::blue), "data2: {}\n", data2.string());

  fmt::print(fg(fmt::color::chocolate),
             "----------------- swap_data_wrapper_move -----------------\n");

  swap_data_wrapper_move(data1, data2);

  fmt::print(fg(fmt::color::blue), "data1: {}\n", data1.string());
  fmt::print(fg(fmt::color::blue), "data2: {}\n", data2.string());
*/
  fmt::print(fg(fmt::color::chocolate),
             "----------------- move using in functions -----------------\n");

  // calling a function creates rvalue that we can use!
  DataWrapper<int> &&data3{getData<DataWrapper<int>>()};

  // passing by rvalue -> because rvalue with name in arguments treats as lvalue
  addToData(std::move(data3), std::move(10));

  fmt::print(fg(fmt::color::blue), "data3: {}\n", data3.string());

  fmt::print(fg(fmt::color::blue), "Done.\n");
}

int add(const int &a, const int &b) { return a + b; }

template <class T> void swap_data_wrapper_copy(T &a, T &b) {
  T temp{a};
  a = b;
  b = temp;
}
template <class T> void swap_data_wrapper_move(T &a, T &b) {
  // move constructor to empty the a
  T temp{std::move(a)};
  // move assignment to empty b
  a = std::move(b);
  // move assignment to empty tmp
  b = std::move(temp);
}

template <class T> T getData() { return T(); }

template <typename T>
void addToData(DataWrapper<T> &&data_wrapper, T &&amount) {
  data_wrapper.add(std::move(amount)); // if amount is int this is overhead!
}
} // namespace Rvalue
