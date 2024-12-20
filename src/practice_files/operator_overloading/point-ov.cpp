#include "point-ov.hpp"
#include <cassert>
#include <cmath>
#include <vector>

namespace OpOverload {

Point::Point(double x, double y)
    : m_x{x}, m_y{y}, m_distance{sqrt(pow((m_x - 0), 2) + pow((m_y - 0), 2))} {
  fmt::print(fg(fmt::color::blue), "Constructed Point: [ {}, {} ]\n", this->m_x,
             this->m_y);
}

void Point::operator()() const {
  fmt::print(fg(fmt::color::blue), "hello from operator (): {}, {}, {}\n",
             this->m_x, this->m_y, this->m_distance);
}

// void Point::operator()() {
//   fmt::print(fg(fmt::color::blue), "hello from static operator ():\n");
// }

Point::~Point() {
  fmt::print(fg(fmt::color::orange), "Destructed Point: [ {}, {} ,{} ]\n",
             this->m_x, this->m_y, this->m_distance);
}

void Point::print_info() {
  fmt::print(fg(fmt::color::cyan), "Point: [ {}, {}, {} ]\n", this->m_x,
             this->m_y, this->m_distance);
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
                    "Point with << [ {:.3f} , {:.3f}, {:.5f} ] \n", p.m_x,
                    p.m_y, p.m_distance);
  return os;
}

Point &Point::operator=(const Point &p) {
  fmt::print(fg(fmt::color::blue), "inside copy assignment!\n");

  if (this != &p) {
    m_x = p.m_x;
    m_y = p.m_y;
  }
  return *this;
}

Point::operator std::vector<double>() {
  return std::vector<double>{this->m_x, this->m_y};
}

void operator++(Point &p) {
  p.m_x++;
  p.m_y++;
}

Point operator++(Point &p, int) {
  Point tmp{p};
  ++p;
  return tmp;
}

void operator--(Point &p) {
  p.m_x--;
  p.m_y--;
}

Point operator--(Point &p, int) {
  Point tmp{p};
  --p;
  return tmp;
}

} // namespace OpOverload
