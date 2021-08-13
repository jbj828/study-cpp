#include <iostream>
#include <string>

template <typename T>
T max(T& a, T& b) {
  return a > b ? a : b;
}

int main() {
  int a = 1, b = 2;
  std::cout << "Max (" << a << " , " << b << " : " << max(a, b) << std::endl;

  std::string s = "hello", t = "worldssss";
  std::cout << "Max (" << s << " , " << t << " : " << max(s, t) << std::endl;
}

// template <typename Cont>
// void bubble_sort(Cont& cont) {
//   for (int i = 0; i < cont.size(); i++) {
//     for (int j = i; j < cont.size(); j++) {
//       if (cont[i] > cont[j]) {
//         cont.swap(i, j);
//       }
//     }
//   }
// }

template <typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp) {
  for (int i = 0; i < cont.size(); i++) {
    for (int j = i + 1; j < cont.size(); j++) {
      if (!comp(cont[i], cont[j])) {
        cont.swap(i, j);
      }
    }
  }
}

struct Comp1 {
  bool operator()(int a, int b) { return a > b; }
};

struct Comp2 {
  bool operator()(int a, int b) { return a < b; }
};

template <typename T, int num>
T add_num(T t) {
  return t + num;
}

int main() {
  int x = 3;
  std::cout << "x : " << add_num<int, 5>(x) << std::endl;
}