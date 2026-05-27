#include "Pipeline.h"
#include "WinAdapt.h"
#include "Point.h"

Pipeline::Pipeline(Boiler* uSource, Boiler* uTarget, int uPumpSize)         //Konstruktor
                :Source(uSource), Target(uTarget), PumpSize(uPumpSize),
                 Startpunkt(1,1), Endpunkt(1,1), Mitte(1,1)
                {}


void Pipeline::transferMedium(double Amount){
    Source->ContainedVolume -= Amount;
    Target->ContainedVolume += Amount;
}


void Pipeline::getPoints(){
    Startpunkt.X = Source->Position.X + (Source->Dimension.X)/2;
    Startpunkt.Y = Source->Position.Y + (Source->Dimension.Y)/2;

    Endpunkt.X = Target->Position.X + (Target->Dimension.X)/2;
    Endpunkt.Y = Target->Position.Y + (Target->Dimension.Y)/2;

    Mitte.X = (Startpunkt.X+Endpunkt.X)/2;
    Mitte.Y = (Startpunkt.Y+Endpunkt.Y)/2;
}


void Pipeline::show(){
    getPoints();

    Line(Startpunkt.X, Startpunkt.Y, Endpunkt.X, Endpunkt.Y);
    Elli(Mitte.X - PumpSize/2, Mitte.Y - PumpSize/2, Mitte.X + PumpSize/2, Mitte.Y + PumpSize/2);
}

bool Pipeline::contains(Point Clickposition){
    getPoints();

    if((Mitte-Clickposition) < PumpSize/2){
        return true;
    }
    return false;
}


