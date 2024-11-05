#include <concepts>
#include <type_traits>

template <typename T>
concept MyIntegral = std::is_integral_v<T> || std::is_floating_point_v<T>;
/*
template <typename T, typename U>
concept Addable = requires(T a, T b) { // simple requirement
  a + b;
  a++;
  b++;
  ++a;
  ++b;
};

*/
template <typename T, typename U>
concept Addable = requires(T a, T b) {
  a + b; // just syntax check
  sizeof(T);
  requires sizeof(T) <= 4; // nested requirement checks the if
};

template <typename R, typename T, typename U>
concept TinyAddResult = requires(R r, T a, T b) {
  {
    a + b
  } -> std::convertible_to<double>; // compound requirement check the return
                                    // type of a expression
  requires sizeof(R) <= 4;
};

void concepts();

template <MyIntegral R = int, MyIntegral T, MyIntegral U>
  requires TinyAddResult<R, T, U>
R add(T a, U b);