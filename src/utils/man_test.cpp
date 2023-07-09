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