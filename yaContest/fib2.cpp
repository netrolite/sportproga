#include <iostream>

int main() {
  unsigned long long fib_n = 0;
  unsigned long long modulo = 0;
  std::cin >> fib_n >> modulo;

  if (fib_n < 2) {
    if (fib_n == 0)
      std::cout << 0 << std::endl;

    if (fib_n == 1)
      std::cout << 1 % modulo << std::endl;

    return 0;
  }

  unsigned int fib_a = 0;
  unsigned int fib_b = 1;

  // надо юзать периоды пизано
  for (unsigned long long i = 0; i < fib_n - 1; ++i) {
    unsigned int new_fib_b = (fib_a + fib_b) % modulo;
    fib_a = fib_b;
    fib_b = new_fib_b;
  }

  std::cout << fib_b << std::endl;

  return 0;
}
