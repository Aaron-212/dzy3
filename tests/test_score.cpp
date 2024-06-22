#include "Score.h"
#include <gtest/gtest.h>

TEST(Score, defaultConstructor) {
    Score s;
    ASSERT_EQ(s.courseID, 0);
    ASSERT_EQ(s.studentId, 0);
    ASSERT_EQ(s.value.percentage, 0);
}

TEST(Score, parameterizedConstructorPercentage) {
    Score s(1, 2, 90);
    ASSERT_EQ(s.courseID, 1);
    ASSERT_EQ(s.studentId, 2);
    ASSERT_EQ(s.percentage(), 90);
}

TEST(Score, parameterizedConstructorLetter) {
    Score s(1, 2, LetterGrade::A);
    ASSERT_EQ(s.courseID, 1);
    ASSERT_EQ(s.studentId, 2);
    ASSERT_EQ(s.value.letter, LetterGrade::A);
    ASSERT_EQ(s.percentage(), 100);
}

TEST(Score, parameterizedConstructorPassFail) {
    Score s(1, 2, PassFail::Pass);
    ASSERT_EQ(s.courseID, 1);
    ASSERT_EQ(s.studentId, 2);
    ASSERT_EQ(s.value.passFail, PassFail::Pass);
    ASSERT_EQ(s.percentage(), 82);
}
