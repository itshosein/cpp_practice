#include <cstring>
#include <string>
#include <string_view>

void functions();

void sum_of_arr(const double (&arr)[5], double &sum_output,
                double initial_value = 0);

void increment(int &value);

void say_hello(std::string_view name);

constexpr int multiply(int value1, int value2) { return value1 * value2; }

consteval int multiply_to_two(int value) { return value * 2; }

int *max_ref(int *num1, int *num2);

int &max_ref(int &num1, int &num2);

const double *find_max(const double array[], size_t size);
