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

