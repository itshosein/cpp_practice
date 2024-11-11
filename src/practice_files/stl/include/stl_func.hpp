#include <array>
#include <cstring>
#include <stack>
#include <vector>

namespace StlExercise {
void stl_func();

template <typename T> void print_raw_array(const T *p, size_t size);

template <typename T, size_t Size>
void print_array(const std::array<T, Size> &arr);

template <typename T> void print_stack(std::stack<T> stack);
} // namespace StlExercise
