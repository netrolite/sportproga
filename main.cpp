#include <fstream>
#include <iostream>

bool isDelimiter(char c) {
  return c == ' ' || c == '\t' || c == '.' || c == ',' || c == ';' ||
         c == ':' || c == '!' || c == '?' || c == '\n' || c == '\r';
}

int main() {
  std::ifstream file("input.txt");

  unsigned long long charCount = 0;
  unsigned long long wordCount = 0;
  bool inWord = false;
  char ch;

  while (file.get(ch)) {
    if (ch >= 32)
      charCount++;

    if (isDelimiter(ch)) {
      inWord = false;
    } else {
      // new word
      if (!inWord) {
        wordCount++;
        inWord = true;
      }
    }
  }

  file.close();

  std::cout << charCount << " " << wordCount << '\n';

  return 0;
}
