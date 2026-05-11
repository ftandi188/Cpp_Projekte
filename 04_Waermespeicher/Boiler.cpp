#include <string>
#include <sstream>
#include "WinAdapt.h"
#include "Stages.h"
#include "Point.h"
#include "Boiler.h"
#include "Burner.h"
using std::stringstream;


Boiler::Boiler(const std::string& uName, Point uPosition, Point uDimension,
               double uContainedVolume, double uContentTemperature)
               :ContentTemperature(uContentTemperature), ContainedVolume(uContainedVolume),
                Position(uPosition), Dimension(uDimension), Name(uName)
                {}
                    //ein string kann auch über die Initialisierungsliste zugewiesen werden
                    //(im Gegensatz zu einem char-Array)


Boiler::~Boiler(){

}

void Boiler::addContent(double MediaTemperature, double MediaAmount){
    ContentTemperature =
    (ContentTemperature*ContainedVolume + MediaTemperature*MediaAmount)/(ContainedVolume + MediaAmount);

    ContainedVolume += MediaAmount;
}


void Boiler::addHeat(double HeatAmount){
    ContentTemperature += HeatAmount/(ContainedVolume*4.17);
}


void Boiler::show(){
    Rect(Position.X, Position.Y, Position.X + Dimension.X, Position.Y + Dimension.Y);
    Text(Position.X + 10, Position.Y + 10, Name.c_str());

    stringstream Textbuffer;

    Textbuffer << "T:    " << ContentTemperature;
    Text(Position.X + 10, Position.Y + Dimension.Y -40, Textbuffer.str().c_str());
    Textbuffer.str("");
    Textbuffer << "V:    " << ContainedVolume;
    Text(Position.X + 10, Position.Y + Dimension.Y -25, Textbuffer.str().c_str());
}
