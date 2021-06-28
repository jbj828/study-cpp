#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T1, typename T2>
class cal {
 public:
  void sum(T1 x, T2 y) { cout << x + y << endl; }
  void diff(T1 x, T2 y) { cout << x - y << endl; }
};

int main() {
  cal<int, int> data;
  data.sum(1, 2);
  data.sum('a', 'b');

  cal<double, long> data2;
  data2.sum(1.2, 2);

  cal<double, double> data3;
  data3.sum(1.2, 1.5);
}
