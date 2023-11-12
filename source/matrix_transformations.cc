#include "matrix_oop.h"

namespace MatrixLib {

int Matrix::GetRows() const { return rows_; };

int Matrix::GetCols() const { return cols_; };

void Matrix::SetRows(int rows) {
  if (rows < 1) throw SegmentationException();
  if (cols_ == 0) {
    rows_ = rows;
    return;
  }
  Matrix buf(rows, cols_);
  for (int i = 0; i < std::min(rows, rows_); ++i) {
    for (int j = 0; j < cols_; ++j) {
      buf.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = std::move(buf);
};

void Matrix::SetCols(int cols) {
  if (cols < 1) throw SegmentationException();
  if (rows_ == 0) {
    cols_ = cols;
    return;
  }
  Matrix buf(rows_, cols);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < std::min(cols, cols_); ++j) {
      buf.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = std::move(buf);
};

Matrix Matrix::Transpose() {
  if (rows_ < 1 || cols_ < 1) throw SegmentationException();
  Matrix res(cols_, rows_);
  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      res.matrix_[i][j] = matrix_[j][i];
    }
  }
  return res;
};

Matrix Matrix::CalcComplements() {
  if (rows_ < 1 || cols_ < 1) throw SegmentationException();
  if (rows_ != cols_) throw CalcException();
  Matrix res(rows_, cols_);
  if (rows_ == 1 || cols_ == 1) {
    res.matrix_[0][0] = 1.0f;
    return res;
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      Matrix minor = Minor(i, j);
      float det = minor.Determinant();
      res.matrix_[i][j] = det * std::pow(-1.0f, static_cast<float>(i + j));
    }
  }
  return res;
};

Matrix Matrix::Minor(int row, int col) {
  if (rows_ < 1 || cols_ < 1) throw SegmentationException();
  if (rows_ != cols_) throw CalcException();
  if (rows_ == 1 || cols_ == 1) {
    Matrix res(rows_, cols_);
    res.matrix_[0][0] = 1.0f;
    return res;
  }
  Matrix res(rows_ - 1, cols_ - 1);
  int new_rows = 0, new_cols = 0;
  for (int i = 0; i < rows_; ++i) {
    if (i == row) continue;
    new_cols = 0;
    for (int j = 0; j < cols_; ++j) {
      if (j == col) continue;
      res.matrix_[new_rows][new_cols] = matrix_[i][j];
      ++new_cols;
    }
    ++new_rows;
  }
  res.rows_ = new_rows;
  res.cols_ = new_cols;
  return res;
}

float Matrix::Determinant() {
  constexpr float EPSILON = 1e-6f;
  if (rows_ < 1 || cols_ < 1) throw SegmentationException();
  if (rows_ != cols_) throw CalcException();
  if (rows_ == 1 || cols_ == 1) return matrix_[0][0];
  Matrix res(*this);
  float det = 1.0f;
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (std::abs(res.matrix_[i][j]) < EPSILON && i == j) {
        if (!res.SwapRowsDeterminant(res, i, j)) return 0.0f;
        det *= -1.0f;
        i -= 1;
      } else if (std::abs(res.matrix_[i][j]) > EPSILON && i != j) {
        res.NormalizeRowsDeterminant(res, i, j);
      }
    }
  }
  for (int i = 0; i < rows_; ++i) det *= res.matrix_[i][i];
  return det;
};

Matrix Matrix::InverseMatrix() {
  constexpr float EPSILON = 1e-6f;
  if (rows_ < 1 || cols_ < 1) throw SegmentationException();
  if (rows_ != cols_) throw CalcException();
  Matrix res(*this);
  if (rows_ == 1 || cols_ == 1) {
    if (matrix_[0][0] < EPSILON) throw CalcException();
    res.matrix_[0][0] = 1.0f / matrix_[0][0];
    return res;
  }
  float det = Determinant();
  if (std::abs(det) < EPSILON) throw CalcException();
  res = CalcComplements();
  res = res.Transpose();
  res *= (1.0f / det);
  return res;
};

}  // namespace MatrixLib