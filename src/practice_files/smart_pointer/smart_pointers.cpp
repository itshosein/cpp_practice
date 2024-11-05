#include "smart_pointers.hpp"
#include "cat.hpp"
#include <fmt/color.h>
#include <fmt/core.h>

namespace SmartPointers {

void smart_pointers() {

  fmt::print(fg(fmt::color::green),
             "**************************** unique pointer "
             "****************************\n");
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
  {
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
  fmt::print(fg(fmt::color::green),
             "\n**************************** shared pointer "
             "****************************\n\n");

  {

    std::shared_ptr<CostumeClasses::Cat> cat11{
        new CostumeClasses::Cat{"cat11"}};

    cat11->print_info();
    fmt::print(fg(fmt::color::blue), "cat11 use count: {}\n",
               cat11.use_count());
    auto cat12{cat11};
    cat11->set_name("cat11 edited!");
    cat12->print_info();
    fmt::print(fg(fmt::color::blue), "cat11 use count: {}\n",
               cat11.use_count());
    cat12.reset();
    fmt::print(fg(fmt::color::blue), "cat11 use count: {}\n",
               cat11.use_count());

    auto cat13{cat11};
    cat13->print_info();
    cat11.reset();
    fmt::print(fg(fmt::color::blue), "cat11 use count: {}\n",
               cat11.use_count());
    fmt::print(fg(fmt::color::blue), "before block ending");
  }

  {
    fmt::print("\n\nshare ptr with unique ptr\n");

    auto cat14{std::make_unique<CostumeClasses::Cat>("cat14")};
    std::shared_ptr<CostumeClasses::Cat> cat15{std::move(cat14)};
    cat15->print_info();
    fmt::print(fg(fmt::color::blue), "cat15 use count: {}\n",
               cat15.use_count());

    auto cat16{std::make_shared<CostumeClasses::Cat>("cat16")};
    cat16->print_info();

    std::shared_ptr<CostumeClasses::Cat> cat17{get_unique_ptr()};
    cat17->print_info();
    // cat14->print_info();// wrong!!
  }

  {
    fmt::print("\n\narrays of share ptr\n");
    std::shared_ptr<CostumeClasses::Cat[]> cats18{
        new CostumeClasses::Cat[5]{CostumeClasses::Cat{"cat18-1"}}};
    for (size_t i = 0; i < 5; i++) {
      cats18[i].print_info();
    }

    auto cats19{cats18};
    for (size_t i = 0; i < 5; i++) {
      cats19[i].print_info();
    }
    fmt::print(fg(fmt::color::blue), "cats18 use count: {}\n",
               cats18.use_count());
  }

  {
    fmt::print("\n\nshare ptr in param\n");
    std::shared_ptr<CostumeClasses::Cat> cat19{
        std::make_shared<CostumeClasses::Cat>("cat19")};

    shared_ptr_value_prm(cat19);

    fmt::print(fg(fmt::color::blue),
               "cat[address]: {} outside shared_ptr_value_prm\n",
               reinterpret_cast<uintptr_t>(cat19.get()));
    fmt::print(fg(fmt::color::blue),
               "cat[count]: {} outside shared_ptr_value_prm\n\n",
               cat19.use_count());

    auto cat21{get_shared_ptr()};

    fmt::print(fg(fmt::color::blue),
               "cat21[address]: {} outside shared_ptr_value_prm\n",
               reinterpret_cast<uintptr_t>(cat21.get()));
    fmt::print(fg(fmt::color::blue),
               "cat21[count]: {} outside shared_ptr_value_prm\n",
               cat21.use_count());
  }

  {
    fmt::print("\n\nweak ptr\n");
    auto cat22 = std::make_shared<CostumeClasses::Cat>("cat22");
    auto cat23 = std::make_shared<CostumeClasses::Cat>("cat23");

    // cycling dependency problem or circular dependencies
    // because they have shared pointer to each other, they will never get
    // destroyed so we have to use weak pointer to prevent this!
    cat22->set_friend(cat23);
    cat23->set_friend(cat22);

    std::weak_ptr<CostumeClasses::Cat> cat24{cat22};
    std::weak_ptr<CostumeClasses::Cat> cat25{cat23};
    cat24.lock()->print_info();
    fmt::print(fg(fmt::color::blue), "cat24[count]: {} \n", cat24.use_count());
    fmt::print(fg(fmt::color::blue), "cat22[count]: {} \n", cat22.use_count());
  }
}

void unique_ptr_value_prm(std::unique_ptr<CostumeClasses::Cat> cat) {
  cat->print_info();
}

void unique_ptr_ref_prm(const std::unique_ptr<CostumeClasses::Cat> &cat) {
  cat->print_info();
}

void shared_ptr_value_prm(const std::shared_ptr<CostumeClasses::Cat> &cat) {
  fmt::print(fg(fmt::color::blue),
             "cat[address]: {} inside shared_ptr_value_prm\n",
             reinterpret_cast<uintptr_t>(cat.get()));
  fmt::print(fg(fmt::color::blue),
             "cat[count]: {} inside shared_ptr_value_prm\n", cat.use_count());
}

std::shared_ptr<CostumeClasses::Cat> get_shared_ptr() {
  auto cat20{std::make_shared<CostumeClasses::Cat>("cat20")};
  fmt::print(fg(fmt::color::blue), "cat20[address]: {} inside get_shared_ptr\n",
             reinterpret_cast<uintptr_t>(cat20.get()));
  fmt::print(fg(fmt::color::blue), "cat20[count]: {} inside get_shared_ptr\n",
             cat20.use_count());
  return cat20;
}

/**
 * compiler returns the same pointer!
 * @returns
 * same unique pointer to a cat (implicit std::move)
 */
std::unique_ptr<CostumeClasses::Cat> get_unique_ptr() {
  std::unique_ptr<CostumeClasses::Cat> catInner1{
      std::make_unique<CostumeClasses::Cat>("catInner1")};
  fmt::print(fg(fmt::color::blue), "catInner1: {} in get_unique_ptr\n",
             reinterpret_cast<uintptr_t>(catInner1.get()));
  return catInner1;
}
} // namespace SmartPointers
