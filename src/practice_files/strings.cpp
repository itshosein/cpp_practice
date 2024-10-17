#include "strings.h"
#include <cctype>
#include <format>
#include <iostream>

void strings() {

  const char *message{new const char[]{"I'm Writing 1 Sample String"}};

  size_t digit_count{}, alpha_count{}, alpha_numeric_count{}, lower_count{},
      upper_count{}, whitespace_count{};

  for (size_t i{}; i < strlen(message); ++i) {
    if (isalnum(*(message + i))) {
      alpha_numeric_count++;
    }
    if (isalpha(*(message + i))) {
      alpha_count++;
    }
    if (isdigit(*(message + i))) {
      digit_count++;
    }
    if (islower(*(message + i))) {
      lower_count++;
    } else if (isupper(*(message + i))) {
      upper_count++;
    }
    if (isspace(*(message + i))) {
      whitespace_count++;
    }
  }

  constexpr char target{'i'};
  const char *res = message;
  size_t iteration{};

  while ((res = strchr(res, target)) != nullptr) {
    ++res;
    ++iteration;
  }

  std::cout << message
            << "\nAbove message has following information:" << std::endl;
  std::cout << std::format(
      "Number of Digit: "
      "{}\nNumber of Alphabet: "
      "{}\nNumber of Alphanumeric: {}\nNumber of "
      "Lowercase characters: {}\nNumber Upper characters: "
      "{}\nNumber of Whitespaces: {}\nFound Character {} {} time",
      digit_count, alpha_count, alpha_numeric_count, lower_count, upper_count,
      whitespace_count, target, iteration);

  delete[] message;
  // delete[] res; // wrong behavior.
  message = nullptr;
  res = nullptr;

  message = new const char[]{"/home/hosein/Desktop/main.cpp"};
  char *found_slash = strrchr(message, '/');
  if (found_slash) {
    std::cout << std::format("\nThe file name is {}\n", ++found_slash);
  }
  delete[] message;
  message = nullptr;

  char dest[20]{"hello"};
  char src[20]{" world!"};

  std::strcat(dest, src);

  std::cout << std::format("After strcat dest is '{}'", dest) << std::endl;

  char *p_dest{new char[20]{"my name"}};
  const char *p_src{new const char[]{" is Hosein"}};

  std::strncat(p_dest, p_src, 3);
  std::cout << std::format("After strncat dest is '{}'", p_dest) << std::endl;

  delete[] p_dest;
  delete[] p_src;
  p_dest = nullptr;
  p_src = nullptr;

  p_dest = new char[20]{};
  p_src = new char[]{"this is from src"};
  std::strcpy(p_dest, p_src);

  std::cout << std::format("After strcpy dest is '{}'", p_dest) << std::endl;

  delete[] p_dest;
  delete[] p_src;
  p_dest = nullptr;
  p_src = nullptr;

  p_dest = new char[20]{};
  p_src = new char[]{"this is from src"};
  std::strncpy(p_dest, p_src, 8);

  std::cout << std::format("After strncpy dest is '{}'", p_dest) << std::endl;

  delete[] p_dest;
  delete[] p_src;
  p_dest = nullptr;
  p_src = nullptr;

  std::cout << "\n==================================================\n";

  // std::string {} or ()
  // (number_of_repeat, character) or (string, number_of_characters) or
  // (string, start_index, number_of_characters)
  // {string, number_of_characters} or {string,
  // start_index,number_of_characters}

  std::string name{"Hosein fathi"};
  std::string greeting{"Hello There!", 5};
  std::string job{"my job is programming"};
  std::string programming{job, 10, 11};

  std::string yell(5, 'a');

  std::cout << std::format(
                   "Name is {}\nGreeting is {}\nProgramming is {}\nYell is {}",
                   name, greeting, programming, yell)
            << std::endl;

  std::string str1{"Hello"
                   " World"};
  std::string str2{greeting + " " + name};

  std::string str3{};
  {
    using namespace std::string_literals;
    // str3 = "c-string" + " awful!"; // compiler error
    str3 = "string_literal!"s + " WOW";
  }
  // yell += 60 // will change 60 to corresponding ascii code

  yell += std::to_string(60);

  std::string str4{std::string{"appending this! =>"}.append(" with me.")};
  std::string str5{
      job.append(src)}; // works with c-string and pointer to string

  if (!message) {
    message = new const char[]{"I'm Writing 1 Sample String"};
  }

  std::string str6{name.append(message, 0, 11)};
  if (message) {
    delete[] message;
    message = nullptr;
  }

  std::cout << std::format(
      "str1: {}\nstr2: {}\nstr3: {}\nstr4: {}\nstr5: {}\nyell: {}\nstr6: {}\n",
      str1, str2, str3, str4, str5, yell, str6);

  std::cout << "str6 in normal loop:";
  for (size_t i = 0; i < str6.size(); i++) {
    std::cout << str6[i] /* str6.at(i) */ << " ";
  }
  std::cout << std::endl;

  std::cout << "str6 in range loop:";
  for (char value : str6) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  char &front = str6.front();
  char &back = str6.back();

  front = 'h';
  back = 'G';

  std::cout << "str6's front and back  are modified: " << str6 << std::endl;

  const char *c_str = str6.c_str();

  std::cout << "c_str for str6 is: " << c_str << std::endl;

  char *p_str6 = str6.data();
  p_str6[0] = 'H';

  std::cout << "str6 modified: " << str6 << std::endl;
  std::cout << "p_str6 modified: " << p_str6 << std::endl;

  std::cout << "=================== Capacity ===================\n";

  std::string str7{"Hello world"};
  std::cout << std::format("str7 has {} size but capacity is {}\n", str7.size(),
                           str7.capacity());
  str7 += " hosein";
  std::cout << std::format(
      "str7 after addition has {} size but capacity is {}\n", str7.size(),
      str7.capacity());
  str7.reserve(100);
  std::cout << std::format(
      "str7's capacity changed now has {} size but capacity is {}\n",
      str7.size(), str7.capacity());
  str7.shrink_to_fit();
  std::cout << std::format(
      "str7 has shrunken now has {} size but capacity is {}\n", str7.size(),
      str7.capacity());

  std::cout << "=================== insert ===================\n";

  std::string str8{"Im a developer"};

  str8.insert(1, 1, '\'');

  std::cout << "str8 is: " << str8 << std::endl;

  str8.insert(3, " good");

  std::cout << "str8 is: " << str8 << std::endl;

  std::string str9{"planet's should be on their good position!"};

  str8.insert(3, str9, 8, 10);

  std::cout << "str8 is: " << str8 << std::endl;

  str8.erase(19, 2);
  str8.erase(1, 2);
  str8.insert(11, " a");

  std::cout << "str8 is: " << str8 << std::endl;

  str8.push_back('!');
  str8.push_back('!');

  std::cout << "str8 is: " << str8 << std::endl;

  str8.pop_back();

  std::cout << "str8 is: " << str8 << std::endl;

  std::cout << "=================== replace ===================\n";

  std::string str10{"I love coding c++"};
  std::string str11{"debugging is the core concept"};

  str10.replace(str10.find("coding"), 6, str11, 0, 9);

  // str10.replace(0, str10.size(), str11, 0, str11.size()); copying one string
  // to another by replaces

  std::cout << "replaced str10 is: " << str10 << std::endl;

  std::cout << "=================== copy ===================\n";

  char str12[30]{};
  str11.copy(str12, 4, 17);

  std::cout << "copied str12 is: " << str12 << std::endl;

  std::cout << "=================== resize ===================\n";

  str11.resize(9);

  std::cout << "resized str11 is: " << str11 << std::endl;

  std::cout << "=================== swap ===================\n";

  str11.swap(str10);

  std::cout << "swapped str10 is: " << str10 << std::endl;
  std::cout << "swapped str11 is: " << str11 << std::endl;

  std::cout << "=================== find ===================\n";

  std::string str13{"I am going to repeat the 'to' word so the program finds "
                    "the to word position."};

  size_t pos{str13.find("to", 0)};

  if (pos == std::string::npos) {
    std::cout << "string not found!" << std::endl;
  } else {
    std::cout << "postion of 'to' is :" << pos << std::endl;
  }

  std::string str_to_find{"to"};
  size_t *p_positions{nullptr};
  size_t number_of_repetition{};

  p_positions =
      find_repeated_positions(str13, str_to_find, number_of_repetition);

  std::cout << std::format("Number of {} is {} at positions", str_to_find,
                           number_of_repetition)
            << std::endl;
  std::string str_positions{};
  for (size_t i = 0; i < number_of_repetition; i++) {
    if (p_positions[i]) {
      str_positions.append(std::to_string(p_positions[i]));
      str_positions.append(", ");
    }
  }
  std::cout << str_positions << std::endl;

  delete[] p_positions;
  p_positions = nullptr;

  std::string str14{R"----(He said "(I'm not his property)")----"};

  std::cout << str14 << std::endl;

  std::cout << "=================== string view ===================\n";

  std::string_view v_str14{
      str14}; // just a vie of string. can be c string or whatever

  std::cout << "v_str14: " << v_str14 << std::endl;

  v_str14.remove_prefix(3);
  v_str14.remove_suffix(2);

  std::cout << "v_str14: " << v_str14 << std::endl;
  std::cout << "str14: " << str14 << std::endl;
  std::cout << "v_str14: " << &v_str14 << std::endl;
  std::cout << "str14: " << &str14 << std::endl;

  std::string_view v_str15;
  {
    std::string str16{"test string"};

    v_str15 = str16;
  }
  // std::cout << "v_str14: " << v_str14
  //<< std::endl; // bad behavior! string_view and it's string should
  //  live in one scope

  str14.append("!!!");
  std::cout << "After appending v_str14: " << v_str14 << std::endl;
  std::cout << "After appending str14: " << str14 << std::endl;
  std::cout << "After appending v_str14: " << &v_str14 << std::endl;
  std::cout << "After appending str14: " << &str14 << std::endl;

  str14.insert(7, ":");

  std::cout << "After inserting v_str14: " << v_str14 << std::endl;
  std::cout << "After inserting str14: " << str14 << std::endl;
  std::cout << "After inserting v_str14: " << &v_str14 << std::endl;
  std::cout << "After inserting str14: " << &str14 << std::endl;
}

size_t *find_repeated_positions(std::string_view str,
                                std::optional<std::string_view> op_str,
                                size_t &number_of_repetition) {
  std::string_view str_to_find{op_str.value_or("")};

  size_t pos = 0;
  size_t *p_positions{nullptr};
  for (size_t i = 0; i < str.size();) {
    pos = str.find(str_to_find, i);
    if (pos == std::string::npos) {
      break;
    } else {
      ++number_of_repetition;
      i = pos + (str_to_find.size());
    }
    size_t *temp_p{p_positions};
    p_positions = new size_t[number_of_repetition]{};

    if (temp_p) {
      for (size_t j = 0; j < (number_of_repetition - 1); j++) {
        p_positions[j] = temp_p[j];
      }
      p_positions[number_of_repetition - 1] = pos;
      delete[] temp_p;
      temp_p = nullptr;
    } else {
      p_positions[number_of_repetition - 1] = pos;
    }
  }
  return p_positions;
}