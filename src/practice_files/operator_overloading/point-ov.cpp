#include "point-ov.h"
#include <cassert>
#include <vector>

namespace OpOverload {

Point::Point(double x, double y) : m_x{x}, m_y{y} {
  fmt::print(fg(fmt::color::blue), "Constructed Point: [ {}, {} ]\n", this->m_x,
             this->m_y);
}

Point::~Point() {
  fmt::print(fg(fmt::color::orange), "Destructed Point: [ {}, {} ]\n",
             this->m_x, this->m_y);
}

void Point::print_info() {
  fmt::print(fg(fmt::color::cyan), "Point: [ {}, {} ]\n", this->m_x, this->m_y);
}

Point Point::operator+(const Point &p) {
  return Point(this->m_x + p.m_x, this->m_y + p.m_y);
}

Point Point::operator-(const Point &p) {
  return Point(this->m_x - p.m_x, this->m_y - p.m_y);
}

double &Point::operator[](int index) { // must be member variable
  assert(index == 0 || index == 1);
  return index == 0 ? m_x : m_y;
}

const double &Point::operator[](int index) const {
  return this->operator[](index);
}

Point operator*(const Point &left, const Point &right) {
  return Point(left.m_x * right.m_x, left.m_y * right.m_y);
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << fmt::format(fg(fmt::color::cyan),
                    "Point with << [ {:.3f} , {:.3f} ] \n", p.m_x, p.m_y);
  return os;
}

Point::operator std::vector<double>() {
  return std::vector<double>{this->m_x, this->m_y};
}

} // namespace OpOverload
