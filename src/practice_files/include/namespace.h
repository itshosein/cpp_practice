#ifndef NAMESPACE_H
#define NAMESPACE_H

double add(const double &x, const double &y);

namespace NamespaceFile {
void namespace_func();

double add(const double &x, const double &y);
} // namespace NamespaceFile

namespace { // only on tu!!
void test();
} // namespace

#endif