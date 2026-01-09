#include <fstream>
#include <iostream>

bool isDelimiter(char c) {
  return c == ' ' || c == '\t' || c == '.' || c == ',' || c == ';' ||
         c == ':' || c == '!' || c == '?' || c == '\n' || c == '\r';
}

int main() {
  std::ifstream file("input.txt");

  long long charCount = 0;
  long long wordCount = 0;
  bool inWord = false;
  char ch;

  while (file.get(ch)) {
    bool delimiter = isDelimiter(ch);

    if (!delimiter && (unsigned char)ch >= 32)
      charCount++;

    if (delimiter) {
      inWord = false;
    } else {
      if (!inWord) {
        wordCount++;
        inWord = true;
      }
    }
  }

  std::cout << charCount << " " << wordCount << '\n';

  file.close();

  return 0;
}
