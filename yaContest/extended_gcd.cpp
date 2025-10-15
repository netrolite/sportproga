// Морозов Матвей
#include <iostream>

int main() {
  long long prev_r, r;
  std::cin >> prev_r >> r;

  long long prev_s = 1;
  long long s = 0;

  long long prev_t = 0;
  long long t = 1;

  while (r != 0) {
    long long quotient = prev_r / r;

    long long tmp = r;
    r = prev_r - quotient * r; // остаток от деления old_r на r
    prev_r = tmp;

    tmp = prev_s;
    prev_s = s;
    s = tmp - quotient * s;

    tmp = prev_t;
    prev_t = t;
    t = tmp - quotient * t;
  }

  if (prev_r < 0) {
    prev_r *= -1;
    prev_s *= -1;
    prev_t *= -1;
  }

  std::cout << prev_s << " " << prev_t << " " << prev_r;
}
