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

#ifndef SRC_UTILS_TREEVISIBILITYSOLVER_HPP_
#define SRC_UTILS_TREEVISIBILITYSOLVER_HPP_

#include "utils/map.hpp"
#include <vector>

class TreeVisibilitySolver {
public:
  /**
   * Calculates the visible trees based on the given map.
   *
   * @param map The map containing the man and trees.
   * @return A pair of doubles representing the best orientation for visibility
   * (x, y).
   */
  std::pair<double, double> calculateVisibleTrees(const Map &map);
};
#endif // SRC_UTILS_TREEVISIBILITYSOLVER_HPP_
