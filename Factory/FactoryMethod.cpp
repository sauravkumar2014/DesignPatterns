#include <cmath>
#include <iostream>

const float pi = 3.1415926535897932;

enum class PointType {
  cartesian,
  polar
};

class Point
{
  Point(const float &x, const float &y): x(x), y(y) {}

public:
  float x, y;

  friend std::ostream& operator<<(std::ostream &os, const Point &p)
  {
    return os << p.x << " " << p.y << std::endl;
  }

  static Point NewCartesian(float x, float y)
  {
    return {x,y};
  }

  static Point NewPolar(float r, float angle)
  {
    return{ r*cos(angle), r*sin(angle) };
  }
};

int main(int argc, char const *argv[])
{
  auto p = Point::NewPolar(5, pi/4);
  std::cout << p << std::endl;

  return 0;
}