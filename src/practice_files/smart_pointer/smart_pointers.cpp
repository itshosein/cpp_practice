#include "smart_pointers.h"
#include "cat.h"
#include <fmt/color.h>
#include <fmt/core.h>

namespace SmartPointers {

void smart_pointers() {
  CostumeClasses::Cat *cat1{new CostumeClasses::Cat{"Sammy"}};
  {
    std::unique_ptr<CostumeClasses::Cat> cat2{cat1};
    cat1 = nullptr;
    cat2->print_info();
    std::unique_ptr<CostumeClasses::Cat> cat3{
        std::make_unique<CostumeClasses::Cat>("Fluffy")};
    cat3->print_info();
    std::unique_ptr<CostumeClasses::Cat> cat4{std::move(cat3)};
    cat4->print_info();
    // cat3->print_info(); wrong ! cat3 points to nullptr because of move
    // constructor of unique_ptr
    cat4.reset(); // release and point to nullptr
  }
  // cat1->print_info(); // error again because cat2 deleted memory!

  std::unique_ptr<CostumeClasses::Cat> cat5{
      std::make_unique<CostumeClasses::Cat>("John")};
  unique_ptr_value_prm(std::move(cat5));
  fmt::print(fg(fmt::color::blue), "cat5: {}\n",
             reinterpret_cast<uintptr_t>(cat5.get()));

  std::unique_ptr<CostumeClasses::Cat> cat6{
      std::unique_ptr<CostumeClasses::Cat>{new CostumeClasses::Cat{"Jack"}}};
  unique_ptr_ref_prm(cat6);
  fmt::print(fg(fmt::color::blue), "cat6: {}\n",
             reinterpret_cast<uintptr_t>(cat6.get()));
  auto cat7{get_unique_ptr()};
  cat7->print_info();

  auto cats8{std::unique_ptr<CostumeClasses::Cat[]>{new CostumeClasses::Cat[]{
      CostumeClasses::Cat{"cat81"}, CostumeClasses::Cat{"cat82"}}}};
  for (size_t i{}; i < 2; i++) {
    cats8[i].print_info();
  }

  std::unique_ptr<CostumeClasses::Cat[]> cats9{new CostumeClasses::Cat[]{
      CostumeClasses::Cat{"cat91"}, CostumeClasses::Cat{"cat92"}}};
  for (size_t i{}; i < 2; i++) {
    cats9[i].print_info();
  }

  std::unique_ptr<CostumeClasses::Cat[]> cats10{
      std::make_unique<CostumeClasses::Cat[]>(2)};
  for (size_t i{}; i < 2; i++) {
    cats10[i].print_info();
  }
}

void unique_ptr_value_prm(std::unique_ptr<CostumeClasses::Cat> cat) {
  cat->print_info();
}

void unique_ptr_ref_prm(const std::unique_ptr<CostumeClasses::Cat> &cat) {
  cat->print_info();
}

/**
 * compiler returns the same pointer!
 * @returns
 * same pointer to a cat (implicit std::move)
 */
std::unique_ptr<CostumeClasses::Cat> get_unique_ptr() {
  std::unique_ptr<CostumeClasses::Cat> catInner1{
      std::make_unique<CostumeClasses::Cat>("catInner1")};
  fmt::print(fg(fmt::color::blue), "catInner1: {} in get_unique_ptr\n",
             reinterpret_cast<uintptr_t>(catInner1.get()));
  return catInner1;
}
} // namespace SmartPointers
