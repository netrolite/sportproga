#include <iostream>

unsigned long long num = 0;
unsigned long long res = 0;

int main() {
  std::cin >> num;
  for (int i = 1; i <= num; ++i)
    res += i;
  std::cout << res;
}
