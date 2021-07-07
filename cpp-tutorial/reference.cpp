#include <iostream>

int main() {
  int x;
  int& y = x;
  int& z = y;

  x = 1;
  std::cout << x << y << z << std::endl;

  y = 2;
  std::cout << x << y << z << std::endl;

  z = 3;
  std::cout << x << y << z << std::endl;
}

// int& a = 3 // X
// const int& b = 3 // O
// b = 4

// int main() {
//   int a = 3;
//   int& another_a = a;

//   another_a = 5;
//   std::cout << "a : " << a << std::endl;
//   std::cout << "another_a : " << another_a << std::endl;

//   return 0;
// }

// 레퍼런스와 포인터의 차이점
// 1. 레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정해야 한다.(레퍼런스가
// 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다.)
// 2. 레퍼런스는 메모리 상에 존재하지 않을 수 도 있다.

// int a = 10;
// int& another_a = a;

// int b = 3;
// another_a = b;  // 이건 a = b 와 같다.

// int a = 10;
// int* p = &a;

// int b = 3;
// p = &b; // p는 a를 버리고 b를 가리킨다.

// int change_val(int *p) {
//   *p = 3;

//   return 0;
// }

// int main() {
//   int number = 5;

//   std::cout << number << std::endl;
//   change_val(&number);
//   std::cout << number << std::endl;
// }