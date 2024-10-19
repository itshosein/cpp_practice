#ifndef SMART_POINTERS_H
#define SMART_POINTERS_H
#include <memory>

namespace CostumeClasses {
class Cat;
} // namespace CostumeClasses

namespace SmartPointers {
void smart_pointers();

void unique_ptr_value_prm(std::unique_ptr<CostumeClasses::Cat> cat);

void unique_ptr_ref_prm(const std::unique_ptr<CostumeClasses::Cat> &cat);

std::unique_ptr<CostumeClasses::Cat> get_unique_ptr();

void shared_ptr_value_prm(const std::shared_ptr<CostumeClasses::Cat> &cat);

std::shared_ptr<CostumeClasses::Cat> get_shared_ptr();

} // namespace SmartPointers

#endif