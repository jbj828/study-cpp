#include <iostream>
#include <string>

using namespace std;

class Stack {
  struct Node {
    Node* prev;
    string s;

    Node(Node* prev, string s) : prev(prev), s(s) {}
  };

  Node* current;
  Node start;

 public:
  Stack();

  void push(string s);
  string pop();
  string peek();
  bool is_empty();

  ~Stack();
};