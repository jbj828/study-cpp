#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T myadd(T x, T y) {
  return x + y;
}

int main() {
  cout << myadd(4, 6) << endl;
  cout << myadd(1.6, 1.8) << endl;

  string b2 = "Hello,";
  string b3 = " world";
  cout << myadd(b2, b3) << endl;
}
