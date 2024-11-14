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

  fmt::print(fg(fmt::color::green), "\nPrinting vec2 with iterators reverse: ");
  print_reverse_collection(vec2);

  fmt::print(fg(fmt::color::green), "\nPrinting vec2 with iterators offset: ");
  print_collection(vec2, 2, 1);

  int raw_arr[]{1, 2, 3, 4, 5};
  fmt::print(fg(fmt::color::green), "\nPrinting raw_arr with iterators : ");
  print_raw_array(raw_arr);


  // deque is best for adding from both side (double end queue)
  std::deque<int> deq1{1, 2, 3, 4, 5, 6, 7};

  fmt::print(fg(fmt::color::green), "\ndeq1: ");
  print_collection(deq1);

  auto iter{deq1.begin() + 1};
  deq1.insert(iter, 100);

  fmt::print(fg(fmt::color::green), "\ndeq1 after insertion: ");
  print_collection(deq1);

  deq1.erase(iter + 1);

  fmt::print(fg(fmt::color::green), "\ndeq1 after erase: ");
  print_collection(deq1);

  fmt::print(fg(fmt::color::green), "\ndeq1 max size: {}", deq1.max_size());

  // deque is specialized for these methods!
  deq1.pop_back();
  deq1.pop_front();
  deq1.push_back(1000);
  deq1.push_front(2000);

  fmt::print(fg(fmt::color::green), "\ndeq1 after push and pop: ");
  print_collection(deq1);


  // forward list has forward iterator so it can't use [] and reverse iterator
  // it is not contiguous finding just one element is costly o(n)
  // it has functions like unique and sort
  // every singly-link or doubly-link has unique and sort
  std::forward_list<int> fl1{123, 4, 56, 78, 123, 4, 5, 5, 12, 5, 7, 8, 9};

  fmt::print(fg(fmt::color::green), "fl1: ");
  print_collection(fl1);

  fl1.insert_after(fl1.before_begin(), 1000);
  fmt::print(fg(fmt::color::green), "fl1 after insert_after: ");
  print_collection(fl1);

  auto found_iter{std::find(fl1.before_begin(), fl1.end(), 5)};
  if (found_iter != fl1.end()) {
    fmt::print(fg(fmt::color::green), "found number 5 in fl1: {}\n",
               *found_iter);
  } else {
    fmt::print(fg(fmt::color::green), "not found number 5 in fl1\n");
  }

  // only remove contiguous repeat! so we can sort to effectively remove
  // duplications
  fl1.unique();
  fmt::print(fg(fmt::color::green), "fl1 after unique: ");
  print_collection(fl1);

  fl1.sort([](const int &a, const int &b) -> bool { return a < b; });
  fmt::print(fg(fmt::color::green), "fl1 after sort: ");
  print_collection(fl1);

  fl1.unique();
  fmt::print(fg(fmt::color::green), "fl1 after sort unique: ");
  print_collection(fl1);
  */

  std::pair<double, std::string> p1{192.22, "Hello"};
  auto p2{std::make_pair<double, std::string>(12.33, "hii")};

  fmt::print(fg(fmt::color::green), "p1: first: {} second: {}\n", p1.first,
             p1.second);
  fmt::print(fg(fmt::color::green), "p2: first: {} second: {}\n", p2.first,
             p2.second);

  auto [p1_first, p1_second]{p1};

  fmt::print(fg(fmt::color::green), "p1 auto: first: {} second: {}\n", p1_first,
             p1_second);

  std::vector<std::pair<std::string, std::string>> vec4{{"k1", "v1"},
                                                        {"k2", "v2"}};

  fmt::print(fg(fmt::color::green), "p2 for auto:\n");
  for (auto &[first, second] : vec4) {
    first = "k11";
    fmt::print(fg(fmt::color::green), "first: {} second: {}\n", first, second);
  }
  fmt::print(fg(fmt::color::green), "vec4[0] after for first: {} second: {}\n",
             vec4[0].first, vec4[0].second);
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

  fmt::println("");
}

template <typename T>
  requires is_reversible_collection<T>
void print_reverse_collection(const T &collection) {
  auto iterator{collection.rbegin()};

  while (iterator != collection.rend()) {
    fmt::print(fg(fmt::color::green), "{} ", *iterator);
    iterator++;
  }
}

template <typename T>
  requires is_reversible<T>
void print_raw_array(const T &collection) {
  auto iterator{std::cbegin(collection)};
  auto end_iterator{std::cend(collection)};

  while (iterator != end_iterator) {
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
