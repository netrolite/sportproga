#include <fstream>

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");

  char prev = 0;
  char cur;

  while (in.get(cur)) {
    bool needUnderscore = false;

    if (cur >= 'A' && cur <= 'Z') {
      if ((prev >= 'A' && prev <= 'Z') || (prev >= 'a' && prev <= 'z') ||
          (prev >= '0' && prev <= '9')) {
        needUnderscore = true;
      }
    } else if (cur >= '0' && cur <= '9') {
      if ((prev >= 'a' && prev <= 'z') || (prev >= 'A' && prev <= 'Z')) {
        needUnderscore = true;
      }
    }

    if (needUnderscore && prev != '_' && prev != 0)
      out.put('_');

    out.put(cur);
    prev = cur;
  }

  out.put('\n');

  in.close();
  out.close();

  return 0;
}
