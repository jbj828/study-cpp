#include <iostream>

class Animal {
 public:
  Animal() {}
  virtual ~Animal() {}
  virtual void speak() = 0;
};

class Dog : public Animal {
 public:
  Dog() : Animal() {}
  void speak() override { std::cout << "dogdog" << std::endl; }
};

class Cat : public Animal {
 public:
  Cat() : Animal() {}
  void speak() override { std::cout << "catcat" << std::endl; }
};

int main() {
  Animal* dog = new Dog();
  Animal* cat = new Cat();

  dog->speak();
  cat->speak();

  //   Animal a; // 순수가상함수가 하나라도 포함된 추상클래스는 그 자체로는
  //   인스턴스화 시킬 수 없다(추상 클래스의 객체를 만들 수 없다.)
}