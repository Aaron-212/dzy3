#include "Student.h"
#include <gtest/gtest.h>

TEST(Student, defaultConstructor) {
    Student s;
    EXPECT_EQ(s.id, 0);
    EXPECT_EQ(s.name, "");
}

TEST(Student, parameterizedConstructor) {
    Student s(1, "John");
    EXPECT_EQ(s.id, 1);
    EXPECT_EQ(s.name, "John");
}

TEST(Student, equaliltyOperator) {
    Student s1(1, "John");
    Student s2(1, "John");
    EXPECT_TRUE(s1 == s2);
}

TEST(Student, inequaliltyOperator) {
    Student s1(1, "John");
    Student s2(2, "Brown");
    EXPECT_TRUE(s1 != s2);
}

TEST(Student, ostreamOperator) {
    Student s1(1, "John");
    std::string expected = "Student ID: 1, Name: John";
    testing::internal::CaptureStdout();
    std::cout << s1;
    std::string actual = testing::internal::GetCapturedStdout();
}
