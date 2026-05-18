#ifndef BOILER_H
#define BOILER_H
#include <stdexcept>
#include <string>
#include "Point.h"
#include "Burner.h"
#include "Stages.h"

class Boiler
{
    public:
        Boiler();
        Boiler(const std::string& Name,
               Point Position,
               Point Dimension=Point(130 ,100),     //Default-Parameter dürfen in der cpp
               double ContainedVolume = 0.0,        //kein zweites mal auftauchen!
               double ContentTemperature = 0.0
              );
        Boiler(const Boiler& Quelle);

        ~Boiler();

        void addContent(double MediaTemperature, double MediaAmount);
        void addHeat(double HeatAmount);
        void extractMedium(double AmountRequested,
                           double& AmountDelivered, double& Temperature);
        void show();


        double ContentTemperature;
        double ContainedVolume;
        Point Position;
        Point Dimension;
        std::string Name;
    protected:

    private:
        Burner* BBurner;
};


#endif // KESSEL_H
