#include <string>
#include <vector>
namespace FunctionEntities {
void function_entities();

double add(double a, double b);

char encrypt(const char &);
char decrypt(const char &);

std::string &modify(std::string &input, char (*fn)(const char &));

std::string get_best(std::vector<std::string> str_v,
                     bool (*comparator)(const std::string &a,
                                        const std::string &b));

bool large_in_size(const std::string &a, const std::string &b);
} // namespace FunctionEntities
