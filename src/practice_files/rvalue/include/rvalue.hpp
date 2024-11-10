namespace Rvalue {
void rvalue_func();

int add(const int &a, const int &b);

template <class T> void swap_data_wrapper_copy(T &a, T &b);
template <class T> void swap_data_wrapper_move(T &a, T &b);
} // namespace Rvalue
