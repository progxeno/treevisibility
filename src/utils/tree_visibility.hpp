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
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef TREE_VISIBILITY_HPP
#define TREE_VISIBILITY_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <limits>
#include <mutex>
#include <thread>

#include "resources/constant.hpp"

struct Tree {
  double x;
  double y;
};

struct BestOrientation {
  double orientation;
  int visibleTreesCount;
  std::mutex mutex;
};

double CalculateAngle(double x1, double y1, double x2, double y2);
int CountVisibleTrees(double manX, double manY, double manViewAngle,
                      double orientation, const std::vector<Tree>& trees);
void FindBestOrientation(double manX, double manY, double manViewAngle,
                         double angleStep, const std::vector<Tree>& trees,
                         BestOrientation& bestOrientation);

#endif  // TREE_VISIBILITY_HPP
