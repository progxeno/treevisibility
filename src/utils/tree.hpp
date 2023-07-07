#ifndef TREE_HPP
#define TREE_HPP

class Tree {
public:
    Tree(double x, double y);

    double getX() const;
    double getY() const;

private:
    double x;
    double y;
};

#endif  // TREE_HPP
