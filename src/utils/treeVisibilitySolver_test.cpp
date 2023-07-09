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

#include "utils/treeVisibilitySolver.hpp"

#include <gtest/gtest.h>

// Test fixture for the tree visibility tests
class TreeVisibilityTest : public ::testing::Test {
protected:
  // Define any setup logic required for the tests
  void SetUp() override {
    // Initialize test data
    trees = {Tree(0.0, 0.0), Tree(1.5, 15.0), Tree(-2.15, 5.0),
             Tree(-4.0, -2.0), Tree(3.0, 3.0)};
  }

  // Define any teardown logic required for the tests
  void TearDown() override {
    // Clean up test data if needed
    trees.clear();
  }

  // Define any shared variables or helper functions
  std::vector<Tree> trees;
};

// Define a structure to represent the input
struct In {
  Man man;
};

// Define a structure to represent the expected output
struct Want {
  std::pair<double, double> orientation;
};

// Define a structure to represent the actual output
struct Got {
  std::pair<double, double> orientation;
};
// Define a structure to represent the actual output
struct TestCase {
  In in;
  Want want;
  Got got;
};

// Define the test cases
TEST_F(TreeVisibilityTest, calculateVisibleTrees) {

  TestCase testCases[] = {{.in.man = {0.0, 0.0, 30.0},
                           .want.orientation = {-0.48, 0.88},
                           .got.orientation = {0.0, 0.0}},
                          {.in.man = {-2.0, -1.0, 60.0},
                           .want.orientation = {0.15, 0.99},
                           .got.orientation = {0.0, 0.0}},
                          {.in.man = {5.0, 3.5, 90.0},
                           .want.orientation = {-0.57, 0.82},
                           .got.orientation = {0.0, 0.0}}};

  // Iterate through each entry
  for (auto &testCase : testCases) {
    Map map(testCase.in.man, trees);

    TreeVisibilitySolver solver;
    testCase.got.orientation = solver.calculateVisibleTrees(map);

    EXPECT_NEAR(testCase.got.orientation.first, testCase.want.orientation.first,
                0.01);
    EXPECT_NEAR(testCase.got.orientation.second,
                testCase.want.orientation.second, 0.01);
  }
}