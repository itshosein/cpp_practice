#include <iomanip>
#include <iostream>

void coutManip() {

  std::cout << std::left;
  std::cout << std::setfill('-');
  std::cout << std::setw(12) << "FirstName" << std::setw(20) << "LastName"
            << std::setw(5) << "Age" << std::endl;
  std::cout << std::setw(12) << "Hossein" << std::setw(20) << "Fathi"
            << std::setw(5) << "27" << std::endl;
  std::cout << std::setw(12) << "Marziyeh" << std::setw(20) << "Fathi"
            << std::setw(5) << "27" << std::endl;
  std::cout << std::setw(12) << "Hossein" << std::setw(20) << "Fathi"
            << std::setw(5) << "27" << std::endl;
  std::cout << std::setw(12) << "Marziyeh" << std::setw(20) << "Fathi"
            << std::setw(5) << "27" << std::endl;
  std::cout << std::setw(12) << "Hossein" << std::setw(20) << "Fathi"
            << std::setw(5) << "27" << std::endl;
  std::cout << std::setw(12) << "Marziyeh" << std::setw(20) << "Fathi"
            << std::setw(5) << "27" << std::endl;

  // std::dec
  // std::hex
  // std::uppercase
  // std::nouppercase
  // std::showbase 0x/0
  // std::noshowbase
  // std::showpos +
  // std::noshowpos
  // std::showpoint 2.0/2
  // std::noshowpoint
  // std::setprecision(20);
}