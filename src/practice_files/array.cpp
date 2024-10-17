#include <ctime>
#include <iostream>

void array() {
  const int arr[]{23, 14, 5, 135, 63, 4};

  char vowel_letters[]{'a', 'i', 'o', 'u', 'e'};

  std::cout << "arr value is: ";
  for (auto value : arr) {
    std::cout << value << ",";
  }
  std::cout << std::endl;

  std::cout << "vowel_letters value is: ";
  for (auto value : vowel_letters) {
    std::cout << value << ",";
  }
  std::cout << std::endl;

  std::cout << "size ot arr array is " << std::size(arr); // C++17
  // std::cout << "size ot arr array is " << sizeof(arr) / sizeof(arr[0]);
  size_t arrLen{std::size(arr)};
  for (size_t i = 0; i < arrLen; i++) {
    std::cout << "[" << i << "]arr value in simple for is: " << arr[i]
              << std::endl;
  }

  char message[]{'h', 'o', 's', 'e', 'i', 'n', '\0'};
  // std::cout << "message value is: ";
  // for (auto value : message) {
  //   std::cout << value;
  // }
  // std::cout << std::endl;
  std::cout << "message: " << message << std::endl;
  std::cout << "sizeof(message): " << sizeof(message) << std::endl;

  char message1[7]{'h', 'o', 's', 'e', 'i', 'n'};
  std::cout << "message1: " << message1 << std::endl;
  std::cout << "sizeof(message1): " << sizeof(message1) << std::endl;

  char message2[]{"hosein"};
  std::cout << "message2: " << message2 << std::endl;
  std::cout << "sizeof(message2): " << sizeof(message2) << std::endl;

  // message2[10000000] = 'a';
  // std::cout << "message2[10000000]: " << message2[10000000] << std::endl;

  int arr2D[3][5]{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};

  std::cout << "----------------------------------" << std::endl;

  for (size_t i = 0; i < std::size(arr2D); i++) {
    for (size_t j = 0; j < std::size(arr2D[i]); j++) {
      std::cout << "value in [" << i << " ,  " << j << "] is: " << arr2D[i][j]
                << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
  }

  constexpr unsigned short name_length{15};
  char names_2D[][name_length]{
      "hosein",
      "marzieh",
      "hassan",
  };

  for (size_t i = 0; i < std::size(names_2D); i++) {
    std::cout << "name[" << i << "] is: " << names_2D[i] << std::endl;
  }
}

int generateRandomNumber(int bottom, int upper) {
  std::srand(std::time(0));

  int random_number{(std::rand() % (upper + 1)) + bottom};

  std::cout << "random number: " << random_number << std::endl;

  return random_number;
}