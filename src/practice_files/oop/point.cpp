#include "point.h"
#include <format>
#include <math.h>

const Point Point::ORIGIN{Point{0, 0, 0}};

Point::Point(const std::initializer_list<double> &list)
    : m_p_origin_obj{nullptr}, m_x{*(list.begin())}, m_y{*(list.begin() + 1)},
      m_z{*(list.begin() + 2)} {
  Point::set_number_point(Point::number_of_point + 1);
}

Point::Point(const Point &p) : Point{p.m_x, m_y, m_z} {
  if (p.m_p_origin_obj) {
    this->create_origin_obj(
        {p.m_p_origin_obj->m_x, p.m_p_origin_obj->m_y, p.m_p_origin_obj->m_z});
  }
}

Point::Point(Point &&p)
    : m_p_origin_obj{p.m_p_origin_obj}, m_x{p.m_x}, m_y{p.m_y}, m_z{p.m_z} {
  Point::set_number_point(Point::number_of_point + 1);
  p.m_p_origin_obj = nullptr;
}

Point::~Point() {
  delete m_p_origin_obj;
  Point::set_number_point(Point::number_of_point - 1);
}

void Point::set_number_point(size_t num) { number_of_point = num; }

void Point::create_origin_obj(const std::initializer_list<double> &list) {
  this->m_p_origin_obj = new Point(list);
}

double Point::get_distance_from_origin() {

  double x_difference{
      this->m_x - (m_p_origin_obj ? m_p_origin_obj->m_x : Point::ORIGIN.m_x)};
  double y_difference{
      this->m_y - (m_p_origin_obj ? m_p_origin_obj->m_y : Point::ORIGIN.m_y)};
  return sqrt(pow(x_difference, 2) + pow(y_difference, 2));
}

std::string Point::get_info() {
  std::string res{
      std::format("Point[add: {}]: [{},{},{}, origin[add:{}]",
                  reinterpret_cast<uintptr_t>(this), m_x, m_y, m_z,
                  reinterpret_cast<uintptr_t>(this->m_p_origin_obj))};
  if (this->m_p_origin_obj) {
    res += std::format(
        ": [{},{},{}, no_inner_origin:{}] ]", this->m_p_origin_obj->m_x,
        this->m_p_origin_obj->m_y, this->m_p_origin_obj->m_z,
        reinterpret_cast<uintptr_t>(this->m_p_origin_obj->m_p_origin_obj));
  } else {
    res += " ]";
  }
  res += "\n";

  return res;
}