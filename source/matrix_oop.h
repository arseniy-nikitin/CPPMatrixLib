#ifndef CPPMATRIXLIB_SOURCE_MATRIX_OOP_H_
#define CPPMATRIXLIB_SOURCE_MATRIX_OOP_H_

#include <algorithm>
#include <cmath>
#include <iostream>

#include "matrix_exceptions.h"

namespace MatrixLib {

class Matrix {
 public:
  Matrix();
  Matrix(int rows, int cols);
  Matrix(const Matrix& other);
  Matrix(Matrix&& other) noexcept;
  ~Matrix();

  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);

  Matrix Transpose();
  Matrix CalcComplements();
  Matrix Minor(int row, int col);
  float Determinant();
  Matrix InverseMatrix();

  float& operator()(int i, int j);
  float operator()(int i, int j) const;
  bool operator==(const Matrix& other) const;
  bool operator!=(const Matrix& other) const;
  Matrix& operator=(const Matrix& other);
  Matrix& operator=(Matrix&& other) noexcept;
  Matrix operator+(const Matrix& other) const;
  Matrix operator-(const Matrix& other) const;
  Matrix operator*(const float num) const;
  Matrix operator*(const Matrix& other) const;
  Matrix operator+=(const Matrix& other);
  Matrix operator-=(const Matrix& other);
  Matrix operator*=(const float num);
  Matrix operator*=(const Matrix& other);

 private:
  bool EqMatrix(const Matrix& other) const;
  void SumMatrix(const Matrix& other);
  void SubMatrix(const Matrix& other);
  void MulNumber(const float num);
  void MulMatrix(const Matrix& other);

  int SwapRowsDeterminant(Matrix& m, int row, int col);
  void NormalizeRowsDeterminant(Matrix& m, int row, int col);

  float** CreateMatrix(int rows, int cols, const Matrix& other);
  float** CreateMatrix(int rows, int cols, const float num);
  void FreeMatrix();

  int rows_;
  int cols_;
  float** matrix_;
};

}  // namespace MatrixLib

#endif