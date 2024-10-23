#include "item.h"

namespace ThreeWayOp {
Item::Item(int num1, int num2, int num3) : m_a(num1), m_b(num2), m_c(num3) {}

Item::Item(int num) : Item::Item(num, num, num) {}

Item::~Item() {}

} // namespace ThreeWayOp
