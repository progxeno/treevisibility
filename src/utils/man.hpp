#ifndef MAN_HPP
#define MAN_HPP

class Man {
public:
    Man(double x, double y, double view_angle);

    double getX() const;
    double getY() const;
    double getViewAngle() const;

private:
    double x;
    double y;
    double view_angle;
};

#endif  // MAN_HPP
