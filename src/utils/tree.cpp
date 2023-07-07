#include "utils/tree.hpp"

Tree::Tree(double x, double y)
    : x(x), y(y) {}

double Tree::getX() const {
    return x;
}

double Tree::getY() const {
    return y;
}
