#ifndef PIPELINE_H_INCLUDED
#define PIPELINE_H_INCLUDED

#include "Boiler.h"
#include "Point.h"

class Pipeline{

    Boiler* Source;
    Boiler* Target;
    int PumpSize;

public:

    Pipeline(Boiler* Source, Boiler* Target, int PumpSize = 40);
    void transferMedium(double Amount);
    void show();
    bool contains(Point& Clickposition);
};



#endif // PIPELINE_H_INCLUDED
