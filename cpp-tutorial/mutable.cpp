#include <iostream>

class A {
  mutable int data_;

 public:
  A(int data) : data_(data) {}
  void DoSomething(int x) const {
    data_ = x;  // 불가능
  }

  void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
  A a(10);
  a.DoSomething(3);
  a.PrintData();
}

class Server {
  mutable Cache cache;

  User GetUserInfo(const int user_id) const {
    // 1. 캐쉬에서 user_id를 검색
    Data user_data = cache.find(user_id);

    // 2. 하지만 캐쉬에 데이터가 없다면 데이터베이스에 요청
    if (!user_data) {
      user_data = Database.find(user_id);

      // 그 후 캐쉬에 user_data 등록
      cache.update(user_id, user_data);
    }

    return User(user_data);
  }
}