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
#include <iostream>
#include <vector>

int main() {
  double man_x, man_y, man_view_angle;
  std::cin >> man_x >> man_y >> man_view_angle;

  int tree_number;
  std::cin >> tree_number;

  std::vector<Tree> trees;
  for (int i = 0; i < tree_number; ++i) {
    double tree_x, tree_y;
    std::cin >> tree_x >> tree_y;
    trees.emplace_back(tree_x, tree_y);
  }

  // Create the map.
  Man man(man_x, man_y, man_view_angle);
  Map map(man, trees);

  // Calculate the best orientation.
  TreeVisibilitySolver solver;
  std::pair<double, double> best_orientation =
      solver.calculateVisibleTrees(map);

  std::cout << best_orientation.first << " " << best_orientation.second
            << std::endl;

  return 0;
}