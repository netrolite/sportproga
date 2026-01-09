#include <fstream>
#include <iostream>

void destroy(long long *arr) {
  if (arr != nullptr)
    delete[] arr;
}

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");

  int n;
  in >> n;

  long long *poly1 = new long long[n];
  for (int i = 0; i < n; ++i)
    in >> poly1[i];

  int m;
  in >> m;

  long long *poly2 = new long long[m];
  for (int i = 0; i < m; ++i)
    in >> poly2[i];

  int reusltSize = n + m;
  long long *result = new long long[reusltSize]();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      result[i + j] += poly1[i] * poly2[j];
    }
  }

  int printLen = 0;
  for (int i = reusltSize - 1; i >= 0; --i) {
    if (result[i] != 0) {
      printLen = i + 1;
      break;
    }
  }

  for (int i = 0; i < printLen; ++i) {
    out << result[i];
    if (i < printLen - 1)
      out << " ";
  }

  in.close();
  out.close();

  delete[] poly1;
  delete[] poly2;
  delete[] result;

  return 0;
}
