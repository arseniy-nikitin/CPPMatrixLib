if (BUILD_TESTING)
  add_executable(tests_main tests_main.cc)
  target_link_libraries(tests_main matrix_oop GTest::gtest_main)

  include(GoogleTest)

  gtest_discover_tests(tests_main)
endif()