add_library(implementations src/fileManipulator.cpp src/quadraticEquation.cpp src/stringLib.cpp)
target_include_directories(implementations PUBLIC include)

add_executable(tests_for_legacy uts/fileManipulatorTest.cpp uts/findInVectorTest.cpp uts/quadraticEquationTest.cpp uts/stableSortTest.cpp uts/stringLibTest.cpp)
target_link_libraries(tests_for_legacy gmock_main gtest gmock implementations)