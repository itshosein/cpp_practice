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
} // namespace FunctionEntities
