/*
    STL에서 컨테이너는 크게 두 가지 종류가 있다.
    1. 시퀀스 컨테이너: 객체들을 순차적으로 보관 - vector, list, deque
    2. 연관 컨테이너(associative container) : 키를 바탕으로 대응되는 값을
   찾아준다.

    반복자: 컨테이너의 원소에 접근할 수 있는 포인터와 같은 객체
*/

#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
  for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
       ++itr) {
    std::cout << *itr << std::endl;
  }
}

int main() {
  std::vector<int> vec;

  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  print_vector(vec);
  std::cout << "-----------------------" << std::endl;

  vec.insert(vec.begin() + 2, 15);
  print_vector(vec);
  std::cout << "-----------------------" << std::endl;

  vec.erase(vec.begin() + 3);
  print_vector(vec);
}