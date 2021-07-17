
bool operator==(MyString& str);

/*
    str1 == str2
->  str1.operator==(str2)
*/

bool MyString::operator==(MyString& str) { return !compare(str); }

