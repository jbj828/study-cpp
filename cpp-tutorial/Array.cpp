#include <iostream>

class Array {
  const int dim;
  int* size;

  struct Address {
    int level;
    void* next;
  };
  Address* top;

 public:
  Array(int dim, int* array_size) : dim(dim) {
    size = new int[dim];
    for (int i = 0; i < dim; i++) size[i] = array_size[i];
  }
};