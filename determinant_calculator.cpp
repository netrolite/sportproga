#include <iostream>

/*
  int**
  points to an array, i.e *int
  *int is an array in which every element is a *int, thus poiting to another
  array
*/
int **create_matrix(int size) {
  int **matrix = new int *[size];
  for (int i = 0; i < size; ++i) {
    matrix[i] = new int[size];
  }
  return matrix;
}

void delete_matrix(int **matrix, int size) {
  for (int i = 0; i < size; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void print_matrix_sizes() {
  std::cout << "2) 2x2\n";
  std::cout << "3) 3x3\n";
}

int calc_2x2(int **m) { return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]); }
int calc_3x3(int **m) {
  /*
    00 01 02
    10 11 12
    20 21 22
  */
  int a = (m[0][0] * m[1][1] * m[2][2]) + (m[1][0] * m[2][1] * m[0][2]) +
          (m[0][1] * m[1][2] * m[2][0]);

  int b = (m[0][2] * m[1][1] * m[2][0]) + (m[2][1] * m[1][2] * m[0][0]) +
          (m[1][0] * m[0][1] * m[2][2]);

  return a - b;
}

enum Matrix_size { Two = 2, Three = 3 };

Matrix_size to_matrix_size(int n) {
  switch (n) {
  case Two:
    return Two;
  case Three:
    return Three;
  }
  throw "invalid matrix size";
}

int main() {
  std::cout << "Enter matrix size (2 or 3):\n";
  print_matrix_sizes();

  int matrix_size_int = 0;
  while (matrix_size_int == 0) {
    std::cin >> matrix_size_int;

    switch (matrix_size_int) {
    case Matrix_size::Two:
    case Matrix_size::Three:
      break;
    default:
      matrix_size_int = 0;
      std::cout << "Invalid matrix size. Please try again. Possible values:\n";
      print_matrix_sizes();
    }
  }

  Matrix_size matrix_size = to_matrix_size(matrix_size_int);
  int a, b, c;
  int **matrix = create_matrix(matrix_size_int);

  if (matrix_size == Matrix_size::Two) {
    for (int row = 0; row < Matrix_size::Two; ++row) {
      std::cout << "Enter numbers in row " << row + 1 << ":" << '\n';
      std::cin >> a >> b;
      matrix[row][0] = a;
      matrix[row][1] = b;
    }
  } else {
    for (int row = 0; row < Matrix_size::Three; ++row) {
      std::cout << "Enter numbers in row " << row + 1 << ":" << '\n';
      std::cin >> a >> b >> c;
      matrix[row][0] = a;
      matrix[row][1] = b;
      matrix[row][2] = c;
    }
  }

  int determinant;
  if (matrix_size == Matrix_size::Two) {
    determinant = calc_2x2(matrix);
  } else {
    determinant = calc_3x3(matrix);
  }

  delete_matrix(matrix, matrix_size_int);

  std::cout << "Determinant = " << determinant << '\n';

  return 0;
}
