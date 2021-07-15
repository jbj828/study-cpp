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
  int capacity() const;
  char at(int i) const;
  void reserve(int size);

  void print() const;
  void println() const;

  // assign
  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  // insert
  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);
};

// ===================== 생성자 ===============
MyString::MyString(char c) {
  string_content = new char[1];
  string_content[0] = c;
  memory_capacity = 1;
  string_length = 1;
}

MyString::MyString(const char* str) {
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];
  for (int i = 0; i < string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  memory_capacity = string_length;
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

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++) {
      string_content[i] = prev_string_content[i];
    }

    delete[] prev_string_content;
  }
}

char MyString::at(int i) const {
  if (i >= string_length || i < 0)
    return NULL;
  else
    return string_content[i];
}

// insert
MyString& MyString::insert(int loc, const MyString& str) {
  if (loc < 0) {
    std::cout << "The location has to be positive number or zero." << std::endl;
    return *this;
  }
  if (str.length() <= 0) {
    std::cout << "Inserted string is empty" << std::endl;
    return *this;
  }

  int total_length = string_length + str.length();
  char* temp_content = string_content;
  if (memory_capacity < total_length) {
    // 새로운 메모리 할당
    delete[] string_content;
    string_content = new char[total_length + 1];
    string_length = total_length + 1;
  }

  if (loc == 0) {
    assign(str);
    for (int i = str.length(); i < string_length; i++) {
      string_content[i] = temp_content[i];
    }
  } else {
    for (int i = 0; i < loc - 1; i++) {
      string_content[i] = temp_content[i];
    }
    for (int i = loc; i < str.length() + loc; i++) {
      string_content[i] = str.at(i - loc);
    }
    for (int i = str.length() + loc; i < string_length; i++) {
      string_content[i] = temp_content[i - str.length() - 1];
    }
  }
  return *this;
}

MyString& MyString::insert(int loc, const char* str) {
  MyString temp(str);
  return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
  MyString temp(c);
  return insert(loc, temp);
}

// ========================MAIN====================
int main() {
  MyString str1("abcdefghijklmnop");
  MyString str2("ZEBRA");

  str1.insert(4, str2);

  str1.println();
}