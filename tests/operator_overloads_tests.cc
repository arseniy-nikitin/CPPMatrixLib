#include <gtest/gtest.h>
#include "../source/matrix_oop.h"

TEST(test, round_brackets_operator_empty) {
  MatrixLib::Matrix m;
  EXPECT_THROW(m(0, 0), MatrixLib::SegmentationException);
}

TEST(test, round_brackets_operator_negative) {
  MatrixLib::Matrix m(1, 1);
  EXPECT_THROW(m(-1, 0), MatrixLib::SegmentationException);
}

TEST(test, round_brackets_operator_out_of_range) {
  MatrixLib::Matrix m(1, 1);
  EXPECT_THROW(m(2, 3), MatrixLib::SegmentationException);
}

TEST(test, round_brackets_operator_single) {
  MatrixLib::Matrix m(1, 1);
  m(0, 0) = 12.3456789f;
  EXPECT_EQ(m(0, 0), 12.3456789f);
}

TEST(test, round_brackets_operator_const) {
  MatrixLib::Matrix src(1, 1);
  src(0, 0) = 12.3456789f;
  MatrixLib::Matrix const dst(src);
  EXPECT_EQ(src(0, 0), 12.3456789f);
}

TEST(test, eq_operator_empty) {
  MatrixLib::Matrix m1;
  MatrixLib::Matrix m2;
  EXPECT_EQ(m1 == m2, true);
}

TEST(test, eq_operator_size_false) {
  MatrixLib::Matrix m1(1, 2);
  MatrixLib::Matrix m2(2, 1);
  EXPECT_EQ(m1 == m2, false);
}

TEST(test, eq_operator_size_true) {
  MatrixLib::Matrix m1(1024, 1024);
  MatrixLib::Matrix m2(1024, 1024);
  EXPECT_EQ(m1 == m2, true);
}

TEST(test, eq_operator_val_false) {
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix m2(2, 2);
  m1(0, 0) = 12.3456789f;
  m1(0, 1) = 12.3456789f;
  m1(1, 0) = 12.3456789f;
  m1(1, 1) = 12.3456789f;

  m2(0, 0) = 12.3456789f;
  m2(0, 1) = 12.3456789f;
  m2(1, 0) = 12.3456789f;
  m2(1, 1) = 12.3456770f;
  EXPECT_EQ(m1 == m2, false);
}

TEST(test, eq_operator_val_true) {
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix m2(2, 2);
  m1(0, 0) = 12.3456789f;
  m1(0, 1) = 12.3456789f;
  m1(1, 0) = 12.3456789f;
  m1(1, 1) = 12.3456789f;

  m2(0, 0) = 12.3456789f;
  m2(0, 1) = 12.3456789f;
  m2(1, 0) = 12.3456789f;
  m2(1, 1) = 12.3456789f;
  EXPECT_EQ(m1 == m2, true);
}

TEST(test, uneq_operator_empty) {
  MatrixLib::Matrix m1;
  MatrixLib::Matrix m2;
  EXPECT_EQ(m1 != m2, false);
}

TEST(test, uneq_operator_size_false) {
  MatrixLib::Matrix m1(1, 2);
  MatrixLib::Matrix m2(2, 1);
  EXPECT_EQ(m1 != m2, true);
}

TEST(test, uneq_operator_size_true) {
  MatrixLib::Matrix m1(1024, 1024);
  MatrixLib::Matrix m2(1024, 1024);
  EXPECT_EQ(m1 != m2, false);
}

TEST(test, uneq_operator_val_false) {
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix m2(2, 2);
  m1(0, 0) = 12.3456789f;
  m1(0, 1) = 12.3456789f;
  m1(1, 0) = 12.3456789f;
  m1(1, 1) = 12.3456789f;

  m2(0, 0) = 12.3456789f;
  m2(0, 1) = 12.3456789f;
  m2(1, 0) = 12.3456789f;
  m2(1, 1) = 12.3456770f;
  EXPECT_EQ(m1 != m2, true);
}

TEST(test, uneq_operator_val_true) {
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix m2(2, 2);
  m1(0, 0) = 12.3456789f;
  m1(0, 1) = 12.3456789f;
  m1(1, 0) = 12.3456789f;
  m1(1, 1) = 12.3456789f;

  m2(0, 0) = 12.3456789f;
  m2(0, 1) = 12.3456789f;
  m2(1, 0) = 12.3456789f;
  m2(1, 1) = 12.3456789f;
  EXPECT_EQ(m1 != m2, false);
}

TEST(test, assignment_operator) {
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix m2(2, 2);
  m1(0, 0) = 12.3456789f;
  m1(0, 1) = 12.3456789f;
  m1(1, 0) = 12.3456789f;
  m1(1, 1) = 12.3456789f;

  m2 = m1;
  EXPECT_EQ(m1 == m2, true);
}

TEST(test, chained_assignment_operator) {
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix m2(2, 2);
  MatrixLib::Matrix m3(2, 2);
  m1(0, 0) = 12.3456789f;
  m1(0, 1) = 12.3456789f;
  m1(1, 0) = 12.3456789f;
  m1(1, 1) = 12.3456789f;

  m3 = m2 = m1;
  EXPECT_EQ(m1 == m2, true);
  EXPECT_EQ(m2 == m3, true);
  EXPECT_EQ(m3 == m1, true);
}

TEST(test, chained_assignment_operator_empty) {
  MatrixLib::Matrix m1;
  MatrixLib::Matrix m2(2, 2);
  MatrixLib::Matrix m3(2, 2);
  m2(0, 0) = 12.3456789f;
  m2(0, 1) = 12.3456789f;
  m2(1, 0) = 12.3456789f;
  m2(1, 1) = 12.3456789f;

  m3 = m2;
  m3 = m2 = m1;
  EXPECT_EQ(m1 == m2, true);
  EXPECT_EQ(m2 == m3, true);
  EXPECT_EQ(m3 == m1, true);
}

TEST(test, move_assignment_operator) {
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix m2(2, 2);
  MatrixLib::Matrix m3(2, 2);
  m1(0, 0) = 12.3456789f;
  m1(0, 1) = 12.3456789f;
  m1(1, 0) = 12.3456789f;
  m1(1, 1) = 12.3456789f;

  m2 = m1;
  m3 = std::move(m2);
  EXPECT_EQ(m1 == m3, true);
  EXPECT_EQ(m2.GetRows(), 0);
  EXPECT_EQ(m2.GetCols(), 0);
}

TEST(test, move_assignment_operator_empty) {
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix m2;

  m1 = std::move(m2);
  EXPECT_EQ(m1 == m2, true);
}

TEST(test, plus_operator) {
  MatrixLib::Matrix res;
  MatrixLib::Matrix actual(2, 2);
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix m2(2, 2);
  m1(0, 0) = 33.3333333f;
  m1(0, 1) = 33.3333333f;
  m1(1, 0) = 33.3333333f;
  m1(1, 1) = 33.3333333f;

  m2(0, 0) = 66.6666666f;
  m2(0, 1) = 66.6666666f;
  m2(1, 0) = 66.6666666f;
  m2(1, 1) = 66.6666666f;

  res = m1 + m2;

  actual(0, 0) = 99.9999999f;
  actual(0, 1) = 99.9999999f;
  actual(1, 0) = 99.9999999f;
  actual(1, 1) = 99.9999999f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, chained_plus_operator) {
  MatrixLib::Matrix res;
  MatrixLib::Matrix actual(2, 2);
  MatrixLib::Matrix m1(2, 2);
  m1(0, 0) = 33.3333333f;
  m1(0, 1) = 33.3333333f;
  m1(1, 0) = 33.3333333f;
  m1(1, 1) = 33.3333333f;

  res = m1 + m1 + m1;

  actual(0, 0) = 99.9999999f;
  actual(0, 1) = 99.9999999f;
  actual(1, 0) = 99.9999999f;
  actual(1, 1) = 99.9999999f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, plus_operator_empty) {
  MatrixLib::Matrix m1;
  MatrixLib::Matrix m2(2, 2);
  m2(0, 0) = 66.6666666f;
  m2(0, 1) = 66.6666666f;
  m2(1, 0) = 66.6666666f;
  m2(1, 1) = 66.6666666f;
  EXPECT_THROW(m1 + m2, MatrixLib::SegmentationException);
}

TEST(test, minus_operator) {
  MatrixLib::Matrix res;
  MatrixLib::Matrix actual(2, 2);
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix m2(2, 2);
  m1(0, 0) = 88.8888888f;
  m1(0, 1) = 88.8888888f;
  m1(1, 0) = 88.8888888f;
  m1(1, 1) = 88.8888888f;

  m2(0, 0) = 55.5555555f;
  m2(0, 1) = 55.5555555f;
  m2(1, 0) = 55.5555555f;
  m2(1, 1) = 55.5555555f;

  res = m1 - m2;

  actual(0, 0) = 33.3333333f;
  actual(0, 1) = 33.3333333f;
  actual(1, 0) = 33.3333333f;
  actual(1, 1) = 33.3333333f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, chained_minus_operator) {
  MatrixLib::Matrix res;
  MatrixLib::Matrix actual(2, 2);
  MatrixLib::Matrix m1(2, 2);
  m1(0, 0) = 33.3333333f;
  m1(0, 1) = 33.3333333f;
  m1(1, 0) = 33.3333333f;
  m1(1, 1) = 33.3333333f;

  res = m1 - m1 - m1;

  actual(0, 0) = -33.3333333f;
  actual(0, 1) = -33.3333333f;
  actual(1, 0) = -33.3333333f;
  actual(1, 1) = -33.3333333f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, minus_operator_empty) {
  MatrixLib::Matrix m1;
  MatrixLib::Matrix m2(1, 1);
  EXPECT_THROW(m1 - m2, MatrixLib::SegmentationException);
}

TEST(test, mult_operator) {
  MatrixLib::Matrix res;
  MatrixLib::Matrix actual(2, 2);
  MatrixLib::Matrix m1(2, 3);
  MatrixLib::Matrix m2(3, 2);
  m1(0, 0) = 22.2222222f;
  m1(0, 1) = 22.2222222f;
  m1(0, 2) = 22.2222222f;
  m1(1, 0) = 22.2222222f;
  m1(1, 1) = 22.2222222f;
  m1(1, 2) = 22.2222222f;

  m2(0, 0) = 22.2222222f;
  m2(1, 0) = 22.2222222f;
  m2(2, 0) = 22.2222222f;
  m2(0, 1) = 22.2222222f;
  m2(1, 1) = 22.2222222f;
  m2(2, 1) = 22.2222222f;

  res = m1 * m2;

  actual(0, 0) = 1481.4814785f;
  actual(0, 1) = 1481.4814785f;
  actual(1, 0) = 1481.4814785f;
  actual(1, 1) = 1481.4814785f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, chained_mult_operator) {
  MatrixLib::Matrix res;
  MatrixLib::Matrix actual(2, 2);
  MatrixLib::Matrix m1(2, 2);
  m1(0, 0) = 22.2222222f;
  m1(0, 1) = 22.2222222f;
  m1(1, 0) = 22.2222222f;
  m1(1, 1) = 22.2222222f;

  res = m1 * m1 * m1;

  actual(0, 0) = 43895.7474677f;
  actual(0, 1) = 43895.7474677f;
  actual(1, 0) = 43895.7474677f;
  actual(1, 1) = 43895.7474677f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, chained_mult_operator_wrong_size) {
  MatrixLib::Matrix m1(11, 5);
  MatrixLib::Matrix m2(5, 11);
  EXPECT_THROW(m1 * m1 * m2 * m1, MatrixLib::CalcException);
}

TEST(test, mult_operator_wrong_size) {
  MatrixLib::Matrix m1(2, 3);
  MatrixLib::Matrix m2(2, 3);
  EXPECT_THROW(m1 * m2, MatrixLib::CalcException);
}

TEST(test, mult_operator_empty) {
  MatrixLib::Matrix m1;
  MatrixLib::Matrix m2;
  EXPECT_THROW(m1 * m2, MatrixLib::SegmentationException);
}

TEST(test, mult_num_operator) {
  MatrixLib::Matrix res;
  MatrixLib::Matrix actual(2, 2);
  MatrixLib::Matrix m1(2, 2);
  float f = 3.3333333f;
  m1(0, 0) = 25.2525252f;
  m1(0, 1) = 25.2525252f;
  m1(1, 0) = 25.2525252f;
  m1(1, 1) = 25.2525252f;

  res = m1 * f;

  actual(0, 0) = 84.1750831f;
  actual(0, 1) = 84.1750831f;
  actual(1, 0) = 84.1750831f;
  actual(1, 1) = 84.1750831f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, mult_num_operator_empty) {
  MatrixLib::Matrix m1;
  float f = 3.3333333f;
  EXPECT_THROW(m1 * f, MatrixLib::SegmentationException);
}

TEST(test, plus_assignment_operator) {
  MatrixLib::Matrix res(2, 2);
  MatrixLib::Matrix m1(2, 2);
  m1(0, 0) = 25.2525252f;
  m1(0, 1) = 25.2525252f;
  m1(1, 0) = 25.2525252f;
  m1(1, 1) = 25.2525252f;

  res += m1;
  EXPECT_EQ(res == m1, true);
}

TEST(test, plus_assignment_operator_itself) {
  MatrixLib::Matrix res(2, 2);
  MatrixLib::Matrix actual(2, 2);
  res(0, 0) = 22.2222222f;
  res(0, 1) = 22.2222222f;
  res(1, 0) = 22.2222222f;
  res(1, 1) = 22.2222222f;

  res += res;

  actual(0, 0) = 44.4444444f;
  actual(0, 1) = 44.4444444f;
  actual(1, 0) = 44.4444444f;
  actual(1, 1) = 44.4444444f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, plus_assignment_operator_empty) {
  MatrixLib::Matrix res;
  MatrixLib::Matrix m1(2, 2);
  EXPECT_THROW(res += m1, MatrixLib::SegmentationException);
}

TEST(test, minus_assignment_operator) {
  MatrixLib::Matrix res(2, 2);
  MatrixLib::Matrix m1(2, 2);
  MatrixLib::Matrix actual(2, 2);
  m1(0, 0) = 25.2525252f;
  m1(0, 1) = 25.2525252f;
  m1(1, 0) = 25.2525252f;
  m1(1, 1) = 25.2525252f;

  res -= m1;

  actual(0, 0) = -25.2525252f;
  actual(0, 1) = -25.2525252f;
  actual(1, 0) = -25.2525252f;
  actual(1, 1) = -25.2525252f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, minus_assignment_operator_itself) {
  MatrixLib::Matrix res(2, 2);
  MatrixLib::Matrix actual(2, 2);
  res(0, 0) = 22.2222222f;
  res(0, 1) = 22.2222222f;
  res(1, 0) = 22.2222222f;
  res(1, 1) = 22.2222222f;

  res -= res;

  actual(0, 0) = 0.0f;
  actual(0, 1) = 0.0f;
  actual(1, 0) = 0.0f;
  actual(1, 1) = 0.0f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, minus_assignment_operator_empty) {
  MatrixLib::Matrix res;
  MatrixLib::Matrix m1(2, 2);
  EXPECT_THROW(res -= m1, MatrixLib::SegmentationException);
}

TEST(test, mult_assignment_operator) {
  MatrixLib::Matrix res(2, 3);
  MatrixLib::Matrix m1(3, 2);
  MatrixLib::Matrix actual(2, 2);
  res(0, 0) = 22.2222222f;
  res(0, 1) = 22.2222222f;
  res(0, 2) = 22.2222222f;
  res(1, 0) = 22.2222222f;
  res(1, 1) = 22.2222222f;
  res(1, 2) = 22.2222222f;

  m1(0, 0) = 22.2222222f;
  m1(1, 0) = 22.2222222f;
  m1(2, 0) = 22.2222222f;
  m1(0, 1) = 22.2222222f;
  m1(1, 1) = 22.2222222f;
  m1(2, 1) = 22.2222222f;

  res *= m1;

  actual(0, 0) = 1481.4814785f;
  actual(0, 1) = 1481.4814785f;
  actual(1, 0) = 1481.4814785f;
  actual(1, 1) = 1481.4814785f;
  EXPECT_EQ(res == actual, true);
  EXPECT_EQ(res == actual, true);
}

TEST(test, mult_assignment_operator_itself) {
  MatrixLib::Matrix res(2, 2);
  MatrixLib::Matrix actual(2, 2);
  res(0, 0) = 22.2222222f;
  res(0, 1) = 22.2222222f;
  res(1, 0) = 22.2222222f;
  res(1, 1) = 22.2222222f;

  res *= res;

  actual(0, 0) = 987.6543190f;
  actual(0, 1) = 987.6543190f;
  actual(1, 0) = 987.6543190f;
  actual(1, 1) = 987.6543190f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, mult_assignment_operator_wrong_size) {
  MatrixLib::Matrix res(2, 3);
  MatrixLib::Matrix m1(2, 3);
  EXPECT_THROW(res *= m1, MatrixLib::CalcException);
}

TEST(test, mult_assignment_operator_empty) {
  MatrixLib::Matrix res;
  MatrixLib::Matrix m1;
  EXPECT_THROW(res *= m1, MatrixLib::SegmentationException);
}

TEST(test, mult_num_assignment_operator) {
  MatrixLib::Matrix res(2, 2);
  float f = 3.3333333f;
  MatrixLib::Matrix actual(2, 2);
  res(0, 0) = 25.2525252f;
  res(0, 1) = 25.2525252f;
  res(1, 0) = 25.2525252f;
  res(1, 1) = 25.2525252f;

  res *= f;

  actual(0, 0) = 84.1750831f;
  actual(0, 1) = 84.1750831f;
  actual(1, 0) = 84.1750831f;
  actual(1, 1) = 84.1750831f;
  EXPECT_EQ(res == actual, true);
}

TEST(test, mult_num_assignment_operator_empty) {
  MatrixLib::Matrix res;
  float f = 3.3333333f;
  EXPECT_THROW(res *= f, MatrixLib::SegmentationException);
}