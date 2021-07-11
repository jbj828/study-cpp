#include <string.h>

#include <iostream>

using namespace std;
class String {
  char* str;
  int len;

 public:
  String(char c, int n);
  String(const char* s);
  String(const String& s);
  ~String();

  void add_string(const String& s);
  void copy_string(const String& s);

  int length();

  void print_string();
};

String::String(char c, int n) {
  len = n;
  str = new char[n];

  for (int i = 0; i < len; i++) {
    str[i] = c;
  }
}

String::String(const char* s) {
  str = new char[strlen(s) + 1];
  strcpy(str, s);
  len = strlen(s);
}

String::String(const String& s) {
  len = s.len;
  str = new char[s.len + 1];
  strcpy(str, s.str);
}

String::~String() {
  if (str) delete[] str;
}

void String::add_string(const String& s) {
  len += s.len;
  strcat(str, s.str);
}

void String::copy_string(const String& s) {
  str = new char[s.len + 1];
  len = s.len;
  strcpy(str, s.str);
}

int String::length() { return len; }

void String::print_string() { cout << str << "," << len << endl; }

int main() {
  String e1('A', 3);
  String e2("Hello");
  String e3(e1);

  e1.print_string();
  e2.print_string();
  e3.print_string();

  e1.add_string(e2);
  e2.copy_string(e3);

  e1.print_string();
  e2.print_string();
  e3.print_string();
}