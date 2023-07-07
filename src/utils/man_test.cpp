#include "utils/man.hpp"
#include <gtest/gtest.h>

// Define the input structure
struct TestCase {
  Man in;
  Man want;
  Man got;
};

// Define the unit tests for the Man class
TEST(ManTest, Getters) {
  TestCase testCases[] = {
      {Man(0.0, 0.0, 30.0), Man(0.0, 0.0, 30.0), Man(0, 0, 0)},
      {Man(-2.0, -1.0, 60.0), Man(-2.0, -1.0, 60.0), Man(0, 0, 0)},
      {Man(5.0, 3.5, 90.0), Man(5.0, 3.5, 90.0), Man(0, 0, 0)}};

  for (auto &testCase : testCases) {
    const Man &in = testCase.in;

    testCase.got = Man(in.getX(), in.getY(), in.getViewAngle());

    EXPECT_EQ(testCase.got.getX(), testCase.want.getX());
    EXPECT_EQ(testCase.got.getY(), testCase.want.getY());
    EXPECT_EQ(testCase.got.getViewAngle(), testCase.want.getViewAngle());
  }
}