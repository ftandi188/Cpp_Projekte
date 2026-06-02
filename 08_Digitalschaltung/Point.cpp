#include "Point.h"
#include <cmath>

Point::Point(double X, double Y)
    :X(X), Y(Y)
{
}

Point Point::operator+(const Point& rhs) const
{
    return Point(X+rhs.X, Y+rhs.Y);
}

Point Point::operator-(const Point& rhs) const
{
    return Point(X-rhs.X, Y-rhs.Y);
}

Point Point::operator-() const
{
    return Point(-X, -Y);
}

Point Point::operator*(const double rhs) const
{
    return Point(X*rhs, Y*rhs);
}

Point Point::operator/(const double rhs) const
{
    return Point(X/rhs, Y/rhs);
}

Point Point::operator%(const double rhs) const
{
    Point Result=*this;
    while (Result.X>rhs)
    {
        Result.X-=rhs;
    }
    while (Result.Y>rhs)
    {
        Result.Y-=rhs;
    }
    return Result;
}

Point& Point::operator+=(const Point& rhs)
{
    X+=rhs.X;
    Y+=rhs.Y;
    return *this;
}

Point& Point::operator-=(const Point& rhs)
{
    X-=rhs.X;
    Y-=rhs.Y;
    return *this;
}

Point& Point::operator*=(const double rhs)
{
    X*=rhs;
    Y*=rhs;
    return *this;
}

Point& Point::operator/=(const double rhs)
{
    X/=rhs;
    Y/=rhs;
    return *this;
}

bool Point::operator<(const Point& rhs) const
{
    return X<rhs.X && Y<rhs.Y;
}

bool Point::operator<=(const Point& rhs) const
{
    return X<=rhs.X && Y<=rhs.Y;
}

bool Point::operator>(const Point& rhs) const
{
    return X>rhs.X && Y>rhs.Y;
}

bool Point::operator>=(const Point& rhs) const
{
    return X>=rhs.X && Y>=rhs.Y;
}

bool Point::operator==(const Point& rhs) const
{
    return X==rhs.X && Y==rhs.Y;
}

bool Point::operator!=(const Point& rhs) const
{
    return X!=rhs.X || Y!=rhs.Y;
}

bool Point::operator<(const double rhs) const
{
    return abs() < rhs;
}

bool Point::operator<=(const double rhs) const
{
    return abs() <= rhs;
}

bool Point::operator>(const double rhs) const
{
    return abs() > rhs;
}

bool Point::operator>=(const double rhs) const
{
    return abs() >= rhs;
}

double Point::abs() const
{
    return std::sqrt(X*X+Y*Y);
}

Point Point::scaleY(double Factor) const
{
    return Point(X, Y*Factor);
}

Point Point::scaleX(double Factor) const
{
    return Point(X * Factor, Y);
}

Point Point::scaleXY(double FactorX, double FactorY) const
{
    return Point(X * FactorX, Y * FactorY);
}

// globals

Point operator*(const double lhs, const Point& rhs)
{
    return Point(lhs*rhs.X, lhs*rhs.Y);
}

