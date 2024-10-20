#ifndef POINT_OP_OV_H
#define POINT_OP_OV_H

#include <ostream>

namespace OpOverload {

class Point {
  friend Point operator*(const Point &left, const Point &right);

  // if you make it member variable (inline) you have to use this: p1 <<
  // std::cout or we can make it friend
  friend std::ostream &operator<<(std::ostream &os, const Point &p);

private:
  double m_x{};
  double m_y{};

public:
  Point() = default;

  Point(double x, double y);

  ~Point();

  void print_info();

  Point operator+(const Point &p);

  Point operator-(const Point &p);

  const double &operator[](int index) const;

  double &operator[](int index);
};
} // namespace OpOverload

#endif