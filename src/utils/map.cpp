#include "utils/map.hpp"

Map::Map(const Man &man, const std::vector<Tree> &trees)
    : man(man), trees(trees) {}

const Man &Map::getMan() const { return man; }

const std::vector<Tree> &Map::getTrees() const { return trees; }
