#include <iostream>

class Parent {
 public:
  virtual void func1();
  virtual void func2();
};

class Child : public Parent {
 public:
  virtual void func1();
  void func3();
};