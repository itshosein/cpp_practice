#ifndef CAT_H
#define CAT_H

#include <memory>
#include <string_view>

namespace CostumeClasses {

class Cat {
private:
  std::string_view m_name{"CatSampleName"};
  std::weak_ptr<Cat> m_friend{};

public:
  Cat() = default;
  Cat(std::string_view name);
  ~Cat();

  Cat *set_name(std::string_view name);

  Cat *set_friend(const std::shared_ptr<Cat> &cat);

  void print_info();
};
} // namespace CostumeClasses

#endif
