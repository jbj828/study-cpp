#include <iostream>
#include <string>

// template <typename String>
// std::string StrCat(const String& s) {
//   return std::string(s);
// }

// template <typename String, typename... Strings>
// std::string StrCat(const String& s, Strings... strs) {
//   return std::string(s) + StrCat(strs...);
// }

template <typename String>
int GetTotalLength(const String& s) {
  return std::string(s).size();
}

template <typename String, typename... Strings>
size_t GetTotalLength(const String& s, Strings... strs) {
  return std::string(s).size() + GetTotalLength(strs...);
}

std::string AppendToString(std::string* concat_str) { return; }

template <typename String, typename... Strings>
std::string AppendToString(std::string* concat_str, const String& s,
                           Strings... strs) {
  concat_str->append(s);
  AppendToString(concat_str, strs...);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
  size_t length = GetTotalLength(s, strs...);
  std::string concat_str;
  concat_str.reserve(length);
  concat_str = s;

  AppendToString(&concat_str, strs...);
  return concat_str;
}

int main() {
  std::cout << StrCat("abc", " ", std::string("hello"), " ", "def", " ",
                      std::string("world"));
}