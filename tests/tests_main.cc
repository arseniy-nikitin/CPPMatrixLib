#include <gtest/gtest.h>
#include "constructors_tests.cc"
#include "operator_overloads_tests.cc"
#include "transformations_tests.cc"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}