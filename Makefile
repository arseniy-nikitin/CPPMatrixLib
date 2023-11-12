all: generate-build s21_matrix_oop.a test

generate-build:
	cmake -S . -B build

s21_matrix_oop.a:
	cmake --build build -j 12

test:
	ctest --test-dir build --output-on-failure -j 12

clean:
	rm -rf build

leaks:
	leaks -atExit -- ./build/tests/tests_main

clang-replace:
	clang-format --style=Google  ${shell find ./source -name "*.cc"} ${shell find ./source -name "*.h"} -i

clang-check:
	clang-format --style=Google  ${shell find ./source -name "*.cc"} ${shell find ./source -name "*.h"} -n