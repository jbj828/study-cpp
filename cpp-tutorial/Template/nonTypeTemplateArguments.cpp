#include <array>
#include <iostream>

// int main() {
//   std::array<int, 5> arr = {1, 2, 3, 4, 5};

//   for (int i = 0; i < arr.size(); i++) {
//     std::cout << arr[i] << " ";
//   }
//   std::cout << std::endl;
// }

// void print_array(const std::array<int, 5>& arr) {
//   for (int i = 0; i < arr.size(); i++) {
//     std::cout << arr[i] << " ";
//   }
//   std::cout << std::endl;
// }

template <typename T>
void print_array(const T& arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  std::array<int, 7> arr2 = {1, 2, 3, 4, 5, 23, 3};
  std::array<int, 9> arr3 = {1, 2, 3, 4, 5, 23, 3, 3, 4};

  print_array(arr);
  print_array(arr3);
  print_array(arr2);
}