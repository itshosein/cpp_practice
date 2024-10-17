#include "concepts.h"
#include <iostream>
#include <string>
#include <string_view>

// auto add(std::integral auto a, std::integral auto b) { return a + b; }

void concepts() {

  char var1{10};
  char var2{30};
  int var3{10213};
  int var4{10123123};
  double var5{101.222};
  double var6{10123.908};
  std::string var7{"test7"};
  std::string var8{"test8"};

  auto res1 = add(var1, var2);
  std::cout << "re1 : " << static_cast<int>(res1) << std::endl;

  auto res2 = add(var3, var4);
  std::cout << "res2 : " << res2 << std::endl;

  auto res3 = add(var5, var6);
  std::cout << "res3 : " << res3 << std::endl;

  // auto res3 = add<std::string_view>(var7, var8);
  // std::cout << "res3 : " << res3 << std::endl;
}

// template <typename T>
//   requires std::integral<T>
// T add(T a, T b) {
//   return a + b;
// }

template <MyIntegral R, MyIntegral T, MyIntegral U>
  requires TinyAddResult<R, T, U>
R add(T a, U b) {
  return a + b;
}

// template <typename T>
// T add(T a, T b)
//   requires std::integral<T>
// {
//   return a + b;
// }
