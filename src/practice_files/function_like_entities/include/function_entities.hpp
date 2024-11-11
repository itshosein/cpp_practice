#include <concepts>
#include <string>
#include <vector>

namespace FunctionEntities {
void function_entities();

double add(double a, double b);

char encrypt(const char &);
char decrypt(const char &);

using fn_t = char (*)(const char &);

std::string &modify(std::string &input, fn_t fn);

using comparator_t = bool (*)(const std::string &a, const std::string &b);

std::string get_best(std::vector<std::string> str_v, comparator_t comparator);

bool large_in_size(const std::string &a, const std::string &b);

template <typename T>
  requires std::is_arithmetic_v<T>
class IsInRange {
private:
  T m_max;
  T m_min;

public:
  IsInRange(T min, T max) : m_min{min}, m_max{max} {}
  IsInRange(T &min, T &max) : m_min{min}, m_max{max} {}
  IsInRange(T &&min, T &&max) : m_min{min}, m_max{max} {}

  bool operator()(T value) { return value <= m_max && value >= m_min; }
};

template <typename T>
  requires std::is_arithmetic_v<T>
T sumInRange(std::vector<T> &v, IsInRange<T> is_in_range);
} // namespace FunctionEntities
