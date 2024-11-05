#include <string_view>
enum class Month : unsigned char /* default is int */ {
  Jan = 1,
  January = Jan,
  Feb,
  February = Feb,
  Mar,
  March = Mar,
  Apr,
  April = Apr,
  May,
  Jun,
  Jul,
  July = Jul,
  Aug,
  August = Aug,
  Sep,
  September = Sep,
  Oct,
  October = Oct,
  Nov,
  November = Nov,
  Dec,
  December = Dec
};

void enum_func();

std::string_view month_to_str(Month m);