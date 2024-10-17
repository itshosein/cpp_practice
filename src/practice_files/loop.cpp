#include <iostream>

void loop() {
  constexpr short loopCount{10};

  for (size_t i{0}, j{5}, k{10}; (i < loopCount) && (j <= loopCount * 2);
       i++, j += 5, k += 10) {
    std::cout << "i: " << i << " j: " << j << " k: " << k << std::endl;
  }

  int int_collection[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

  // for (size_t i{0}; i < 9; i++) {
  //   std::cout << "value in collection: " << int_collection[i] << std::endl;
  // }

  for (unsigned short multiplier{2}; auto value : int_collection) {
    std::cout << "value in collection: " << value * multiplier << std::endl;
  }
}