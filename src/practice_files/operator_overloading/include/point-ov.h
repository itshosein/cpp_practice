#ifndef POINT_OP_OV_H
#define POINT_OP_OV_H

namespace OpOverload {

class Point {
  friend Point operator*(const Point &left, const Point &right);

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