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