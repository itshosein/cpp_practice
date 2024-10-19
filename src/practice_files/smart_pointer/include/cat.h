#ifndef CAT_H
#define CAT_H

#include <string_view>
namespace CostumeClasses {

class Cat {
private:
  std::string_view m_name{"CatSampleName"};

public:
  Cat() = default;
  Cat(std::string_view name);
  ~Cat();

  Cat *set_name(std::string_view name);

  void print_info();
};
} // namespace CostumeClasses

#endif
