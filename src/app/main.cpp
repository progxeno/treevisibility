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

#include <iostream>
#include <vector>

#include "utils/tree_visibility.hpp"
#include "resources/constant.hpp"

int main() {
  double manX, manY, manViewAngle;
  int treeCount;
  std::cin >> manX >> manY >> manViewAngle >> treeCount;

  std::vector<Tree> trees(treeCount);
  for (int i = 0; i < treeCount; i++) {
    std::cin >> trees[i].x >> trees[i].y;
  }

  BestOrientation bestOrientation{0.0, std::numeric_limits<int>::min(), {}};

  std::vector<std::thread> threads;
  int numThreads = std::thread::hardware_concurrency();
  for (int i = 0; i < numThreads; i++) {
    threads.emplace_back(FindBestOrientation, manX, manY, manViewAngle,
                         Constant::kAngleStep, std::cref(trees),
                         std::ref(bestOrientation));
  }

  for (auto& thread : threads) {
    thread.join();
  }

  std::cout << bestOrientation.orientation << std::endl;

  return 0;
}
