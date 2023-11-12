cmake_minimum_required(VERSION 3.18)
project(MATRIXOOP LANGUAGES CXX)
get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)
set(INTERFACE CMAKE_CXX_STANDARD 17)

option(MATRIXOOP_TESTING "Enable unit testing" ON)
option(MATRIXOOP_COVERAGE "Enable test coverage verification" OFF)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

include(cmake/UpdateSubmodules.cmake)
include(CTest)

add_subdirectory(external)
add_subdirectory(source)
add_subdirectory(tests)
