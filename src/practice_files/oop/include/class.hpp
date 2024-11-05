#ifndef CLASS_HPP
#define CLASS_HPP
#include "cylinder.hpp"
#include "person.hpp"

namespace Oop {

void class_func();

void class_param(Cylinder a);

bool comparePersonAges(const Person &p1, const Person &p2);

void print_cylinder_private(const Cylinder &c);

void p_work(Person *const p);
void p_work(const Person &p);

} // namespace Oop

#endif