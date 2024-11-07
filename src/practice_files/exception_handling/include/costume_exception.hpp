#ifndef COSTUME_EXCEPTION_HPP
#define COSTUME_EXCEPTION_HPP

#include <exception>
#include <string>
#include <string_view>

namespace ExceptionHandling {
class CostumeException : public std::exception {
private:
  std::string m_msg{};

public:
  CostumeException() = default;
  CostumeException(std::string_view msg);

  CostumeException(const CostumeException &ce);
  ~CostumeException();

  virtual const char *what() const noexcept override;
};

} // namespace ExceptionHandling

#endif