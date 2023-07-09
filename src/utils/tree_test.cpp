// MIT License
//
// Copyright (c) 2023 progxeno
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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