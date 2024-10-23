#if !defined(ITEM_H)
#define ITEM_H

#include <fmt/color.h>
#include <fmt/core.h>
#include <ostream>

namespace ThreeWayOp {
class Item {

  friend std::ostream &operator<<(std::ostream &os, const Item &p);

private:
  int m_a{1};
  int m_b{2};
  int m_c{3};

public:
  Item() = default;

  Item(int num);

  Item(int num1, int num2, int num3);

  ~Item();

  /**
   * default of three way comparision (spaceship) will do three way as member
   * wise and produce == and and then !=
   * <,<= ,>,>= ,these two for defaulting ==, !=
   * @returns std::strong_ordering (int or double) or std::weak_ordering
   * (std::string) or partial_ordering (nan with double)
   */
  auto operator<=>(const Item &p) const = default;
};

inline std::ostream &operator<<(std::ostream &os, const Item &p) {
  os << fmt::format(fg(fmt::color::cyan), "Item: [{}, {} ,{}]\n", p.m_a, p.m_b,
                    p.m_c);

  return os;
}

} // namespace ThreeWayOp
#endif // ITEM_H
