#include <cstring>

#include <optional>
#include <string_view>

void strings();

size_t *find_repeated_positions(std::string_view str,
                                std::optional<std::string_view> op_str,
                                size_t &number_of_repetition);