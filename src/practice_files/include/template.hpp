#include <string>

void template_func();

template <typename R = double, typename T, typename U>
R maximum(const T &a, const U &b);
// template <typename R, typename T, typename U> R maximum(T a, U b);
template <typename R, typename T, typename U> R *maximum(T *a, T *b);
// template <> const char *maximum<const char *>(const char *a, const char *b);

const char *maximum(const char *a, const char *b);

template <typename T, typename U>
auto add(const T &a, const U &b) -> decltype(a + b);

void string_printer(std::string_view a);
void integral_printer(int a);
void floating_printer(double a);