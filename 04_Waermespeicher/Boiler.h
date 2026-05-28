#ifndef BOILER_H
#define BOILER_H
#include <stdexcept>
#include <string>
#include "Point.h"
#include "Burner.h"
#include "Stages.h"


class ExceptionBoilerOverheating : public std::exception{       //Von std::exception abgeleitete Klasse
public:
    mutable std::string Fehlermeldung;      //Gehört nicht zum logischen Zustand des Objekts
                                            //Als const gekennzeichnete Methoden dürfen solche
    double BoilerTemperature;               //Attribute trotzdem ändern
    double BoilerContent;
    double AddedHeat;
    Boiler* FailingBoiler;

    ExceptionBoilerOverheating (double BoilerTemperature, double BoilerContent,
                                double AddedHeat, Boiler* FailingBoiler);

    const char* what() const noexcept;
};


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

        Boiler& operator=(const Boiler& rhs);

        void addContent(double MediaTemperature, double MediaAmount);
        void addHeat(double HeatAmount);
        void extractMedium(double AmountRequested,
                           double& AmountDelivered, double& Temperature);
        void show();
        void activateHeating(double Amount);
        bool contains(const Point& Pos);


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
