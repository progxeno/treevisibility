#include "utils/map.hpp"
#include <gtest/gtest.h>

// Overload the equality operator for Tree
bool operator==(const Tree &lhs, const Tree &rhs) {
  return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

// Test fixture for the Map class tests
class MapTest : public ::testing::Test {
protected:
  void SetUp() override {
    // Set up the tree positions
    trees = {Tree(0.0, 0.0), Tree(1.5, 15.0), Tree(-2.15, 5.0),
             Tree(-4.0, -2.0), Tree(3.0, 3.0)};
  }

  void TearDown() override {
    // Clean up test data if needed
    trees.clear();
  }

  std::vector<Tree> trees;
};

// Define the input structure
struct In {
  Man man;
  std::vector<Tree> trees;
};

// Define the expected output structure
struct Want {
  Man man;
  std::vector<Tree> trees;
};

// Define the actual output structure
struct Got {
  Man man;
  std::vector<Tree> trees;
};

// Define the test case structure
struct TestCase {
  In in;
  Want want;
  Got got;
};

// Define the test cases
TEST_F(MapTest, ConstructorAndGetters) {
  TestCase testCases[] = {
      {.in = {.man = Man(0.0, 0.0, 30.0), .trees = trees},
       .want = {.man = Man(0.0, 0.0, 30.0), .trees = trees},
       .got = {.man = Man(0, 0, 0), .trees = std::vector<Tree>{}}},
      {.in = {.man = Man(-2.0, -1.0, 60.0), .trees = trees},
       .want = {.man = Man(-2.0, -1.0, 60.0), .trees = trees},
       .got = {.man = Man(0, 0, 0), .trees = std::vector<Tree>{}}}};

  for (auto &testCase : testCases) {
    const In &in = testCase.in;

    // Construct the Map object
    Map map(in.man, in.trees);

    // Verify the values using getters
    Got got = {.man = map.getMan(), .trees = map.getTrees()};

    // Verify the values
    EXPECT_EQ(got.man.getX(), testCase.want.man.getX());
    EXPECT_EQ(got.man.getY(), testCase.want.man.getY());
    EXPECT_EQ(got.man.getViewAngle(), testCase.want.man.getViewAngle());
    EXPECT_EQ(got.trees, testCase.want.trees);
  }
}