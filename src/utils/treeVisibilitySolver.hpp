#ifndef TREE_VISIBILITY_SOLVER_HPP
#define TREE_VISIBILITY_SOLVER_HPP

#include "utils/map.hpp"
#include <vector>

class TreeVisibilitySolver {
public:
  std::pair<double, double> calculateVisibleTrees(const Map &map);
};
#endif // TREE_VISIBILITY_SOLVER_HPP
