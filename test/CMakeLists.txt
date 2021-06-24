include_directories(SOURCE_DIR)

# add new test files here
set(TEST_FILES utils_test.cpp)

add_executable(test ${TEST_FILES})
target_link_libraries(test IntermediateLib gtest gtest_main)