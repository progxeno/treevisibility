#include "utils/tree.hpp"
#include <gtest/gtest.h>

// Define the input structure
struct In {
  double x;
  double y;
};

// Define the expected output structure
struct Want {
  double x;
  double y;
};

// Define the actual output structure
struct Got {
  double x;
  double y;
};

// Define the test case structure
struct TestCase {
  In in;
  Want want;
  Got got;
};

// Test fixture for the Tree class tests
class TreeTest : public ::testing::Test {
protected:
  // Define any shared variables or helper functions

  // Define any setup logic required for the tests
  void SetUp() override {
    // Initialize test data
  }

  // Define any teardown logic required for the tests
  void TearDown() override {
    // Clean up test data if needed
  }
};

// Define the test cases
TEST_F(TreeTest, GetX) {
  TestCase testCases[] = {
      {.in = {0.0, 0.0}, .want = {0.0, 0.0}, .got = {0.0, 0.0}},
      {.in = {1.5, 2.5}, .want = {1.5, 2.5}, .got = {0.0, 0.0}},
      {.in = {-2.0, 3.0}, .want = {-2.0, 3.0}, .got = {0.0, 0.0}}};

  for (auto &testCase : testCases) {
    Tree tree(testCase.in.x, testCase.in.y);
    testCase.got.x = tree.getX();
    testCase.got.y = tree.getY();

    EXPECT_EQ(testCase.got.x, testCase.want.x);
    EXPECT_EQ(testCase.got.y, testCase.want.y);
  }
}