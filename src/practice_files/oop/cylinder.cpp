#include "cylinder.hpp"
#include "constants.hpp"
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>

namespace Oop {

void Cylinder::invalidate() {
  m_name = nullptr;
  m_base_radius = nullptr;
  m_height = nullptr;
}

Cylinder::Cylinder(const Cylinder &c) // copy constructor
    : Cylinder(c.get_name(), c.get_base_radius(), c.get_height()) {
  // this->print_info("Copied");
}

// move the temp to this obj then empty the temp pointers!
Cylinder::Cylinder(Cylinder &&c)
    : m_base_radius{c.m_base_radius}, m_height{c.m_height}, m_name{c.m_name},
      WEIRD_CONST{100} {
  c.invalidate(); // important because for temp the deconstructor will be
                  // called!
  // this->print_info("move constructor");
}

Cylinder::Cylinder() : Cylinder("CylinderDefault", 1, 1) {}

Cylinder::Cylinder(std::string_view name_param, const double &radius_param,
                   const double &height_param)
    : m_base_radius{new double{radius_param}},
      m_height{new double{height_param}},
      m_name{new std::string_view{name_param}}, WEIRD_CONST{100} {
  ++m_cylinder_alive_count;
}

Cylinder::~Cylinder() {

  // std::cout << std::format("!object Deconstructed with name[{}] {} at {}!",
  //                          reinterpret_cast<uintptr_t>(this->m_name),
  //                          this->get_name(),
  //                          reinterpret_cast<uintptr_t>(this))
  //           << std::endl;
  delete m_base_radius;
  delete m_height;
  delete m_name;
  --m_cylinder_alive_count;
}

double Cylinder::get_height() const { return m_height ? *m_height : 0; }
double Cylinder::get_base_radius() const {
  return m_base_radius ? *m_base_radius : 0;
}
std::string_view Cylinder::get_name() const {
  return m_name ? *m_name : "no_name";
};

Cylinder *Cylinder::set_height(const double &height_p) {
  *m_base_radius = height_p;
  return this;
}
Cylinder *Cylinder::set_base_radius(const double &base_radius_p) {
  *m_base_radius = base_radius_p;
  return this;
}
Cylinder *Cylinder::set_name(std::string_view name_param) {
  *m_name = name_param;
  return this;
}

double Cylinder::get_vol() {
  return PI * get_base_radius() * get_base_radius() * get_height();
}

std::ostream &operator<<(std::ostream &os, const Cylinder &c) {
  os << fmt::format(fg(fmt::color::aqua),
                    "Cylinder [{}] with name[{}] {} and height of {} and "
                    "base_radius of {}.\n",
                    reinterpret_cast<uintptr_t>(&c),
                    reinterpret_cast<uintptr_t>(c.m_name), c.get_name(),
                    c.get_height(), c.get_base_radius());
  return os; // Return the output stream
}
} // namespace Oop

// ClassName::Method => scope resolution

// class and struct are same just
// structs are public by default and is better to use for class without methods!
// class members are private by default

// size_t Cylinder::m_cylinder_alive_count{};
// const std::string_view Cylinder::class_string{"Cylinder"};
