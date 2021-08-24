#include <stdio.h>

template <class T>
class X {
 public:
  void f(typename T::myType* mt) {}
};

class Yarg {
 public:
  struct myType {};
};

int main() {
  X<Yarg> x;
  x.f(new Yarg::myType());
}