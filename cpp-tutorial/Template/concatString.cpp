#include <cstring>
#include <iostream>
#include <string>

/*
  GetStringSize
*/
size_t GetStringSize(const char* s) { return strlen(s); }
size_t GetStringSize(const std::string& s) { return s.size(); }

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs) {
  return GetStringSize(s) + GetStringSize(strs...);
}

/*
  AppendToString
*/
void AppendToString(std::string* concat_str) { return; }

template <typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... strs) {
  concat_str->append(s);
  AppendToString(concat_str, strs...);
}

/*
  StrCat
*/
template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
  size_t total_size = GetStringSize(s, strs...);

  std::string concat_str;
  concat_str.reserve(total_size);

  concat_str = s;

  AppendToString(&concat_str, strs...);

  return concat_str;
}

int main() {
  // std::string 과 const char* s 을 혼합해서 사용 가능하다.
  std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
                      " ", std::string("sentence"));
}
