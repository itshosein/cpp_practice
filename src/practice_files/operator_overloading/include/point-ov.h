#ifndef POINT_OP_OV_H
#define POINT_OP_OV_H

#include <fmt/color.h>
#include <fmt/core.h>
#include <istream>
#include <ostream>
#include <vector>

namespace OpOverload {

class Point {
  friend Point operator*(const Point &left, const Point &right);

  // if you make it member variable you have to use this: p1 <<
  // std::cout or we can make it friend
  friend std::ostream &operator<<(std::ostream &os, const Point &p);

  friend std::istream &operator>>(std::istream &is, Point &p);

  friend void operator++(Point &p);
  friend Point operator++(Point &p, int);
  friend void operator--(Point &p);
  friend Point operator--(Point &p, int);

private:
  double m_x{};
  double m_y{};

public:
  Point() = default;

  Point(double x, double y);

  void operator()() const;

  // static void operator()(); only on c++23 () with static

  ~Point();

  void print_info();

  Point operator+(const Point &p);

  Point operator-(const Point &p);
  // prefix
  // void operator++();
  // prefix
  // Point operator++(int);

  // should be member
  const double &operator[](int index) const;

  double &operator[](int index);

  Point &operator=(const Point &p);

  // Type Conversions should be member variables! no return type!
  explicit operator std::vector<double>();
};

inline std::istream &operator>>(std::istream &is, Point &p) {
  fmt::print(fg(fmt::color::green), "Enter the point with order [x,y]:\n");
  double x{};
  double y{};

  is >> x >> y;

  p.m_x = x;
  p.m_y = y;

  return is;
}
} // namespace OpOverload

#endif