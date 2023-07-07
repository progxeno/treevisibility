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