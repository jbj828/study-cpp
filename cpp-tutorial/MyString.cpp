#include <string.h>

#include <iostream>

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이
  int memory_capacity;

 public:
  // 문자 하나로 생성
  MyString(char c);

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);
  ~MyString();

  // 문자열의 길이를 구한다
  int length() const;

  void print() const;
  void println() const;

  // assign
  MyString& assign(const MyString& str);
  MyString& assign(const char* str);
};

// ===================== 생성자 ===============
MyString::MyString(char c) {
  string_content = new char[1];
  string_content[0] = c;
  string_length = 1;
}

MyString::MyString(const char* str) {
  string_length = strlen(str);
  string_content = new char[string_length];
  for (int i = 0; i < string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  string_content = new char[string_length];
  for (int i = 0; i < string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }

// ===================== 함수 ===============
int MyString::length() const { return string_length; }

void MyString::print() const {
  for (int i = 0; i < string_length; i++) {
    std::cout << string_content[i];
  }
}

void MyString::println() const {
  for (int i = 0; i < string_length; i++) {
    std::cout << string_content[i];
  }
  std::cout << std::endl;
}

// assign
MyString& MyString::assign(const MyString& str) {
  if (str.string_length > memory_capacity) {
    delete[] string_content;
    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i < str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }
  string_length = str.string_length;

  return *this;
}
MyString& MyString::assign(const char* str) {
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    delete[] string_content;
    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i < str_length; i++) {
    string_content[i] = str[i];
  }
  string_length = str_length;

  return *this;
}

// ========================MAIN====================
int main() {
  MyString str1("Hello world!");
  MyString str2(str1);

  str1.println();
  str2.println();
}