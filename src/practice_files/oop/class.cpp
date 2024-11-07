#include "class.hpp"
#include "cylinder.hpp"
#include "engineer.hpp"
#include "person.hpp"
#include "point.hpp"
#include <fmt/core.h>
#include <iostream>
#include <memory>
#include <vector>

namespace Oop {

void class_func() {
  double num1{20.99};
  double num2{44.22};
  double num3{99.22};
  double num4{66.28};
  /*


  Point p{};
  p.x = 22.99;
  p.y = 1999.344;
  p.z = 65.9;
  std::cout << p.get_info();
  auto [a, b, c] = p;

  p.x = 50.99;

  std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;

  const Person person1("0213123", 27, "hossein");
  Person person2("6526263");

  std::cout << person1.get_info();
  std::cout << person1.get_info();
  std::cout << person2.get_info();

  std::cout << std::boolalpha << "Is person1's age greater than person2's age? "
            << comparePersonAges(person1, person2) << std::endl;
  // std::cout << std::boolalpha << "Is person1's age greater than 20? "
  //           << comparePersonAges(person1, 20)
  //           << std::endl; //  be aware::implicit Person creation!!!

  Cylinder c1{"C1", num1, num2}; // () can be used!
  Cylinder c4{"C4", num1, num2}; //
  // std::cout << "c1.get_vol(): " << c1.get_vol() << std::endl;
  c1.print_info();
  c4.print_info();

  std::cout << "sizeof(c1): " << sizeof(c1)
            << std::endl; // just the sizeof members!

  {
    Cylinder c2;
    c2.print_info();

    c2.set_height(num3)->set_base_radius(num4)->print_info("after change");
    // class_param(c2);
    // std::cout
    //     << "after class_param func: " << c2.get_name()
    //     << std::endl; // reading data that is not for us anymore! dangerous
  }

  Cylinder *p_c1 = &c1;

  (*p_c1).print_info("(*p_c1).print_info()");
  p_c1->print_info("p_c1->print_info()");
*/
  Cylinder *p_c3 = new Cylinder{"*p_c3", 20, 111.99};
  Cylinder c5{"c5", num1, num2};
  Cylinder c6{c5};

  // p_c3->print_info("p_c3");
  // c5.print_info("c5 variable: ");
  // c6.print_info("c6 variable: ");

  // class_param(*p_c3);

  std::cout << "\n----------- creating arrays -----------" << std::endl;

  Cylinder cylinders[]{*p_c3, c5, c6}; // arrays will create copies!!!!

  std::cout << "\n----------- simple for loop -----------" << std::endl;

  for (size_t i{}; i < std::size(cylinders); i++) {
    std::cout << "inside for: " << cylinders[i];
  }

  std::cout << "\n----------- range for loop -----------" << std::endl;

  for (Cylinder &c : cylinders) { // without reference will create copy!!
    std::cout << c;
  }

  std::cout << "\n----------- creating vectors -----------" << std::endl;

  std::vector<Cylinder> v_cylinders{*p_c3, c5, c6};

  std::cout << "\n----------- move constructor -----------" << std::endl;

  Cylinder c7{std::move(Cylinder{"c7", 7, 7})};

  std::cout << c7;

  std::cout << "\n----------- initializer list {} -----------" << std::endl;

  std::initializer_list<int> int_list{1, 2, 3};

  for (const int *i{int_list.begin()}; i != int_list.end(); i++) {
    std::cout << "int_list[" << i << "]: " << *i << std::endl;
  }
  std::cout << "int_list size():" << int_list.size() << std::endl;

  Point p1{10, 11, 12};
  std::cout << p1.get_info();

  std::cout << "\n----------- friend of cylinder calling -----------"
            << std::endl;

  print_cylinder_private(c5);

  std::cout << "\n----------- static and const member variable  -----------"
            << std::endl;

  std::cout << "Cylinder::m_cylinder_alive_count: "
            << Cylinder::m_cylinder_alive_count << std::endl; // 9
  std::cout << "Cylinder::CLASS_STRING: " << Cylinder::CLASS_STRING
            << std::endl;
  std::cout << "p_c3->WEIRD_CONST: " << p_c3->WEIRD_CONST << std::endl;

  std::cout << "\n----------- self member variable  -----------" << std::endl;

  Point p2{20.00, 30.00, 30.00};
  p2.create_origin_obj({1, 1});
  std::cout << p2.get_info();
  std::cout << "distance from origin is: " << p2.get_distance_from_origin()
            << std::endl;

  std::cout << "\n----------- inheritance  -----------" << std::endl;

  Engineer e1("12345", 27, "hosein", "programmer");

  std::cout << e1;

  // Engineer e2(e1);

  // std::cout << e2;

  std::cout << "\n----------- polymorphism  -----------" << std::endl;

  // virtualizing or dynamic binding or polymorphism approximately adds 8 byte
  // of size to object

  Person per1("12312331", 44, "john");
  // Engineer e3("123451231", 30, "jack", "architect");

  p_work(&per1);
  p_work(&e1);
  p_work(per1);
  p_work(e1);

  // e3.work(20); // will not work because work overload became hidden
  // e1.work(8.8);

  Person *p_arr[]{&per1, &e1};
  fmt::print(fg(fmt::color::blue),
             "\nInside for of person polymorphic objects: ( \n");
  for (auto &i : p_arr) {
    fmt::print(fg(fmt::color::blue),
               "\n\nInside for of person polymorphic objects:\n");
    i->work();  // always using the person class default argument in Engineer
                // body
    i->work(8); // works!
    // i->work("param!!");// not works because this overload is only available
    // in engineer polymorphism level

    i->work(
        10.9); // instead this one will be implicitly converted to int version
  }
  fmt::print(fg(fmt::color::blue), "\n) \n");

  std::unique_ptr<Person> p_per_e{
      std::make_unique<Engineer>("012013", 25, "jack22", "Teacher")};

  Person *p_ptr{new Engineer("012013", 45, "michael", "worker")};

  /*
    dynamic cast is for casting base class to derived class to that we can
    access to non polymorphic methods as well
    dynamic cast ONLY works with references and pointers
    (pointers are recommended)
   */
  auto en_ptr{dynamic_cast<Engineer *>(p_ptr)};
  if (en_ptr) {
    fmt::print(fg(fmt::color::green), "dynamic cast en_ptr->get_field(): {} \n",
               en_ptr->get_field());
  } else {
    fmt::print(fg(fmt::color::green),
               "dynamic cast failed from Person* to Engineer* \n");
  }

  fmt::print(fg(fmt::color::blue), "sizeof(per1): {}\n",
             sizeof(per1)); // dynamic => 56 static => 48
  fmt::print(fg(fmt::color::blue), "sizeof(e3): {}\n",
             sizeof(e1)); // dynamic => 72 static => 64

  fmt::print(fg(fmt::color::blue_violet), "Person::m_count: {}\n",
             Person::m_count);
  fmt::print(fg(fmt::color::blue_violet), "Engineer::m_count: {}\n",
             Engineer::m_count);

  /*
    because they are introduced in c++11 for backward compatibility they are not
    keywords! but not recommended to use them as names!
   */
  double final{22.33};
  std::string override{"override"};
  fmt::print(fg(fmt::color::chocolate), "final: {}, override: {},\n", final,
             override);

  std::cout << "\n----------- ending -----------" << std::endl;

  delete p_ptr;
  delete en_ptr;
  delete p_c3;
  p_c3 = nullptr;
}

void class_param(Cylinder a) {
  std::cout << "Inside class_param(Cylinder a)" << a;
}

bool comparePersonAges(const Person &p1, const Person &p2) {
  return p1.get_age() > p2.get_age();
}

void print_cylinder_private(const Cylinder &c) {
  std::cout << "c.m_base_radius : " << c.m_base_radius
            << " c.m_height: " << c.m_height << " c.m_name: " << c.m_name
            << std::endl;
}

void p_work(Person *const p) {
  fmt::print(fg(fmt::color::blue), "inside p_work(Person *const p) : ");
  p->work();
}

void p_work(const Person &p) {
  fmt::print(fg(fmt::color::blue), "inside p_work(const Person &p) : ");

  p.work();
}

} // namespace Oop
