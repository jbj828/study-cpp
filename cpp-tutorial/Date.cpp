#include <iostream>

class Date {
  int year_;
  int month_;
  int day_;

 public:
  void SetDate(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
  }
  void AddDay(int inc) {
    int month_days[12] = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31};

    if (inc >= 365) {
      int plus_year = inc / 365;
      year_ += plus_year;
      inc %= 365;
    }

    int curr_month_days = month_days[month_ - 1];
    while (inc > month_days[month_ - 1]) {
      inc -= month_days[month_ - 1];
      month_++;
      if (month_ > 12) {
        year_++;
        month_ = 1;
      }
    }

    if (inc + day_ > month_days[month_ - 1]) {
      int curr_left = month_days[month_ - 1] - day_;

      inc -= curr_left;
      month_++;
      day_ = inc;
    }
  }
  void AddMonth(int inc) {
    int total = month_ + inc;
    if (total > 12) {
      int left = total % 12;
      int val = total / 12;
      year_ += val;
      month_ = left;
    } else {
      month_ = total;
    }
  }
  void AddYear(int inc) { year_ += inc; }

  void ShowDate() {
    std::cout << year_ << "/" << month_ << "/" << day_ << std::endl;
  }
};

int main() {
  Date date;
  date.SetDate(2021, 7, 8);
  date.AddYear(3);
  date.AddMonth(24);
  date.AddDay(650);
  date.ShowDate();
}