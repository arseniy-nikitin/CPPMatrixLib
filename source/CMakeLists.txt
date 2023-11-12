set(LIB_NAME matrix_oop)
set(CMAKE_CXX_STANDARD 17)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} MATRIX_SRCS)
file(GLOB_RECURSE MATRIX_HEADER includes/*.h)

add_library(${LIB_NAME} STATIC
  ${MATRIX_SRCS}
  ${MATRIX_HEADER}
)

add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-conversion
        -Wsign-promo
)