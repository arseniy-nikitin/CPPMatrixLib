#include "matrix_oop.h"

namespace MatrixLib {

bool Matrix::EqMatrix(const Matrix& other) const {
  constexpr float EPSILON = 1e-6f;
  if (rows_ < 0 || cols_ < 0) throw SegmentationException();
  if (rows_ != other.rows_) return false;
  if (cols_ != other.cols_) return false;
  if (rows_ == 0 || cols_ == 0) return true;
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (matrix_[i][j] - other.matrix_[i][j] > EPSILON) return false;
    }
  }
  return true;
};

void Matrix::SumMatrix(const Matrix& other) {
  if (rows_ < 1 || cols_ < 1) throw SegmentationException();
  if (rows_ != other.rows_) throw MatrixException();
  if (cols_ != other.cols_) throw MatrixException();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
};

void Matrix::SubMatrix(const Matrix& other) {
  if (rows_ < 1 || cols_ < 1) throw SegmentationException();
  if (rows_ != other.rows_) throw MatrixException();
  if (cols_ != other.cols_) throw MatrixException();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
};

void Matrix::MulNumber(const float num) {
  if (rows_ < 1 || cols_ < 1) throw SegmentationException();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
};

void Matrix::MulMatrix(const Matrix& other) {
  if (rows_ < 1 || cols_ < 1) throw SegmentationException();
  if (cols_ != other.rows_) throw CalcException();
  Matrix res(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = std::move(res);
};

int Matrix::SwapRowsDeterminant(Matrix& m, int row, int col) {
  constexpr float EPSILON = 1e-6f;
  int pivot_row = 0;
  for (int k = row; k < rows_ && pivot_row; ++k) {
    if (m.matrix_[k][col] > EPSILON) pivot_row = k;
  }
  if (pivot_row) {
    std::swap(m.matrix_[row], m.matrix_[pivot_row]);
  }
  return pivot_row;
}

void Matrix::NormalizeRowsDeterminant(Matrix& m, int row, int col) {
  float actual = m.matrix_[row][col];
  for (int k = 0; k < cols_; ++k) {
    float factor = -1.0f * (m.matrix_[col][k] * actual / m.matrix_[col][col]);
    m.matrix_[row][k] += factor;
  }
}

float** Matrix::CreateMatrix(int rows, int cols, const Matrix& other) {
  if (rows < 0 || cols < 0) throw SegmentationException();
  if (rows == 0 || cols == 0) return nullptr;
  try {
    float** matrix = new float*[static_cast<unsigned long>(rows)];
    for (int i = 0; i < rows; ++i) {
      matrix[i] = new float[static_cast<unsigned long>(cols)];
      for (int j = 0; j < cols; ++j) {
        matrix[i][j] = other.matrix_[i][j];
      }
    }
    return matrix;
  } catch (std::bad_alloc& ba) {
    FreeMatrix();
    throw AllocationException();
  }
}

float** Matrix::CreateMatrix(int rows, int cols, const float num) {
  if (rows < 1 || cols < 1) throw SegmentationException();
  try {
    float** matrix = new float*[static_cast<unsigned long>(rows)];
    for (int i = 0; i < rows; ++i) {
      matrix[i] = new float[static_cast<unsigned long>(cols)];
      for (int j = 0; j < cols; ++j) {
        matrix[i][j] = num;
      }
    }
    return matrix;
  } catch (std::bad_alloc& ba) {
    FreeMatrix();
    throw AllocationException();
  }
}

void Matrix::FreeMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
    delete[] matrix_;
    matrix_ = nullptr;
  }
  rows_ = 0;
  cols_ = 0;
}

}  // namespace MatrixLib
