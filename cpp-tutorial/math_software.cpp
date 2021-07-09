#include <cmath>
#include <iostream>

class Point {
  int x, y;

 public:
  Point(int pos_x, int pos_y) {
    x = pos_x;
    y = pos_y;
  };

  int GetX() { return x; }
  int GetX() const { return x; }
  int GetY() { return y; }
  int GetY() const { return y; }
};

class Geometry {
 private:
  Point *point_array[100];
  int num_points;

 public:
  Geometry() { num_points = 0; };

  void AddPoint(const Point &point);
  void PrintDistance();
  void PrintNumMeets();
};

void Geometry::AddPoint(const Point &point) {
  point_array[num_points++] = new Point(point.GetX(), point.GetY());
};

// 모든 점들간의 거리를 출력하는 함수
void Geometry::PrintDistance() {
  double distance = 0.0f;
  for (int i = 0; i <= num_points; i++) {
    Point *curr = point_array[i];
    Point *next = point_array[i + 1];

    int currX = curr->GetX();
    int currY = curr->GetY();
    int nextX = next->GetX();
    int nextY = next->GetY();

    int sqrtDist = pow(currX - nextX, 2) + pow(currY - nextY, 2);

    double dist = sqrt(sqrtDist);
    distance += dist;
  }
  std::cout << 'Distance between all the Point is ' << distance << std::endl;
};

void Geometry::PrintNumMeets(){

};