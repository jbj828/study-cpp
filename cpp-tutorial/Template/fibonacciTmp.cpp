#include <iostream>

template <int N>
struct fibonacci {
  static const int value = fibonacci<N - 1>::value + fibonacci<N - 2>::value;
};
template <>
struct fibonacci<1> {
  static const int value = 1;
};

template <>
struct fibonacci<2> {
  static const int value = 1;
};

int main() { std::cout << fibonacci<5>::value << std::endl; }