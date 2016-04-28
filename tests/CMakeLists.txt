# Minimum cmake version required
cmake_minimum_required(VERSION 2.6)

project(RP3D_TESTS)

INCLUDE_DIRECTORIES("../include/rp3d/")
INCLUDE_DIRECTORIES(${REACTPHYSICS3D_SOURCE_DIR}/test)

file (
  GLOB_RECURSE
  TESTS_SOURCE_FILES
  ${REACTPHYSICS3D_SOURCE_DIR}/test/*
)

add_executable(rp3d_tests ${TESTS_SOURCE_FILES})

target_link_libraries(rp3d_tests reactphysics3d)

add_test(Test rp3d_tests)
