#include <gtest/gtest.h>
#include "student/student.hpp"

TEST(StudentTest, Study) {
    Student s;
    // This will output "Studying" to the console
    s.study();
    // Example assertion to check if true
    ASSERT_TRUE(false);
}
