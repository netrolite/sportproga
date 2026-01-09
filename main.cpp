#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>

using namespace std;

typedef long long ll;
typedef complex<double> cd;

const double PI = acos(-1.0);

void fft(cd *a, int n, bool shouldInvert) {
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;

    for (; j & bit; bit >>= 1)
      j ^= bit;

    j |= bit;

    if (i < j) {
      cd tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (shouldInvert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j];
        cd v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }

  if (shouldInvert) {
    for (int i = 0; i < n; i++)
      a[i] /= n;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::ifstream in("input.txt");
  std::ofstream out("output.txt");

  int N;
  in >> N;

  int *A = new int[N];
  for (int i = 0; i < N; i++)
    in >> A[i];

  int M;
  in >> M;

  int *B = new int[M];
  for (int i = 0; i < M; i++)
    in >> B[i];

  int n = 1;
  while (n < N + M)
    n <<= 1;

  cd *fa = new cd[n];
  cd *fb = new cd[n];

  for (int i = 0; i < n; i++) {
    fa[i] = (i < N) ? cd(A[i], 0) : cd(0, 0);
    fb[i] = (i < M) ? cd(B[i], 0) : cd(0, 0);
  }

  fft(fa, n, false);
  fft(fb, n, false);

  for (int i = 0; i < n; i++)
    fa[i] *= fb[i];

  fft(fa, n, true);

  ll *Result = new ll[N + M];
  for (int i = 0; i < N + M - 1; i++)
    Result[i] = (ll)(fa[i].real() + 0.5);

  int lastNonZeroIndex = 0;
  for (int i = 0; i < N + M - 1; i++) {
    if (Result[i] != 0)
      lastNonZeroIndex = i;
  }

  for (int i = 0; i <= lastNonZeroIndex; i++) {
    out << Result[i];
    if (i < lastNonZeroIndex)
      out << ' ';
  }

  delete[] A;
  delete[] B;
  delete[] fa;
  delete[] fb;
  delete[] Result;

  in.close();
  out.close();

  return 0;
}
