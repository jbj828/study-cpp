#include <iostream>
#include <sstream>
#include <string>

// int main() {
//   std::istringstream ss("123");
//   int x;
//   ss >> x;

//   std::cout << x << std::endl;
// }

// double to_number(std::string s) {
//   std::istringstream ss(s);
//   double x;

//   ss >> x;
//   return x;
// }

std::string to_str(int num) {
  std::ostringstream ss;
  ss << num;
  return ss.str();
}
int main() { std::cout << to_str(1 + 2) << std::endl; }