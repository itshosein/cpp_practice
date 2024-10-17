#include <bitset>
#include <iomanip>
#include <iostream>

constexpr unsigned short int COLUMN_WIDTH{20};

constexpr unsigned int maskRed{0XFF000000};
constexpr unsigned int maskGreen{0X00FF0000};
constexpr unsigned int maskBlue{0X0000FF00};
constexpr unsigned int maskAlpha{0X000000FF};

// for set => value |= maskBit0
// for reset  => value &= ~maskBit0
// for checking => (value & maskBit0) >> 0
// for toggling => value ^= maskBit0

void unpackColor(unsigned int color) {
  std::cout << "\n\n ----------- unpack color -----------" << std::endl;
  std::cout << std::left << std::setfill('-');

  std::cout << std::setw(COLUMN_WIDTH) << "color is: " << std::hex << color
            << std::dec << std::endl;

  std::cout << std::setw(COLUMN_WIDTH)
            << "Red is: " << ((color & maskRed) >> 24) << std::endl;

  std::cout << std::setw(COLUMN_WIDTH)
            << "Green is: " << ((color & maskGreen) >> 16) << std::endl;

  std::cout << std::setw(COLUMN_WIDTH)
            << "Blue is: " << ((color & maskBlue) >> 8) << std::endl;

  std::cout << std::setw(COLUMN_WIDTH)
            << "Alpha is: " << ((color & maskAlpha) >> 0) << std::endl;
}

void binary() {
  unsigned short int data{27};

  std::cout << "data (dec) " << std::dec << data << std::endl;
  std::cout << "data (bin) " << std::bitset<16>(data) << std::endl;

  data = static_cast<unsigned short int>(data >> 3);
  std::cout << "data (dec)size=> " << std::dec << sizeof((data >> 3)) << " :"
            << data << std::endl;
  std::cout << "data (bin) " << std::bitset<16>(data) << std::endl;

  unsigned int testColor{0xff233400};
  unpackColor(testColor);
}
