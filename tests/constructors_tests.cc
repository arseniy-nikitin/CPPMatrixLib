#include <gtest/gtest.h>
#include "../source/matrix_oop.h"

TEST(test, standard_constructor) {
  MatrixLib::Matrix m;
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(m.GetCols(), 0);
}

TEST(test, standard_constructor_const) {
  MatrixLib::Matrix const m;
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(m.GetCols(), 0);
}

TEST(test, parametrized_constructor_zero) {
  EXPECT_THROW(MatrixLib::Matrix m(1, 0), MatrixLib::SegmentationException);
}

TEST(test, parametrized_constructor_negative) {
  EXPECT_THROW(MatrixLib::Matrix m(1, -9), MatrixLib::SegmentationException);
}

TEST(test, parametrized_constructor_1x1) {
  MatrixLib::Matrix m(1, 1);
  EXPECT_EQ(m.GetRows(), 1);
  EXPECT_EQ(m.GetCols(), 1);
}

TEST(test, parametrized_constructor_1024x1024) {
  MatrixLib::Matrix m(1024, 1024);
  EXPECT_EQ(m.GetRows(), 1024);
  EXPECT_EQ(m.GetCols(), 1024);
}

TEST(test, parametrized_constructor_const) {
  MatrixLib::Matrix const m(1, 1);
  EXPECT_EQ(m(0, 0), 0.0f);
}

TEST(test, copy_constructor_empty_matrix) {
  MatrixLib::Matrix empty;
  MatrixLib::Matrix m(empty);
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(m.GetCols(), 0);
}

TEST(test, copy_constructor_1x1) {
  MatrixLib::Matrix single(1, 1);
  MatrixLib::Matrix m(single);
  EXPECT_EQ(m.GetRows(), 1);
  EXPECT_EQ(m.GetCols(), 1);
}

TEST(test, copy_constructor_1024x1024) {
  MatrixLib::Matrix large(1024, 1024);
  MatrixLib::Matrix m(large);
  EXPECT_EQ(m.GetRows(), 1024);
  EXPECT_EQ(m.GetCols(), 1024);
}

TEST(test, copy_constructor_const) {
  MatrixLib::Matrix src(1, 1);
  src(0, 0) = 12.3456789f;
  MatrixLib::Matrix const dst(src);
  EXPECT_EQ(dst(0, 0), 12.3456789f);
}

TEST(test, move_constructor_empty_matrix) {
  MatrixLib::Matrix empty;
  MatrixLib::Matrix m(std::move(empty));
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(m.GetCols(), 0);
}

TEST(test, move_constructor_1x1) {
  MatrixLib::Matrix single(1, 1);
  MatrixLib::Matrix m(std::move(single));
  EXPECT_EQ(m.GetRows(), 1);
  EXPECT_EQ(m.GetCols(), 1);
}

TEST(test, move_constructor_1024x1024) {
  MatrixLib::Matrix large(1024, 1024);
  MatrixLib::Matrix m(std::move(large));
  EXPECT_EQ(m.GetRows(), 1024);
  EXPECT_EQ(m.GetCols(), 1024);
}

TEST(test, move_constructor_const) {
  MatrixLib::Matrix src(1, 1);
  src(0, 0) = 12.3456789f;
  MatrixLib::Matrix const dst(std::move(src));
  EXPECT_EQ(dst(0, 0), 12.3456789f);
}