#include <fstream>

static const char *const morseCodes[54] = {
    ".-",     "-...",   "-.-.",   "-..",     ".",      "..-.",   "--.",
    "....",   "..",     ".---",   "-.-",     ".-..",   "--",     "-.",
    "---",    ".--.",   "--.-",   ".-.",     "...",    "-",      "..-",
    "...-",   ".--",    "-..-",   "-.--",    "--..",   "-----",  ".----",
    "..---",  "...--",  "....-",  ".....",   "-....",  "--...",  "---..",
    "----.",  ".-.-.-", "--..--", "..--..",  ".----.", "-.-.--", "-..-.",
    "-.--.",  "-.--.-", ".-...",  "---...",  "-.-.-.", "-...-",  ".-.-.",
    "-....-", "..--.-", ".-..-.", "...-..-", ".--.-."};

static const char *const symbols[54] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",  "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",  "Y", "Z", "0", "1",
    "2", "3", "4", "5", "6", "7", "8", "9", ".", ",",  "?", "'", "!", "/",
    "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@"};

char toUpper(char ch) {
  if ('a' <= ch && ch <= 'z')
    return ch - 32;
  return ch;
}

const char *charToMorse(char c) {
  char upper = toUpper(c);

  for (int i = 0; i < 54; ++i) {
    if (symbols[i][0] == upper) {
      return morseCodes[i];
    }
  }
  return nullptr;
}

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");

  char ch;
  bool isFirstWord = true;
  bool inWord = false;
  bool firstCharInWord = true;

  while (in.get(ch)) {
    if (ch == ' ') {
      inWord = false;
      continue;
    }

    const char *morseCode = charToMorse(ch);

    if (morseCode != nullptr) {
      if (!inWord) {
        if (!isFirstWord) {
          out << "   ";
        }
        inWord = true;
        isFirstWord = false;
        firstCharInWord = true;
      }

      if (!firstCharInWord) {
        out << " ";
      }

      out << morseCode;
      firstCharInWord = false;
    }
  }

  in.close();
  out.close();

  return 0;
}
