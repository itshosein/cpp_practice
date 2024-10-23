#include "item.h"

namespace ThreeWayOp {
Item::Item(const int &num1, const int &num2, const int &num3, const int &num)
    : m_a(num1), m_b(num2), m_c(num3), m_i1(num) {}

Item::Item(const int &num) : Item::Item(num, num, num, num) {}

Item::~Item() {}

InnerItem::InnerItem(const int &num) : m_innerNum1(num){};

InnerItem::~InnerItem(){};

} // namespace ThreeWayOp
