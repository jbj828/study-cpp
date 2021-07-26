#include <iostream>
#include <string>

int main() {
  std::string s = "abc";
  std::string t = "def";
  std::string s2 = s;

  std::cout << s << s.length() << std::endl;
  std::cout << s + t << std::endl;

  if (s == s2) {
    std::cout << "s s2 equal" << std::endl;
  }

  if (s != t) {
    std::cout << "s t not equal" << std::endl;
  }
  return 0;
}