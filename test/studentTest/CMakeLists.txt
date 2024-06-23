set(TEST_NAME "studentTest")

# Add test executable for student
add_executable(${TEST_NAME} test_student.cpp)
target_link_libraries(${TEST_NAME} PRIVATE student_lib gtest_main gmock_main)

# Add test
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

# Add to the list of tests
list(APPEND TESTS ${TEST_NAME})
