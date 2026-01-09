#include <cstring>
#include <fstream>

static const char *const morseCodes[55] = {
    ".-",     "-...",   "-.-.",   "-..",     ".",      "..-.",     "--.",
    "....",   "..",     ".---",   "-.-",     ".-..",   "--",       "-.",
    "---",    ".--.",   "--.-",   ".-.",     "...",    "-",        "..-",
    "...-",   ".--",    "-..-",   "-.--",    "--..",   "-----",    ".----",
    "..---",  "...--",  "....-",  ".....",   "-....",  "--...",    "---..",
    "----.",  ".-.-.-", "--..--", "..--..",  ".----.", "-.-.--",   "-..-.",
    "-.--.",  "-.--.-", ".-...",  "---...",  "-.-.-.", "-...-",    ".-.-.",
    "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};

static const char *const symbols[55] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",  "K", "L", "M",  "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",  "Y", "Z", "0",  "1",
    "2", "3", "4", "5", "6", "7", "8", "9", ".", ",",  "?", "'", "!",  "/",
    "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@", "SOS"};

const char *morseToChar(const char *code) {
  // if (code[0] == '\0')
  //   return nullptr;

  for (int i = 0; i < 55; ++i) {
    if (strcmp(morseCodes[i], code) == 0)
      return symbols[i];
  }
  return nullptr;
}

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");

  char ch;
  char buffer[20];
  int idx = 0;
  int spaceCount = 0;

  while (in.get(ch)) {
    if (ch == '.' || ch == '-') {
      // new word
      if (spaceCount >= 3) {
        out << " ";
      }

      buffer[idx++] = ch;
      buffer[idx] = '\0';
      spaceCount = 0;
    } else if (ch == ' ' || ch == '\n' || ch == '\r') {
      if (idx > 0) {
        const char *res = morseToChar(buffer);
        if (res)
          out << res;

        idx = 0;
        buffer[0] = '\0';
      }

      if (ch == ' ')
        spaceCount++;
    }
  }

  if (idx > 0) {
    const char *res = morseToChar(buffer);
    if (res)
      out << res;
  }

  in.close();
  out.close();

  return 0;
}
