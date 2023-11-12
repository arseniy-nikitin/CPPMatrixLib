#include "matrix_oop.h"

namespace MatrixLib {

float& Matrix::operator()(int i, int j) {
  if (i >= rows_ || i < 0) throw SegmentationException();
  if (j >= cols_ || j < 0) throw SegmentationException();
  return matrix_[i][j];
};

float Matrix::operator()(int i, int j) const {
  if (i >= rows_ || i < 0) throw SegmentationException();
  if (j >= cols_ || j < 0) throw SegmentationException();
  return matrix_[i][j];
};

bool Matrix::operator==(const Matrix& other) const { return EqMatrix(other); };

bool Matrix::operator!=(const Matrix& other) const { return !EqMatrix(other); };

Matrix& Matrix::operator=(const Matrix& other) {
  if (this != &other) {
    FreeMatrix();

    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = CreateMatrix(other.rows_, other.cols_, other);
  }
  return *this;
};

Matrix& Matrix::operator=(Matrix&& other) noexcept {
  if (this != &other) {
    FreeMatrix();

    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;

    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
};

Matrix Matrix::operator+(const Matrix& other) const {
  Matrix res(*this);
  res.SumMatrix(other);
  return res;
};

Matrix Matrix::operator-(const Matrix& other) const {
  Matrix res(*this);
  res.SubMatrix(other);
  return res;
};

Matrix Matrix::operator*(const float num) const {
  Matrix res(*this);
  res.MulNumber(num);
  return res;
};

Matrix Matrix::operator*(const Matrix& other) const {
  Matrix res(*this);
  res.MulMatrix(other);
  return res;
};

Matrix Matrix::operator+=(const Matrix& other) {
  SumMatrix(other);
  return *this;
};

Matrix Matrix::operator-=(const Matrix& other) {
  SubMatrix(other);
  return *this;
};

Matrix Matrix::operator*=(const float num) {
  MulNumber(num);
  return *this;
};

Matrix Matrix::operator*=(const Matrix& other) {
  MulMatrix(other);
  return *this;
};

}  // namespace MatrixLib