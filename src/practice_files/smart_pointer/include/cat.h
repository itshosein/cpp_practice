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

  void print_info();
};
} // namespace CostumeClasses

#endif
