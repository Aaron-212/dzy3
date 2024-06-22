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
