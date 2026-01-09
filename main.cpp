#include <fstream>
#include <iostream>

typedef unsigned long long ull;

struct Rect {
  long long x, y, w, h;
};

ull getGcd(ull a, ull b) {
  while (b) {
    a %= b;
    ull temp = a;
    a = b;
    b = temp;
  }
  return a;
}

long long my_max(long long a, long long b) { return (a > b) ? a : b; }
long long my_min(long long a, long long b) { return (a < b) ? a : b; }

int main() {
  std::ifstream file("input.txt");

  int N;
  file >> N;

  // first rectangle
  Rect r1;
  file >> r1.x >> r1.y >> r1.w >> r1.h;
  ull area1 = (ull)r1.w * (ull)r1.h;

  std::cout << "1 1\n";

  // remaining rectangles
  for (int i = 0; i < N - 1; ++i) {
    Rect r2;
    file >> r2.x >> r2.y >> r2.w >> r2.h;
    ull area2 = (ull)r2.w * (ull)r2.h;

    long long intersectoinX1 = my_max(r1.x, r2.x);
    long long intersectionX2 = my_min(r1.x + r1.w, r2.x + r2.w);

    long long intersectionY1 = my_max(r1.y, r2.y);
    long long intersectionY2 = my_min(r1.y + r1.h, r2.y + r2.h);

    long long width = intersectionX2 - intersectoinX1;
    long long height = intersectionY2 - intersectionY1;

    if (width <= 0 || height <= 0) {
      std::cout << "0 1\n";
    } else {
      ull area = (ull)width * (ull)height;
      ull areaUnion = area1 + area2 - area;
      ull gcd = getGcd(area, areaUnion);

      std::cout << area / gcd << ' ' << areaUnion / gcd << '\n';
    }
  }

  file.close();

  return 0;
}
