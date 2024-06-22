#include "Course.h"
#include <gtest/gtest.h>

TEST(Course, defaultConstructor) {
    Course c;

    EXPECT_EQ(c.id, 0);
    EXPECT_EQ(c.name, "");
    EXPECT_EQ(c.credits, 0);
}

TEST(Course, parameterizedConstructor) {
    Course c(1, "C++", 3);

    EXPECT_EQ(c.id, 1);
    EXPECT_EQ(c.name, "C++");
    EXPECT_EQ(c.credits, 3);
}

TEST(Course, equaliltyOperator) {
    Course c1(1, "C++", 3);
    Course c2(1, "C++", 3);
    EXPECT_TRUE(c1 == c2);
}

TEST(Course, inequaliltyOperator) {
    Course c1(1, "C++", 3);
    Course c2(2, "Java", 3);
    EXPECT_TRUE(c1 != c2);
}

TEST(Student, ostreamOperator) {
    Course c1(1, "C++", 3);
    std::string expected = "Course ID: 1, Name: C++, Credits: 3";
    testing::internal::CaptureStdout();
    std::cout << c1;
    std::string actual = testing::internal::GetCapturedStdout();
}
