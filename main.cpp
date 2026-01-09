#include <fstream>
#include <iostream>

int main() {
  std::ifstream file("input.txt");

  char text[1000000] = {};
  file.read(text, 1000000);
  int len = file.gcount();

  char pattern[256];
  int patternLen = 0;
  file.seekg(0);
  int i = 0;
  while (text[i] != '\n' && text[i] != '\0') {
    pattern[patternLen++] = text[i++];
  }
  file.close();

  int count = 0;
  for (int pos = 0; pos + patternLen <= len; ++pos) {
    int j = 0;
    while (j < patternLen && text[pos + j] == pattern[j])
      j++;
    bool match = j == patternLen;
    if (match)
      count++;
  }

  std::cout << count;
  return 0;
}
