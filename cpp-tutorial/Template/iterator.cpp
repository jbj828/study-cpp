#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
  std::cout << "[ ";
  for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
       ++itr) {
    std::cout << *itr << " ";
  }
  std::cout << "]";
}

int main() {
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);
  vec.push_back(50);

  for (std::vector<int>::const_reverse_iterator r_iter = vec.rbegin();
       r_iter != vec.rend(); r_iter++) {
    std::cout << *r_iter << std::endl;
  }
}