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

  // set is working with operator< and it is in-order!
  std::set<int , std::less<int>> set1{3, 1, 2, 5, 666, 11, 0, 666}; // default
  // functor
  std::set<std::string, std::function<bool(const std::string &, const
  std::string &)>> set_str1(str_compare);

  set_str1.insert({"test1", "test11", "test2", "test22", "test332414"});

  fmt::print(fg(fmt::color::green), "set1:\n");
  print_collection(set1);

  auto insert_result{set_str1.insert("test1")};

  if (insert_result.second) {
    fmt::print(fg(fmt::color::blue), "insertion of {} was successful!\n",
               *insert_result.first);
  } else {
    fmt::print(fg(fmt::color::red), "insertion of {} was not successful!\n",
               *insert_result.first);
  }

  auto iter_found{std::find(set_str1.begin(), set_str1.end(), "test1")};

  if (iter_found != set_str1.end()) {
    set_str1.erase(iter_found);
    fmt::print(fg(fmt::color::blue), "deletion of {} was successful!\n",
               "test1");
  } else {
    fmt::print(fg(fmt::color::blue), "deletion of {} was not successful!\n",
               "test1");
  }

  fmt::print(fg(fmt::color::green), "set_str1:\n");
  print_collection(set_str1);


  // ordered collection of set that is ordered based of keys
  std::map<std::string, std::string> map1{{"k1", "v1"}, {"k11", "v2"}};

  map1.insert({"k2", "v2"});
  auto [pair_res, is_bool_inserted]{map1.insert({"k1", "v2"})};

  if (is_bool_inserted) {
    fmt::print(fg(fmt::color::blue), "insertion of {} was successful!\n",
               pair_res->first);
  } else {
    fmt::print(fg(fmt::color::red), "insertion of {} was not successful!\n",
               pair_res->first);
  }

  fmt::print(fg(fmt::color::green), "map1:\n");
  print_collection(map1);

  // default container is deque
  // container can be list and deque
  std::queue<int> q1{};
  q1.push(10);
  q1.push(123123);
  q1.push(451);
  fmt::print(fg(fmt::color::green), "q1:\n");
  print_queue(q1);

  std::queue<int, std::list<int>> q2{};
  q2.push(98);
  q2.push(8213);
  q2.push(1407);
  q2.push(180273);
  fmt::print(fg(fmt::color::green), "q2:\n");
  print_queue(q2);

  // default container is vector
  // default comparator is std::less
  std::priority_queue<double> pq1{};
  pq1.push(123.123);
  pq1.push(9123.123);
  pq1.push(192.12);
  fmt::print(fg(fmt::color::green), "pq1:\n");
  print_priority_queue(pq1);

  */
  int coll1[]{1, 2, 3, 4, 5};
  std::vector<int> coll2{10, 20, 30, 188, 14};
  std::set<int> coll3{29, 10, 298, 3914, 120, 1310};
  /*
    if (std::all_of(std::begin(coll1), std::end(coll1),
                    [](int &a) { return a % 2 == 0; })) {
      fmt::print(fg(fmt::color::green), "All of member of coll1 is even\n");
    } else {
      fmt::print(fg(fmt::color::green), "Not all of member of coll1 is even\n");
    }
    if (std::all_of(std::begin(coll2), std::end(coll2),
                    [](int &a) { return a % 2 == 0; })) {
      fmt::print(fg(fmt::color::green), "All of member of coll2 is even\n");
    } else {
      fmt::print(fg(fmt::color::green), "Not all of member of coll2 is even\n");
    }
    if (std::all_of(std::next(std::begin(coll3), 1), std::end(coll3),
                    [](const int &a) { return a % 2 == 0; })) {
      fmt::print(fg(fmt::color::green), "All of member of coll3 is even\n");
    } else {
      fmt::print(fg(fmt::color::green), "Not all of member of coll3 is even\n");
    } */

  if (std::any_of(std::next(std::begin(coll2), 3), std::end(coll2),
                  DivisibleBy(10))) {
    fmt::print(fg(fmt::color::green),
               "At least one of coll2's member is divisible by 10\n");
  } else {
    fmt::print(fg(fmt::color::green),
               "None of coll2's member is divisible by 10\n");
  }
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

bool str_compare(const std::string &a, const std::string &b) {
  return a.size() < b.size();
}

template <typename K, typename V>
  requires is_collection<K>
void print_collection(const std::map<K, V> &collection) {
  auto iter{collection.begin()};

  while (iter != collection.end()) {
    fmt::print(fg(fmt::color::green), "({} : {}) ", iter->first, iter->second);
    iter++;
  }
}

template <typename T, typename U> void print_queue(std::queue<T, U> q) {

  while (!q.empty()) {
    fmt::print(fg(fmt::color::green), "{} ", q.front());
    q.pop();
  }
  fmt::println("");
}

template <typename T, typename U, typename V>
void print_priority_queue(std::priority_queue<T, U, V> pq) {
  while (!pq.empty()) {
    fmt::print(fg(fmt::color::green), "{} ", pq.top());
    pq.pop();
  }
  fmt::println("");
}

} // namespace StlExercise
