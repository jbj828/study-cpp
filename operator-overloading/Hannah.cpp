#include "Hannah.h"

#include <iostream>
using namespace std;

Hannah::Hannah() {}

Hannah::Hannah(int a) { num = a; }

Hannah Hannah::operator+(Hannah aho) {
  Hannah brandNew;
  brandNew.num = num + aho.num;
  return (brandNew);
}