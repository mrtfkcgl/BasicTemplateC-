set(TEST_NAME "teacherTest")

# Add test executable for teacher
add_executable(${TEST_NAME} test_teacher.cpp)
target_link_libraries(${TEST_NAME} PRIVATE teacher_lib gtest_main)

# Add test
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

# Add to the list of tests
list(APPEND TESTS ${TEST_NAME})
