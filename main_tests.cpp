#include <gtest/gtest.h>
#include "main.cpp"
#include <iostream>


TEST(VectorTest, test1) {
    Point a = Point(2, 0);
    Point b = Point(1, 0);
    Vector c = Vector(-1, 0);
    EXPECT_EQ(Vector(0, 0), Vector(b, a) + c);
}

TEST(VectorTest, test2) {
    Vector c = Vector(-1, 0);
    EXPECT_EQ(1, c.len());
}

TEST(LineTest, test1) {
    Point a = Point(0, 0);
    Point b = Point(1, -1);
    Line c = Line(-1, -1, 0);
    EXPECT_EQ(c, get_line(a, b));
}
