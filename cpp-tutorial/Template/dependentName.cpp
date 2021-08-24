#include <iostream>

template <typename T>
class MyTempClass {
 public:
  typedef T TempType;  // dependent name(type)
};

int main() {
  MyTempClass<int> a;
  MyTempClass<int>::TempType b;
  MyTempClass<double> c;
  MyTempClass<double>::TempType d;
}
