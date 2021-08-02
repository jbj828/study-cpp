#include <iostream>

class A {
 public:
  int a;
  A() { std::cout << "A" << std::endl; }
};

class B {
 public:
  int b;
  B() { std::cout << "B" << std::endl; }
};

class C : public A, public B {
 public:
  int c;
  C() : A(), B() { std::cout << "C" << std::endl; }
};

int main() {
  C c;
  c.a = 3;
  c.b = 2;
  c.c = 4;
}