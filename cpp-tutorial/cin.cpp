#include <iostream>
#include <string>

// int main() {
//   int t;
//   while (true) {
//     std::cin >> t;
//     std::cout << "Input :: " << t << std::endl;
//     if (std::cin.fail()) {
//       std::cout << "Please write number" << std::endl;
//       std::cin.clear();
//       std::cin.ignore(100, '\n');
//     }
//     if (t == 1) break;
//   }
// }

// int main() {
//   int t;
//   while (true) {
//     std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
//     std::cin >> t;
//     std::cout << "Input :: " << t << std::endl;
//     if (std::cin.fail()) {
//       std::cout << "Please write number only" << std::endl;
//       std::cin.clear();
//       std::cin.ignore(100, '\n');
//     }
//     if (t == 0) break;
//   }
// }

int main() {
  std::string s;
  std::cin >> s;

  char peek = std::cin.rdbuf()->snextc();
  if (std::cin.fail()) std::cout << "Failed";
  std::cout << "the first alphabet of secondary word: " << peek << std::endl;
  std::cin >> s;
  std::cout << "Reread again: " << s << std::endl;
}