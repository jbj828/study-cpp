#include <string.h>

#include <iostream>

class string {
  char *str;
  int len;

 public:
  string(char c, int n);  // 문자 c 가 n개 있는 문자열로 정의
  string(const char *s);
  string(const string &s);
  ~string();

  void add_string(const string &s);
  void copy_string(const string &s);
  int strlen();
};

string::string(char c, int n) {}