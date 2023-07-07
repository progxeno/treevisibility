#ifndef MAP_HPP
#define MAP_HPP

#include <vector>

#include "utils/man.hpp"
#include "utils/tree.hpp"

class Map {
public:
  Map(const Man &man, const std::vector<Tree> &trees);

  const Man &getMan() const;
  const std::vector<Tree> &getTrees() const;

private:
  Man man;
  std::vector<Tree> trees;
};

#endif // MAP_HPP
