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
        Burner(Boiler* MyBoiler, const string& Name, const Point& Position=Point(-1, -1));
        void feedFuel(double Amount);
        void show();
    protected:

    private:
        std::string Name;
        Point Position;
        Boiler* MyBoiler;
        double ConsumedFuel;
        Point ActualDimension;
        Point ActualPosition;
        void updateCoordinates();
};

#endif
