#include "stl_func.hpp"
#include <fmt/color.h>
#include <fmt/core.h>

namespace StlExercise {
void stl_func() {
  /*
  stl contains three parts:
  1) containers
  2) algorithms
  3) iterators


  std::vector<int> vec1{1, 2, 3, 4};
  // (amount of variable, default value)
  std::vector<int> vec2(10, 10000);

  fmt::print(fg(fmt::color::green), "vec1: ");
  for (auto &&el : vec1) {
    fmt::print(fg(fmt::color::green), "{} ", el);
  }

  fmt::print(fg(fmt::color::green), "\nvec2: ");
  print_raw_array(vec2.data(), vec2.size());



  std::array<int, 5> arr1{1, 2, 3, 4};
  std::array arr2{23.4, 21.45, 1245.22};

  fmt::print(fg(fmt::color::green), "arr1: ");
  print_raw_array(arr1.data(), arr1.size());

  fmt::print(fg(fmt::color::green), "\narr2: ");
  print_array(arr2);


  std::stack<int> stack1;
  stack1.push(1);
  stack1.push(13030);
  std::stack<double> stack2;
  stack2.push(13.131);
  stack2.push(983.1233);

  fmt::print(fg(fmt::color::green), "stack1: ");
  print_stack(stack1);

  fmt::print(fg(fmt::color::green), "stack2: ");
  print_stack(stack2);
   */

  // list is better when you want insertion from both side or in the middle
  // as well as deletion. better complexity than vector.
  // vector is better when accessing fast random access to elements
  // vector maintain the order better
  // so if you want to change the elements a lot use list
  // and if you want order and random access more use vector
  std::vector<int> vec2{1, 2, 3, 4, 5};
  std::list<int> list1{};
  list1.push_back(10);
  list1.push_front(1); // only in list not in vector
  list1.push_front(2);
  list1.push_front(3);
  list1.push_front(4);
  list1.push_front(5);

  fmt::print(fg(fmt::color::green), "list1:");
  print_list(list1);

  // we can't use offset with iterators on list because it does not
  // provide random access because it not contiguous
  fmt::print(fg(fmt::color::green), "\nPrinting list1 with iterators: ");
  print_collection(list1);

  fmt::print(fg(fmt::color::green), "\nPrinting vec2 with iterators: ");
  print_collection(vec2);

  fmt::print(fg(fmt::color::green), "\nPrinting vec2 with iterators offset: ");
  print_collection(vec2, 2, 1);
}

template <typename T> void print_raw_array(const T *p, size_t size) {
  for (size_t i{}; i < size; i++) {
    fmt::print(fg(fmt::color::green), "{} ", p[i]);
  }
}

template <typename T, size_t Size>
void print_array(const std::array<T, Size> &arr) {
  for (auto &i : arr) {
    fmt::print(fg(fmt::color::green), "{} ", i);
  }
}

template <typename T> void print_stack(std::stack<T> stack) {
  while (!stack.empty()) {
    fmt::print(fg(fmt::color::green), "{} ", stack.top());
    stack.pop();
  }
}

template <typename T> void print_list(const std::list<T> &list) {
  for (auto &i : list) {
    fmt::print(fg(fmt::color::green), "{} ", i);
  }
}

template <typename T>
  requires is_collection<T>
void print_collection(const T &collection) {
  auto iterator{collection.begin()};

  while (iterator != collection.end()) {
    fmt::print(fg(fmt::color::green), "{} ", *iterator);
    iterator++;
  }
}

template <typename T>
  requires is_collection<T>
void print_collection(const T &collection, size_t begin_offset,
                      size_t end_offset) {
  auto begin_iterator{collection.begin() + begin_offset};
  auto end_iterator{collection.end() - end_offset};

  while (begin_iterator != end_iterator) {
    fmt::print(fg(fmt::color::green), "{} ", *begin_iterator);
    begin_iterator++;
  }
}
} // namespace StlExercise
