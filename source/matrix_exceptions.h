#ifndef CPPMATRIXLIB_SOURCE_MATRIX_EXCEPTIONS_H_
#define CPPMATRIXLIB_SOURCE_MATRIX_EXCEPTIONS_H_

#include <stdexcept>

namespace MatrixLib {

class MatrixException : public std::exception {
 public:
  const char* what() const noexcept override { return "Matrix exception"; }
};

class CalcException : public std::exception {
 public:
  const char* what() const noexcept override { return "Calculation exception"; }
};

class SegmentationException : public std::exception {
 public:
  const char* what() const noexcept override {
    return "Segmentation exception";
  }
};

class AllocationException : public std::exception {
 public:
  const char* what() const noexcept override { return "Allocation exception"; }
};

}  // namespace MatrixLib

#endif