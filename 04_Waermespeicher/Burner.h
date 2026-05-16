#ifndef BURNER_H
#define BURNER_H

#include <string>
#include "Point.h"
#include "Stages.h"

using std::string;

class Boiler;

class Burner
{
    public:
        std::string Name;
        Point Position;
        Boiler* MyBoiler;
        double ConsumedFuel;
        Point ActualDimension;
        Point ActualPosition;


        Burner(Boiler* MyBoiler, const string& Name, const Point& Position=Point(-1, -1));
        void feedFuel(double Amount);
        void show();
        void updateCoordinates();
        bool contains(const Point& Pos);

};

#endif
