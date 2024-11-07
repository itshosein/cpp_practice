#include "costume_exception.hpp"
#include <fmt/color.h>
#include <fmt/core.h>

namespace ExceptionHandling {
CostumeException::CostumeException(std::string_view msg) : m_msg{msg} {}

CostumeException::CostumeException(const CostumeException &ce)
    : CostumeException(ce.m_msg) {}

CostumeException::~CostumeException() {
  fmt::print(fg(fmt::color::blue), "costume exception deleted!\n");
}

const char *CostumeException::what() const noexcept { return m_msg.c_str(); }

} // namespace ExceptionHandling
