#include <iostream>
#include <string>

class Base {
  std::string s;

 public:
  Base() : s("base") { std::cout << "Base class" << std::endl; }

  virtual void what() { std::cout << "base what" << std::endl; }
};

class Derived : public Base {
  std::string s;

 public:
  Derived() : s("derived"), Base() {
    std::cout << "Derived class" << std::endl;
  }

  void what() override { std::cout << "derived what" << std::endl; }
};

int main() {
  Base b;
  Derived d;

  Base* b_b = &b;
  b_b->what();
  Base* b_d = &d;
  b_d->what();
  return 0;
}