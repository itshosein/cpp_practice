#include <iostream>

void pointer() {

  int var{87};
  int var1{1};
  char chr_test{'m'};
  // int *ptr_var{nullptr};
  int *ptr_int{&var};
  char *ptr_chr{&chr_test};

  double *test{nullptr};
  // *test = 10.22; // error!

  *ptr_int = 88;

  *ptr_chr = '7';

  std::cout << "ptr_var: " << ptr_int << std::endl;
  std::cout << "*ptr_var: " << *ptr_int << std::endl;

  const char *name{"hossein"};
  std::cout << "name: " << name << std::endl;
  std::cout << "*name: " << *name << std::endl;

  char char_arr[]{'h', 'o', 's', 'e', 'i', 'n' /* ,'\0' */};
  char *ptr_char_arr{&char_arr[0]};
  std::cout << "char_arr: " << char_arr << std::endl;
  std::cout << "ptr_char_arr: " << name << std::endl;
  std::cout << "*ptr_char_arr: " << *name << std::endl;

  const char *string_arr[]{"hossein", "mohsen", "marzieh"};
  std::cout << "string_arr: " << std::size(string_arr) << std::endl;
  std::cout << "*string_arr: " << *string_arr << std::endl;

  const int *ptr_to_const{&var};

  // *ptr_to_const = 33;

  int *const const_ptr{&var};
  *const_ptr = 87;
  // const_ptr = &var1;

  const int *const const_ptr_to_const{&var1};
  // *const_ptr_to_const = 33;
  // const_ptr_to_const = &var;

  int int_arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *p_int_arr{int_arr};

  std::cout << "int_arr: " << int_arr << std::endl;
  std::cout << "p_int_arr: " << p_int_arr << std::endl;
  // std::cout << "&int_arr: " << &int_arr << std::endl; // same

  std::cout << "*int_arr: " << *int_arr << std::endl;
  std::cout << "int_arr[0]: " << int_arr[0] << std::endl;
  std::cout << "*p_int_arr: " << *p_int_arr << std::endl;
  std::cout << "p_int_arr[0]: " << p_int_arr[0] << std::endl;
  // std::cout << "*int_arr[1]: " << *int_arr[1] << std::endl;

  // swapping two array data
  int number1[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  int number2[]{10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

  // int *const temp{number1};
  int *p_number1{number2};
  int *p_number2{number1};

  // size_t p_count_number1{std::size(number2)};
  // size_t p_count_number2{std::size(number1)};

  // std::cout << std::endl << "------------------------" << std::endl;
  // std::cout << "p_number1: ";
  // for (size_t i = 0; i < p_count_number1; i++) {
  //   std::cout << p_number1[i] << ", "; // *(p_number1 + i)
  // }
  // std::cout << std::endl;

  // std::cout << "p_number2: ";
  // for (size_t i = 0; i < p_count_number2; i++) {
  //   std::cout << p_number2[i] << ", "; //*(p_number2 + i)
  // }
  // std::cout << std::endl << "------------------------" << std::endl;

  // pointer athematic

  p_number1 = number1;

  // for (size_t i = 0; i < std::size(number1); i++) {
  //   std::cout << "value in [" << i << "] is: " << *(p_number1 + i)
  //             << std::endl; // p_number[i] or *(number1 + 1)
  // }
  // std::cout << std::endl << "------------------------" << std::endl;

  // for (size_t i = std::size(number1); i > 0; i--) {
  //   std::cout << "value in [" << i << "] is: "
  //             << *(p_number1 + i - 1) // p_number[i] or *(number1 + i - 1)
  //             << std::endl;
  // }

  // std::cout << std::endl << "------------------------" << std::endl;
  // p_number1 = number1 + std::size(number1) - 1;

  // for (size_t i = std::size(number1); i > 0; i--) {
  //   std::cout << "value in [" << i << "] is: " << *(p_number1--) <<
  //   std::endl;
  // }

  int number[]{15, 45, 45, 78, 9, 7, 4, 6, 2, 1};

  int *p_number1_diff{number + 1}; // {&number[1]}
  int *p_number2_diff{number + 8}; // {&number[8]}

  std::ptrdiff_t pos_diff{p_number2_diff - p_number1_diff};
  std::ptrdiff_t neg_diff{p_number1_diff - p_number2_diff};
  std::cout << "pos_diff: " << pos_diff << std::endl;
  std::cout << "p_number1_diff < p_number2_diff: "
            << (p_number1_diff < p_number2_diff) << std::endl;

  std::cout << "sizeof(ptrdiff_t): " << sizeof(ptrdiff_t) << std::endl;

  int *bad_pointer;
  // *bad_pointer = 33; // runtime disaster
  int *bad_pointer1{};
  // *bad_pointer1 = 22; // runtime disaster

  int *dynamic_int{nullptr};
  // dynamic_int = new int{55};

  std::cout << "dynamic_int: " << dynamic_int << std::endl;
  if (dynamic_int != nullptr) {
    std::cout << "*dynamic_int: " << *dynamic_int << std::endl;
    std::cout << "deleting dynamic_int: " << std::endl;
    delete dynamic_int;
    dynamic_int = nullptr;
  }

  std::cout << "dynamic_int == nullptr: " << (dynamic_int == nullptr)
            << std::endl;

  try {
    int *overflow_arr{new int[1'000'0000'000'000]}; // new fails
    if (overflow_arr) {
      delete overflow_arr;
      overflow_arr = nullptr;
    }
  } catch (const std::exception &ex) {
    std::cerr << ex.what() << std::endl;
  }

  int *overflow_arr{new (std::nothrow) int[1'000'0000'000'000]}; // new fails

  if (!overflow_arr) {
    std::cout << "overflow_arr is nullptr" << std::endl;
  } else {
    delete overflow_arr;
    overflow_arr = nullptr;
  }

  size_t dynamic_arr_size{10};
  int *arr_dynamic{new int[dynamic_arr_size]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

  // std::cout << "std::size(arr_dynamic)" << std::size(arr_dynamic) <<
  // std::endl; // compiler error

  // for (auto i : arr_dynamic) { // compiler error
  //   std::cout << "i" << i << std::endl;
  // }

  if (arr_dynamic) {
    for (size_t i{0}; i < dynamic_arr_size; i++) {
      std::cout << "*(arr_dynamic + i): " << *(arr_dynamic + i) << std::endl;
    }
    delete[] arr_dynamic;
    arr_dynamic = nullptr;
  }

  std::cout << "program ending" << std::endl;
}