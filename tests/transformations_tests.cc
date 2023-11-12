#include <gtest/gtest.h>
#include "../source/matrix_oop.h"

constexpr float EPSILON = 1e-6f;

TEST(test, rows_getter_empty) {
  MatrixLib::Matrix m;
  EXPECT_EQ(m.GetRows(), 0);
}

TEST(test, rows_getter) {
  MatrixLib::Matrix m(124, 124);
  EXPECT_EQ(m.GetRows(), 124);
}

TEST(test, cols_getter_empty) {
  MatrixLib::Matrix m;
  EXPECT_EQ(m.GetCols(), 0);
}

TEST(test, cols_getter) {
  MatrixLib::Matrix m(124, 124);
  EXPECT_EQ(m.GetCols(), 124);
}

TEST(test, rows_setter_negative) {
  MatrixLib::Matrix m(124, 124);
  EXPECT_THROW(m.SetRows(-1), MatrixLib::SegmentationException);
}

TEST(test, cols_setter_negative) {
  MatrixLib::Matrix m(124, 124);
  EXPECT_THROW(m.SetCols(-1), MatrixLib::SegmentationException);
}

TEST(test, rows_setter_zero) {
  MatrixLib::Matrix m(124, 124);
  EXPECT_THROW(m.SetRows(0), MatrixLib::SegmentationException);
}

TEST(test, cols_setter_zero) {
  MatrixLib::Matrix m(124, 124);
  EXPECT_THROW(m.SetCols(0), MatrixLib::SegmentationException);
}

TEST(test, rows_setter_empty) {
  MatrixLib::Matrix m;
  m.SetRows(124);
  EXPECT_EQ(m.GetRows(), 124);
  EXPECT_EQ(m.GetCols(), 0);
}

TEST(test, cols_setter_empty) {
  MatrixLib::Matrix m;
  m.SetCols(124);
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(m.GetCols(), 124);
}

TEST(test, rows_setter) {
  MatrixLib::Matrix m(1, 1);
  m(0, 0) = 12.3456789f;
  m.SetRows(2);
  EXPECT_EQ(m(0, 0), 12.3456789f);
  EXPECT_EQ(m(1, 0), 0.0f);
}

TEST(test, cols_setter) {
  MatrixLib::Matrix m(1, 1);
  m(0, 0) = 12.3456789f;
  m.SetCols(2);
  EXPECT_EQ(m(0, 0), 12.3456789f);
  EXPECT_EQ(m(0, 1), 0.0f);
}

TEST(test, determinant_1x1) {
    MatrixLib::Matrix m1(1, 1);
    m1(0, 0) = 9.0f;

    float res = m1.Determinant();

    float actual = 9.0f;
    EXPECT_EQ(std::abs(res - actual) < EPSILON, true);
}

TEST(test, determinant_2x2) {
    MatrixLib::Matrix m1(2, 2);
    m1(0, 0) = 9.0f;
    m1(0, 1) = 3.0f;
    m1(1, 0) = 5.0f;
    m1(1, 1) = 2.0f;

    float res = m1.Determinant();

    float actual = 3.0f;
    EXPECT_EQ(std::abs(res - actual) < EPSILON, true);
}

TEST(test, determinant_3x3) {
    MatrixLib::Matrix m1(3, 3);
    m1(0, 0) = 3.0f;
    m1(0, 1) = 5.0f;
    m1(0, 2) = 6.0f;
    m1(1, 0) = 3.0f;
    m1(1, 1) = 8.0f;
    m1(1, 2) = 3.0f;
    m1(2, 0) = 9.0f;
    m1(2, 1) = 2.0f;
    m1(2, 2) = 1.0f;

    float res = m1.Determinant();

    float actual = -270.0f;
    EXPECT_EQ(std::abs(res - actual) < EPSILON, true);
}
TEST(test, determinant_degenerate) {
    MatrixLib::Matrix m1(2, 2);
    m1(0, 0) = 1.0f;
    m1(0, 1) = 1.0f;
    m1(1, 0) = 1.0f;
    m1(1, 1) = 1.0f;

    float res = m1.Determinant();

    float actual = 0.0f;
    EXPECT_EQ(std::abs(res - actual) < EPSILON, true);
}

TEST(test, determinant_wrong_size) {
    MatrixLib::Matrix m(2, 3);
    EXPECT_THROW(m.CalcComplements(), MatrixLib::CalcException);
}

TEST(test, determinant_empty) {
    MatrixLib::Matrix m;
    EXPECT_THROW(m.Determinant(), MatrixLib::SegmentationException);
}

TEST(test, minor_1x1) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(1, 1);
    MatrixLib::Matrix actual(1, 1);

    res = m1.Minor(0, 0);

    actual(0, 0) = 1.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, minor_2x2) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(2, 2);
    MatrixLib::Matrix actual(1, 1);

    res = m1.Minor(0, 0);

    EXPECT_EQ(res == actual, true);
}

TEST(test, minor_3x3) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(3, 3);
    MatrixLib::Matrix actual(2, 2);

    res = m1.Minor(0, 0);

    EXPECT_EQ(res == actual, true);
}

TEST(test, calc_complements_1x1) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(1, 1);
    MatrixLib::Matrix actual(1, 1);
    m1(0, 0) = 9.0f;

    res = m1.CalcComplements();

    actual(0, 0) = 1.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, calc_complements_2x2) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(2, 2);
    MatrixLib::Matrix actual(2, 2);
    m1(0, 0) = 9.0f;
    m1(0, 1) = 3.0f;
    m1(1, 0) = 5.0f;
    m1(1, 1) = 2.0f;

    res = m1.CalcComplements();

    actual(0, 0) = 2.0f;
    actual(0, 1) = -5.0f;
    actual(1, 0) = -3.0f;
    actual(1, 1) = 9.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, calc_complements_3x3) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(3, 3);
    MatrixLib::Matrix actual(3, 3);
    m1(0, 0) = 3.0f;
    m1(0, 1) = 5.0f;
    m1(0, 2) = 6.0f;
    m1(1, 0) = 3.0f;
    m1(1, 1) = 8.0f;
    m1(1, 2) = 3.0f;
    m1(2, 0) = 9.0f;
    m1(2, 1) = 2.0f;
    m1(2, 2) = 1.0f;

    res = m1.CalcComplements();

    actual(0, 0) = 2.0f;
    actual(0, 1) = 24.0f;
    actual(0, 2) = -66.0f;
    actual(1, 0) = 7.0f;
    actual(1, 1) = -51.0f;
    actual(1, 2) = 39.0f;
    actual(2, 0) = -33.0f;
    actual(2, 1) = 9.0f;
    actual(2, 2) = 9.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, calc_complements_degenerate) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(2, 2);
    MatrixLib::Matrix actual(2, 2);
    m1(0, 0) = 1.0f;
    m1(0, 1) = 1.0f;
    m1(1, 0) = 1.0f;
    m1(1, 1) = 1.0f;

    res = m1.CalcComplements();

    actual(0, 0) = 1.0f;
    actual(0, 1) = 1.0f;
    actual(1, 0) = 1.0f;
    actual(1, 1) = 1.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, calc_complements_wrong_size) {
    MatrixLib::Matrix m(2, 3);
    EXPECT_THROW(m.CalcComplements(), MatrixLib::CalcException);
}

TEST(test, calc_complements_empty) {
    MatrixLib::Matrix m;
    EXPECT_THROW(m.Transpose(), MatrixLib::SegmentationException);
}


TEST(test, transpose_1x1) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(1, 1);
    MatrixLib::Matrix actual(1, 1);
    m1(0, 0) = 1.0f;

    res = m1.Transpose();

    actual(0, 0) = 1.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, transpose_2x2) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(2, 2);
    MatrixLib::Matrix actual(2, 2);
    m1(0, 0) = 2.0f;
    m1(0, 1) = -5.0f;
    m1(1, 0) = -3.0f;
    m1(1, 1) = 9.0f;

    res = m1.Transpose();

    actual(0, 0) = 2.0f;
    actual(0, 1) = -3.0f;
    actual(1, 0) = -5.0f;
    actual(1, 1) = 9.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, transpose_3x3) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(3, 3);
    MatrixLib::Matrix actual(3, 3);
    m1(0, 0) = 2.0f;
    m1(0, 1) = 24.0f;
    m1(0, 2) = -66.0f;
    m1(1, 0) = 7.0f;
    m1(1, 1) = -51.0f;
    m1(1, 2) = 39.0f;
    m1(2, 0) = -33.0f;
    m1(2, 1) = 9.0f;
    m1(2, 2) = 9.0f;

    res = m1.Transpose();

    actual(0, 0) = 2.0f;
    actual(0, 1) = 7.0f;
    actual(0, 2) = -33.0f;
    actual(1, 0) = 24.0f;
    actual(1, 1) = -51.0f;
    actual(1, 2) = 9.0f;
    actual(2, 0) = -66.0f;
    actual(2, 1) = 39.0f;
    actual(2, 2) = 9.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, transpose_1x4) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(1, 4);
    MatrixLib::Matrix actual(4, 1);
    m1(0, 0) = 1.0f;
    m1(0, 1) = 2.0f;
    m1(0, 2) = 3.0f;
    m1(0, 3) = 4.0f;

    res = m1.Transpose();

    actual(0, 0) = 1.0f;
    actual(1, 0) = 2.0f;
    actual(2, 0) = 3.0f;
    actual(3, 0) = 4.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, transpose_empty) {
    MatrixLib::Matrix m;
    EXPECT_THROW(m.Transpose(), MatrixLib::SegmentationException);
}

TEST(test, inverse_matrix_1x1) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(1, 1);
    MatrixLib::Matrix actual(1, 1);
    m1(0, 0) = 9.0f;

    res = m1.InverseMatrix();

    actual(0, 0) = 1.0f / 9.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, inverse_matrix_2x2) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(2, 2);
    MatrixLib::Matrix actual(2, 2);
    m1(0, 0) = 9.0f;
    m1(0, 1) = 3.0f;
    m1(1, 0) = 5.0f;
    m1(1, 1) = 2.0f;

    res = m1.InverseMatrix();

    actual(0, 0) = 2.0f / 3.0f;
    actual(0, 1) = -1.0f;
    actual(1, 0) = -5.0f / 3.0f;
    actual(1, 1) = 3.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, inverse_matrix_3x3) {
    MatrixLib::Matrix res;
    MatrixLib::Matrix m1(3, 3);
    MatrixLib::Matrix actual(3, 3);
    m1(0, 0) = 3.0f;
    m1(0, 1) = 5.0f;
    m1(0, 2) = 6.0f;
    m1(1, 0) = 3.0f;
    m1(1, 1) = 8.0f;
    m1(1, 2) = 3.0f;
    m1(2, 0) = 9.0f;
    m1(2, 1) = 2.0f;
    m1(2, 2) = 1.0f;

    res = m1.InverseMatrix();

    actual(0, 0) = -1.0f / 135.0f;
    actual(0, 1) = -7.0f / 270.0f;
    actual(0, 2) = 11.0f / 90.0f;
    actual(1, 0) = -4.0f / 45.0f;
    actual(1, 1) = 17.0f / 90.0f;
    actual(1, 2) = -1.0f / 30.0f;
    actual(2, 0) = 11.0f / 45.0f;
    actual(2, 1) = -13.0f / 90.0f;
    actual(2, 2) = -1.0f / 30.0f;
    EXPECT_EQ(res == actual, true);
}

TEST(test, inverse_matrix_degenerate) {
    MatrixLib::Matrix m(2, 2);
    m(0, 0) = 1.0f;
    m(0, 1) = 1.0f;
    m(1, 0) = 1.0f;
    m(1, 1) = 1.0f;
    EXPECT_THROW(m.InverseMatrix(), MatrixLib::CalcException);
}

TEST(test, inverse_matrix_wrong_size) {
    MatrixLib::Matrix m(2, 3);
    EXPECT_THROW(m.InverseMatrix(), MatrixLib::CalcException);
}

TEST(test, inverse_matrix_empty) {
    MatrixLib::Matrix m;
    EXPECT_THROW(m.InverseMatrix(), MatrixLib::SegmentationException);
}