#include "Pipeline.h"
#include "WinAdapt.h"
#include "Point.h"

Pipeline::Pipeline(Boiler* uSource, Boiler* uTarget, int uPumpSize)         //Konstruktor
                :Source(uSource), Target(uTarget), PumpSize(uPumpSize)
                {}


void Pipeline::transferMedium(double Amount){
    Source->ContainedVolume -= Amount;
    Target->ContainedVolume += Amount;
}


void Pipeline::show(){
    Point Startpunkt(1,1);
    Point Endpunkt(1,1);

    Startpunkt.X = Source->Position.X + (Source->Dimension.X)/2;
    Startpunkt.Y = Source->Position.Y + (Source->Dimension.Y)/2;

    Endpunkt.X = Target->Position.X + (Target->Dimension.X)/2;
    Endpunkt.Y = Target->Position.Y + (Target->Dimension.Y)/2;

    Rect(Startpunkt.X, Startpunkt.Y, Endpunkt.X, Endpunkt.Y);
    Elli((Startpunkt.X+Endpunkt.X-PumpSize)/2, (Startpunkt.Y+Endpunkt.Y-PumpSize)/2,
         (Startpunkt.X+Endpunkt.X+PumpSize)/2, (Startpunkt.Y+Endpunkt.Y+PumpSize)/2);
}

bool Pipeline::contains(Point& Clickposition){
    Point Startpunkt(1,1);
    Point Endpunkt(1,1);
    Startpunkt.X = Source->Position.X + (Source->Dimension.X)/2;
    Startpunkt.Y = Source->Position.Y + (Source->Dimension.Y)/2;
    Endpunkt.X = Target->Position.X + (Target->Dimension.X)/2;
    Endpunkt.Y = Target->Position.Y + (Target->Dimension.Y)/2;

    Point Mitte((Startpunkt.X+Endpunkt.X)/2, (Startpunkt.Y+Endpunkt.Y)/2);

    if((Mitte-Clickposition).abs() < PumpSize/2){
        return true;
    }
    return false;
}


