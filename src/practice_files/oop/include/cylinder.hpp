#ifndef CYLINDER_HPP
#define CYLINDER_HPP
#include <string>
#include <string_view>

namespace Oop {

class Cylinder {
  friend void print_cylinder_private(const Cylinder &c);

  // private:
  std::string_view *m_name{};
  double *m_base_radius{};
  double *m_height{};

  void invalidate();

public:
  static inline size_t m_cylinder_alive_count{};
  static inline const std::string_view CLASS_STRING{"Cylinder"};

  const int WEIRD_CONST;

  Cylinder() /*  = default */; // with =default you can not implement it and
                               // with =delete you can not use that constructor
                               // e.g. copy constructor
  explicit Cylinder(std::string_view name_param, const double &radius_param,
                    const double &height_param = 10);
  Cylinder(const Cylinder &c);           // copy constructor
  Cylinder(Cylinder &&c) /* = delete */; // move constructor
  ~Cylinder();

  double get_height() const;
  double get_base_radius() const;
  std::string_view get_name() const;

  Cylinder *set_height(const double &height_p);
  Cylinder *set_base_radius(const double &base_radius_p);
  Cylinder *set_name(std::string_view name_param);

  double get_vol();

  friend std::ostream &operator<<(std::ostream &os, const Cylinder &c);
};

} // namespace Oop

#endif