#include "Score.h"
#include <gtest/gtest.h>

TEST(Score, defaultConstructor) {
    Score s;
    ASSERT_EQ(s.studentID, 0);
    ASSERT_EQ(s.courseID, 0);
    ASSERT_EQ(s.score, 0);
}

TEST(Score, parameterizedConstructorPercentage) {
    Score s(1, 2, 90);
    ASSERT_EQ(s.studentID, 1);
    ASSERT_EQ(s.courseID, 2);
    ASSERT_EQ(s.score, 90);
}

TEST(Score, parameterizedConstructorLetter) {
    Score s(1, 2, 'A');
    ASSERT_EQ(s.studentID, 1);
    ASSERT_EQ(s.courseID, 2);
    ASSERT_EQ(s.score, 100);
}

TEST(Score, parameterizedConstructorPassFail) {
    Score s(1, 2, "Pass");
    ASSERT_EQ(s.studentID, 1);
    ASSERT_EQ(s.courseID, 2);
    ASSERT_EQ(s.score, 82);
}
