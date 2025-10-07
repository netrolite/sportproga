#include <iostream>

int main() {
  unsigned int modulo = 0;
  std::cin >> modulo;

  unsigned int seq_len = 0;
  unsigned int fib_a = 0;
  unsigned int fib_b = 1;

  do {
    ++seq_len;

    unsigned int new_fib_b = (fib_a + fib_b) % modulo;
    fib_a = fib_b;
    fib_b = new_fib_b;
  } while (fib_a != 0 || fib_b != 1);

  std::cout << seq_len;

  return 0;
}
