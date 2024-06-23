# Add subdirectories for tests
add_subdirectory(studentTest)
add_subdirectory(teacherTest)

enable_testing()

# Include GoogleTest
include(GoogleTest)

# Add tests
foreach(TEST ${TESTS})
    gtest_discover_tests(${TEST})
endforeach()
