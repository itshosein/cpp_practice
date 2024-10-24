#ifndef POINT_OOP_H
#define POINT_OOP_H

#include <initializer_list>
#include <string>
namespace Oop {

/**
 *  struct uses initializer list by default
 * struct properties are public by default
 *
 * */
struct Point {
private:
  double m_x{};
  double m_y{};
  double m_z{};
  // Point p; // Compiler error
  // static inline Point p; // Compiler error
  Point *m_p_origin_obj;

public:
  static const Point ORIGIN;
  static inline size_t number_of_point{};

  static void set_number_point(size_t num);

  Point(const std::initializer_list<double> &list);

  Point(const Point &p);

  Point(Point &&p);

  ~Point();

  void create_origin_obj(const std::initializer_list<double> &list);

  double get_distance_from_origin();

  std::string get_info();
};
} // namespace Oop

#endif