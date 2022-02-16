cmake_minimum_required(VERSION 3.12)
project(NaTddExercises CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

add_subdirectory(project1)
add_subdirectory(project2)

enable_testing()
add_test(TiTaToTests project2/TiTaToTests)
add_test(tests_for_legacy project1/tests_for_legacy)

add_custom_target(tests1
                  COMMAND "./project1/tests_for_legacy"
                  DEPENDS tests_for_legacy)

add_custom_target(tests2
                  COMMAND "./project2/TiTaToTests"
                  DEPENDS TiTaToTests)
