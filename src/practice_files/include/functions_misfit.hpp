#include <functional>
#include <string>

namespace FunctionMisfits {

void functions_misfit();

int sum(int a, int b);

double sum_double(const double &num1, const double &num2);

// gets a function pointer and returns another function pointer
void (*wrapper(double (*sum)(const double &num1,
                             const double &num2)))(const std::string &name);
std::function<void(const std::string &)> function_wrapper(
    std::function<double(const double &num1, const double &num2)>);
} // namespace FunctionMisfits
