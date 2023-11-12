#include "matrix_oop.h"

namespace MatrixLib {

Matrix::Matrix() : rows_(0), cols_(0), matrix_(nullptr){};

Matrix::Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(CreateMatrix(rows, cols, 0.0f)){};

Matrix::Matrix(const Matrix& other)
    : rows_(other.rows_),
      cols_(other.cols_),
      matrix_(CreateMatrix(other.rows_, other.cols_, other)){};

Matrix::Matrix(Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
};

Matrix::~Matrix() { FreeMatrix(); };

}  // namespace MatrixLib
