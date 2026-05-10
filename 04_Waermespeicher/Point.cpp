#include "Point.h"
#include <cmath>

Point::Point(double X, double Y)        //Konstruktor
    :X(X), Y(Y)
{
}

Point Point::operator+(const Point& rhs) const      //Addition von 2 Koordinaten
{
    return Point(X+rhs.X, Y+rhs.Y);
}

Point Point::operator-(const Point& rhs) const      //Subtraktion: aufrufendes Objekt - Argument
{
    return Point(X-rhs.X, Y-rhs.Y);
}

Point Point::operator-() const          //Invertierung der Koordinaten
{
    return Point(-X, -Y);
}

Point Point::operator*(const double rhs) const      //Multiplikation mit einer Zahl
{
    return Point(X*rhs, Y*rhs);
}

Point Point::operator/(const double rhs) const      //Teilen durch eine Zahl
{
    return Point(X/rhs, Y/rhs);
}

Point Point::operator%(const double rhs) const      //Modulo-Operation, die mit übergebener
{                                                   //Zahl für X und Y separat gemacht wird
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

//entsprechende Operationen zu oben, nur dass hier das aufrufende Objekt verändert wird

Point& Point::operator+=(const Point& rhs){
    X+=rhs.X;
    Y+=rhs.Y;
    return *this;
}
Point& Point::operator-=(const Point& rhs){
    X-=rhs.X;
    Y-=rhs.Y;
    return *this;
}
Point& Point::operator*=(const double rhs){
    X*=rhs;
    Y*=rhs;
    return *this;
}
Point& Point::operator/=(const double rhs){
    X/=rhs;
    Y/=rhs;
    return *this;
}


bool Point::operator<(const Point& rhs) const   //Prüft,ob sowohl X- als auch Y-Koordinate vom aufrufenden
{                                               //Objekt kleiner sind als übergebene Vergleichskoordinate
    return X<rhs.X && Y<rhs.Y;
}

bool Point::operator<=(const Point& rhs) const  //entsprechend mit kleiner gleich
{
    return X<=rhs.X && Y<=rhs.Y;
}

bool Point::operator>(const Point& rhs) const   //entsprechend mit größer
{
    return X>rhs.X && Y>rhs.Y;
}

bool Point::operator>=(const Point& rhs) const  //entsprechend mit größer gleich
{
    return X>=rhs.X && Y>=rhs.Y;
}

bool Point::operator==(const Point& rhs) const  //Prüfe auf Gleichheit
{
    return X==rhs.X && Y==rhs.Y;
}

bool Point::operator!=(const Point& rhs) const  //Prüfe auf Ungleichheit
{
    return X!=rhs.X || Y!=rhs.Y;
}

//Vergleich der Länge des Vektors zur Koordinate mit übergebenem Betrag

bool Point::operator<(const double rhs) const{
    return abs() < rhs;
}
bool Point::operator<=(const double rhs) const{
    return abs() <= rhs;
}
bool Point::operator>(const double rhs) const{
    return abs() > rhs;
}
bool Point::operator>=(const double rhs) const{
    return abs() >= rhs;
}

double Point::abs() const       //Ermitteln der Vektorlänge
{
    return std::sqrt(X*X+Y*Y);
}


// globals

Point operator*(const double lhs, const Point& rhs)     //Multiplikation, wenn der Faktor zuerst kommt
{
    return Point(lhs*rhs.X, lhs*rhs.Y);
}
