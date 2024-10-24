#ifndef CLASS_H
#define CLASS_H
#include "cylinder.h"
#include "person.h"

namespace Oop {

void class_func();

void class_param(Cylinder a);

bool comparePersonAges(const Person &p1, const Person &p2);

void print_cylinder_private(const Cylinder &c);
} // namespace Oop

#endif