#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point(double X, double Y);
    double X;
    double Y;
    Point operator+(const Point& rhs) const;
    Point operator-(const Point& rhs) const;
    Point operator-() const;
    Point operator*(const double rhs) const;
    Point operator/(const double rhs) const;
    Point operator%(const double rhs) const;
    Point& operator+=(const Point& rhs);
    Point& operator-=(const Point& rhs);
    Point& operator*=(const double rhs);
    Point& operator/=(const double rhs);
    bool operator<(const Point& rhs) const;
    bool operator<=(const Point& rhs) const;
    bool operator>(const Point& rhs) const;
    bool operator>=(const Point& rhs) const;
    bool operator!=(const Point& rhs) const;
    bool operator==(const Point& rhs) const;
    bool operator<(const double rhs) const;
    bool operator<=(const double rhs) const;
    bool operator>(const double rhs) const;
    bool operator>=(const double rhs) const;
    double abs() const;
    Point scaleY(double Factor) const;
    Point scaleX(double Factor) const;
    Point scaleXY(double FactorX, double FactorY) const;
};

Point operator*(const double lhs, const Point& rhs);


#endif // POINT_H
