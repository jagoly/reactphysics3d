cmake_minimum_required(VERSION 3.0)
project(RP3D_TESTS CXX)

include_directories("../include/rp3d" ".")

file(GLOB_RECURSE TESTS_SOURCE_FILES "tests/*.h")
list(APPEND TESTS_SOURCE_FILES "main.cpp" "Test.h" "Test.cpp" "TestSuite.h" "TestSuite.cpp")

add_executable(rp3d_tests ${TESTS_SOURCE_FILES})
target_link_libraries(rp3d_tests reactphysics3d)

add_test(Test rp3d_tests)
