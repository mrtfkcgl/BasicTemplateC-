#include <gtest/gtest.h>
#include "teacher/teacher.hpp"

TEST(TeacherTest, Teach) {
    Teacher t;
    // This will output "Teaching" to the console
    t.teach();
    // Example assertion to check if true
    ASSERT_TRUE(true);
}
