#if !defined(ITEM_HPP)
#define ITEM_HPP

#include <fmt/color.h>
#include <fmt/core.h>
#include <ostream>

namespace ThreeWayOp {
class InnerItem {
  friend std::ostream &operator<<(std::ostream &os, const InnerItem &ii);

private:
  int m_innerNum1{1};

public:
  InnerItem() = default;
  InnerItem(const int &num);
  ~InnerItem();

  auto operator<=>(const InnerItem &ii) const = default; // best way

  // bool operator==(const InnerItem &ii) const = default;
  // bool operator<(const InnerItem &ii) const = default;
};

class Item {

  friend std::ostream &operator<<(std::ostream &os, const Item &p);

private:
  int m_a{1};
  int m_b{2};
  int m_c{3};
  InnerItem m_i1;

public:
  Item() = default;

  Item(const int &num);

  Item(const int &num1, const int &num2, const int &num3, const int &num);

  ~Item();

  /**
   * three way comparision (spaceship) will do three way as member
   * wise and produce <,<= ,>,>=  because of default  == and != will be produced
   * if you create costume <=> you have to create
   * bool operator==(const Item &rhs) const;
   *  as well
   * if we have costume class as inner type either it should have <=> or <,==
   *  operators
   * @returns std::strong_ordering (int or double) or std::weak_ordering
   * (std::string) or partial_ordering (nan with double)
   */
  auto operator<=>(const Item &p) const = default;
  // std::strong_ordering operator<=>(const Item &p) const = default;
};

inline std::ostream &operator<<(std::ostream &os, const Item &p) {
  os << fmt::format(fg(fmt::color::cyan), "Item: [{}, {} ,{} ", p.m_a, p.m_b,
                    p.m_c);
  os << p.m_i1 << fmt::format(fg(fmt::color::cyan), "]\n");
  return os;
}

inline std::ostream &operator<<(std::ostream &os, const InnerItem &ii) {
  os << fmt::format(fg(fmt::color::cyan), "InnerItem: [{}] ", ii.m_innerNum1);

  return os;
}

} // namespace ThreeWayOp
#endif // ITEM_HPP
