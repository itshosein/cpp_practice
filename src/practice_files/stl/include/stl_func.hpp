#include <array>
#include <concepts>
#include <cstring>
#include <list>
#include <stack>
#include <vector>

namespace StlExercise {
void stl_func();

template <typename T> void print_raw_array(const T *p, size_t size);

template <typename T, size_t Size>
void print_array(const std::array<T, Size> &arr);

template <typename T> void print_stack(std::stack<T> stack);

template <typename T> void print_list(const std::list<T> &list);

// a concept for checking tha validity of begin and end iterators
template <typename T>
concept is_collection = requires(const T &collection) {
  collection.begin();
  collection.end();
};
template <typename T>
concept is_reversible = requires(const T &collection) {
  std::begin(collection);
  std::end(collection);
};
template <typename T>
concept is_reversible_collection = requires(const T &collection) {
  collection.rbegin();
  collection.rend();
};

template <typename T>
  requires is_reversible_collection<T>
void print_reverse_collection(const T &collection);

template <typename T>
  requires is_collection<T>
void print_collection(const T &collection);

template <typename T>
  requires is_reversible<T>
void print_raw_array(const T &collection);

template <typename T>
  requires is_collection<T>
void print_collection(const T &collection, size_t begin_offset,
                      size_t end_offset);

} // namespace StlExercise
