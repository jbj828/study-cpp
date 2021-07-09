#include <iostream>

// class Date {
//   int year_;
//   int month_;
//   int day_;

//  public:
//   void SetDate(int year, int month, int day);
//   void AddDay(int inc);
//   void AddMonth(int inc);
//   void AddYear(int inc);

//   int GetCurrentMonthTotalDays(int year, int month);
//   void ShowDate();

//   // Date(int year, int month, int day) {
//   //   year_ = year;
//   //   month_ = month;
//   //   day_ = day;
//   // }

//   // Default Constructor
//   Date() {
//     year_ = 2021;
//     month_ = 7;
//     day_ = 9;
//   }
// };

// void Date::SetDate(int year, int month, int day) {
//   year_ = year;
//   month_ = month;
//   day_ = day;
// }

// int Date::GetCurrentMonthTotalDays(int year, int month) {
//   static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
//   31}; if (month != 2) {
//     return month_day[month - 1];
//   } else if (year % 4 == 0 && year % 100 != 0) {
//     return 29;  // 윤년
//   } else {
//     return 28;
//   }
// }

// void Date::AddDay(int inc) {
//   while (true) {
//     int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

//     if (day_ + inc <= current_month_total_days) {
//       day_ += inc;
//       return;
//     } else {
//       inc -= (current_month_total_days - day_ + 1);
//       day_ = 1;
//       AddMonth(1);
//     }
//   }
// }

// void Date::AddMonth(int inc) {
//   AddYear((inc + month_ - 1) / 12);
//   month_ = month_ + inc % 12;
//   month_ = (month_ == 12 ? 12 : month_ % 12);
// }

// void Date::AddYear(int inc) { year_ += inc; }

// void Date::ShowDate() {
//   std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
//             << " 일 입니다 " << std::endl;
// }

// int main() {
//   Date day(2011, 3, 1);
//   day.ShowDate();
//   day.AddDay(30);
//   day.ShowDate();
//   day.AddDay(2000);
//   day.ShowDate();
//   day.SetDate(2012, 1, 31);  // 윤년
//   day.AddDay(29);
//   day.ShowDate();
//   day.SetDate(2012, 8, 4);
//   day.AddDay(2500);
//   day.ShowDate();
//   return 0;
// }

// class Test {
//  public:
//   Test() = default  // 디폴트 생성자를 정의해라
// };

class Date {
  int month_;
  int day_;
  int year_;

 public:
  void ShowDate() {
    std::cout << year_ << "/" << month_ << "/" << day_ << std::endl;
  }
  Date() {
    std::cout << "기본 생성자 호출!" << std::endl;
    year_ = 2012;
    month_ = 8;
    day_ = 12;
  }

  Date(int year, int month, int day) {
    std::cout << "인자 3개인 생성자 호출" << std::endl;
    year_ = 2012;
    month_ = 8;
    day_ = 12;
  }
};

int main() {
  Date day1 = Date();
  Date day2 = Date(1992, 3, 3);

  day1.ShowDate();
  day2.ShowDate();
}