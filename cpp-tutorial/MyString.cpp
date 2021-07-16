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

  // erase
  MyString& erase(int loc, int num);

  // find
  int find(int find_from, MyString& str) const;
  int find(int find_from, const char* str) const;
  int find(int find_from, char c) const;

  // compare
  int compare(const MyString& str) const;
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
    return '\0';
  else
    return string_content[i];
}

// insert
MyString& MyString::insert(int loc, const MyString& str) {
  if (loc < 0 || loc > string_length) return *this;

  if (str.length() <= 0) {
    std::cout << "Inserted string is empty" << std::endl;
    return *this;
  }

  int total_length = string_length + str.length();
  char* temp_content = string_content;
  if (memory_capacity < total_length) {
    // 새로운 메모리 할당
    if (memory_capacity * 2 > total_length) {
      memory_capacity *= 2;
    } else {
      memory_capacity = total_length;
    }
    delete[] string_content;
    string_content = new char[memory_capacity];
    string_length = total_length;
  }

  if (loc == 0) {
    for (int i = 0; i < str.length(); i++) {
      string_content[i] = str.at(i);
    }
    for (int i = str.length(); i < string_length; i++) {
      string_content[i] = temp_content[i - str.length()];
    }
  } else {
    for (int i = 0; i < loc; i++) {
      string_content[i] = temp_content[i];
    }
    for (int i = loc; i < str.length() + loc; i++) {
      string_content[i] = str.at(i - loc);
    }
    for (int i = str.length() + loc; i <= string_length; i++) {
      string_content[i] = temp_content[i - str.length()];
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

// erase
MyString& MyString::erase(int loc, int num) {
  if (loc < 0 || loc > string_length || num < 0) return *this;

  // 지운다는 것은 단순히 뒤의 문자를 앞으로 끌고 오면 된다
  for (int i = loc + num; i < string_length; i++) {
    string_content[i - num] = string_content[i];
  }

  string_length -= num;
  return *this;
}

// find
int MyString::find(int find_from, MyString& str) const {
  int i, j;

  if (str.string_length == 0) return -1;
  for (i = find_from; i <= string_length - str.string_length; i++) {
    for (j = 0; j < str.string_length; j++) {
      if (string_content[i + j] != str.string_content[j]) break;
    }

    if (j == str.string_length) return i;
  }

  return -1;
}

int MyString::find(int find_from, const char* str) const {
  MyString temp(str);
  return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
  MyString temp(c);
  return find(find_from, temp);
}

// compare
int MyString::compare(const MyString& str) const {
  for (int i = 0; i < std::min(string_length, str.string_length); i++) {
    if (string_content[i] > str.string_content[i]) {
      return 1;
    } else if (string_content[i] < str.string_content[i]) {
      return -1;
    }
  }

  if (string_length == str.string_length)
    return 0;
  else if (string_length > str.string_length)
    return 1;

  return -1;
}

// ========================MAIN====================
int main() {
  MyString str1("abcdefghijklmnop");
  MyString str2("hi");
  int result = str1.find(3, str2);

  std::cout << result << std::endl;
}