#define CATCH_CONFIG_MAIN

#include "utils/tree_visibility.hpp"
#include "gtest/gtest.h"

// Define a structure to represent the input
struct In {
  double x;
  double y;
  double viewingAngle;
  double orientation;
  std::vector<Tree> trees;
};

// Define a structure to represent the expected output
struct Want {
  int count;
};

// Define a structure to represent the actual output
struct Got {
  int count;
};

// Define a test fixture
class CountVisibleTreesTest : public ::testing::Test {
protected:
  // Define any setup logic required for the tests
  void SetUp() override {
    // Initialize test data
    trees = {
        {1.5, 15.0},  // Tree 1 coordinates (x, y)
        {-2.15, 5.0}, // Tree 2 coordinates (x, y)
        {-4.0, -2.0}  // Tree 3 coordinates (x, y)
    };
  }

  // Define any teardown logic required for the tests
  void TearDown() override {
    // Clean up test data if needed
    trees.clear();
  }

  // Define any shared variables or helper functions
  std::vector<Tree> trees;
};

// Define a test case
TEST_F(CountVisibleTreesTest, CountVisibleTreesTest1) {
  // Define the input values for the test case
  In in{.x = 3.5,
        .y = 3.5,
        .viewingAngle = 50.0,
        .orientation = 74.9,
        .trees = trees};

  // Define the expected output
  Want want{.count = 1};

  // Call the function to be tested
  Got got{.count = CountVisibleTrees(in.x, in.y, in.viewingAngle,
                                     in.orientation, in.trees)};

  // Assert that the actual output matches the expected output
  EXPECT_EQ(got.count, want.count);
}

// // Run the tests
// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
