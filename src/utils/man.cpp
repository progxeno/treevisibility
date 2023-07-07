#include "utils/man.hpp"

Man::Man(double x, double y, double view_angle)
    : x(x), y(y), view_angle(view_angle) {}

double Man::getX() const { return x; }

double Man::getY() const { return y; }

double Man::getViewAngle() const { return view_angle; }
