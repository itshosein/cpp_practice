#include "exercise.h"
#include <format>
#include <iostream>
#include <unordered_map>
#include <vector>

void exercise() {
  // const int array[]{1, 2, 3, 4, 0, 424, 24132, 42, 0, 232, 7, 3213, 23, 4};

  // bool spy_found = spy_game(array, std::size(array));

  // std::cout << "spy result is: " << std::boolalpha << spy_found << std::endl;

  // size_t top{201000};
  // size_t result{count_primes(top)};
  // std::cout << std::format("primes until {} are {}", top, result) <<
  // std::endl;
  print_big("my wife and i will leave iran and will");
}

/**
 * SPY GAME: Write a function that takes in a list of integers and returns
 * True if it contains 007 in order
 *
 * */
bool spy_game(const int *p_arr, size_t size) {
  constexpr char target[]{0, 0, 7};
  const char *p_target{&target[0]};
  for (size_t i{}; i < size; i++) {
    std::cout << "in for:p_arr[i]: " << p_arr[i] << " *p_target:" << *p_target
              << std::endl;
    if (p_arr[i] == *p_target) {
      if (*p_target == 7) {
        return true;
      } else {
        p_target = ++p_target;
      }
    }
  }
  return false;
}

/**
 * COUNT PRIMES: Write a function that returns the number of prime numbers that
exist up to and including a given number count_primes(100) --> 25
 *  */
size_t count_primes(size_t top) {
  size_t res{};
  for (size_t i{2}; i <= top; i++) {
    for (size_t j{2}; j <= i; j++) {
      if (!(i % j)) {
        if (i != j) {
          break;
        }
        res += 1;
      }
    }
  }

  return res;
}

/**
 * PRINT BIG: Write a function that takes in a single letter, and returns a 5x5
representation of that letter print_big('a')
 */
void print_big(std::string_view letters) {
  std::string res{"\n\n\n\n\n"};
  const std::unordered_map<unsigned char, std::vector<std::vector<bool>>>
      myObject{{'3',
                {{0, 1, 0, 1, 0},
                 {1, 0, 1, 0, 1},
                 {1, 0, 0, 0, 1},
                 {0, 1, 0, 1, 0},
                 {0, 0, 1, 0, 0}}},
               {'A',
                {{0, 0, 1, 0, 0},
                 {0, 1, 0, 1, 0},
                 {1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1}}},
               {'B',
                {{1, 1, 1, 0, 0},
                 {1, 0, 0, 1, 0},
                 {1, 1, 1, 0, 0},
                 {1, 0, 0, 1, 0},
                 {1, 1, 1, 0, 0}}},
               {'C',
                {{0, 0, 1, 1, 1},
                 {0, 1, 0, 0, 0},
                 {0, 1, 0, 0, 0},
                 {0, 1, 0, 0, 0},
                 {0, 0, 1, 1, 1}}},
               {'D',
                {{1, 1, 1, 0, 0},
                 {1, 0, 0, 1, 0},
                 {1, 0, 0, 1, 0},
                 {1, 0, 0, 1, 0},
                 {1, 1, 1, 0, 0}}},
               {'E',
                {{1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0},
                 {1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0},
                 {1, 1, 1, 1, 0}}},
               {'F',
                {{1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0},
                 {1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0}}},
               {'G',
                {{0, 1, 1, 1, 1},
                 {1, 0, 0, 0, 0},
                 {1, 0, 1, 1, 1},
                 {1, 0, 0, 0, 1},
                 {0, 1, 1, 1, 1}}},
               {'H',
                {{1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1}}},
               {'I',
                {{0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0}}},
               {'J',
                {{0, 1, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 1, 1, 0, 0}}},
               {'K',
                {{1, 0, 0, 0, 1},
                 {1, 0, 0, 1, 0},
                 {1, 1, 1, 0, 0},
                 {1, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1}}},
               {'L',
                {{1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1}}},
               {'M',
                {{1, 0, 0, 0, 1},
                 {1, 1, 0, 1, 1},
                 {1, 0, 1, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1}}},
               {'N',
                {{1, 0, 0, 0, 1},
                 {1, 1, 0, 0, 1},
                 {1, 0, 1, 0, 1},
                 {1, 0, 0, 1, 1},
                 {1, 0, 0, 0, 1}}},
               {'O',
                {{0, 1, 1, 1, 0},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {0, 1, 1, 1, 0}}},
               {'P',
                {{1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 1},
                 {1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0}}},
               {'Q',
                {{0, 1, 1, 1, 0},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {0, 1, 1, 1, 0},
                 {0, 0, 0, 0, 1}}},
               {'R',
                {{1, 1, 1, 1, 0},
                 {1, 0, 0, 1, 0},
                 {1, 1, 1, 1, 0},
                 {1, 1, 0, 0, 0},
                 {1, 0, 1, 1, 0}}},
               {'T',
                {{1, 1, 1, 1, 1},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0}}},
               {'U',
                {{1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {0, 1, 1, 1, 0}}},
               {'V',
                {{1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {0, 1, 0, 1, 0},
                 {0, 0, 1, 0, 0}}},
               {'W',
                {{1, 0, 0, 0, 1},
                 {1, 0, 1, 0, 1},
                 {1, 0, 1, 0, 1},
                 {1, 1, 0, 1, 1},
                 {1, 0, 0, 0, 1}}},
               {'X',
                {{1, 0, 0, 0, 1},
                 {0, 1, 0, 1, 0},
                 {0, 0, 1, 0, 0},
                 {0, 1, 0, 1, 0},
                 {1, 0, 0, 0, 1}}},
               {'Y',
                {{1, 0, 0, 0, 1},
                 {0, 1, 0, 1, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0}}},
               {'Z',
                {{1, 1, 1, 1, 1},
                 {0, 0, 0, 1, 0},
                 {0, 0, 1, 0, 0},
                 {0, 1, 0, 0, 0},
                 {1, 1, 1, 1, 1}}},
               {'(',
                {{0, 0, 1, 0, 0},
                 {0, 1, 0, 0, 0},
                 {0, 1, 0, 0, 0},
                 {0, 1, 0, 0, 0},
                 {0, 0, 1, 0, 0}}},
               {')',
                {{0, 0, 1, 0, 0},
                 {0, 0, 0, 1, 0},
                 {0, 0, 0, 1, 0},
                 {0, 0, 0, 1, 0},
                 {0, 0, 1, 0, 0}}},
               {' ', {{0}, {0}, {0}, {0}, {0}}}};
  size_t insert_positions{0};
  for (const auto &letter : letters) {
    insert_positions = res.find('\n', 0);
    if (auto search = myObject.find(std::toupper(letter));
        search != myObject.end()) {

      for (const auto &vec : search->second) {
        for (const bool value : vec) {
          if (value) {
            res.insert(insert_positions, 1, '*');
          } else {
            res.insert(insert_positions, 1, ' ');
          }
          ++insert_positions;
        }
        if (insert_positions + 1 != res.size()) {
          insert_positions = res.find('\n', ++insert_positions);
        }
      }
    } else {
      std::cerr << "Not found\n";
    }
  }

  std::cout << std::string_view{res} << std::endl;
}
