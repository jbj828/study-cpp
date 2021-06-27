#include <iostream>

#include "Hannah.h"
using namespace std;

int main() {
  Hannah a(34);
  Hannah b(21);
  Hannah c;

  c = a + b;
  cout << c.num << endl;
}