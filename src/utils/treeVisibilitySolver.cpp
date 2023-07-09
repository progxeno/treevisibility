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
#include "resources/angles.hpp"
#include <cmath>

std::pair<double, double>
TreeVisibilitySolver::calculateVisibleTrees(const Map &map) {
  const Man &man = map.getMan();
  const std::vector<Tree> &trees = map.getTrees();

  double best_orientation_x = 0.0;
  double best_orientation_y = 0.0;
  int max_visible_trees = 0;

  // Try all possible orientations.
  for (double angle = -Angles::kViewFactor * man.getViewAngle();
       angle <= Angles::kViewFactor * man.getViewAngle();
       angle += Angles::kStep) {
    double orientation_x = std::cos(angle);
    double orientation_y = std::sin(angle);
    int visible_trees = 0;

    // Count visible trees.
    for (const Tree &tree : trees) {
      double tree_x = tree.getX() - man.getX();
      double tree_y = tree.getY() - man.getY();
      double dot_product = tree_x * orientation_x + tree_y * orientation_y;

      if (dot_product > 0) {
        visible_trees++;
      }
    }

    // Keep track of the best orientation.
    if (visible_trees > max_visible_trees) {
      max_visible_trees = visible_trees;
      best_orientation_x = orientation_x;
      best_orientation_y = orientation_y;
    }
  }

  return std::make_pair(best_orientation_x, best_orientation_y);
}