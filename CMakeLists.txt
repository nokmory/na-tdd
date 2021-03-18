cmake_minimum_required(VERSION 3.10)
project(NaTddExercises CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(cmake/GTest.cmake)

add_subdirectory(project1)
add_subdirectory(project2)

enable_testing()
add_test(TiTaToTests project2/TiTaToTests)
add_test(tests_for_legacy project1/tests_for_legacy)