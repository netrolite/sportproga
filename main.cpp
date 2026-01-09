#include <fstream>
#include <iostream>

int main() {
  std::ifstream file("input.txt");

  int n;
  file >> n;
  if (file.eof()) {
    std::cout << 0 << '\n';
    return 0;
  }

  long long maxSum = 0;
  long long curSum = 0;
  int el;
  for (int i = 0; i < n; ++i) {
    file >> el;
    curSum += el;

    if (curSum < 0)
      curSum = 0;

    if (maxSum < curSum)
      maxSum = curSum;
  }

  std::cout << maxSum << '\n';

  file.close();
  return 0;
}
