#include <string>
#include <sstream>
#include "WinAdapt.h"
#include "Stages.h"
#include "Point.h"
#include "Boiler.h"
#include "Burner.h"
using std::stringstream;


Boiler::Boiler()
                :ContentTemperature(20), ContainedVolume(100),
                Position(50,50), Dimension(50,50), Name("Hans"),
                BBurner(new Burner(this, "Erwin"))
                    //Objekt vom Typ Burner wird erzeugt, damit der Pointer vom Objekt
                    //vom Typ Boiler, das gerade generiert wird, auf dieses zeigen kann
                {}


Boiler::Boiler(const std::string& uName, Point uPosition, Point uDimension,
               double uContainedVolume, double uContentTemperature)
               :ContentTemperature(uContentTemperature), ContainedVolume(uContainedVolume),
                Position(uPosition), Dimension(uDimension), Name(uName), BBurner(new Burner(this, "Erwin"))
                {}
                    //ein string kann auch über die Initialisierungsliste zugewiesen werden
                    //(im Gegensatz zu einem char-Array)

Boiler::Boiler(const Boiler& Quelle)
               :ContentTemperature(Quelle.ContentTemperature), ContainedVolume(Quelle.ContainedVolume),
                Position(Quelle.Position), Dimension(Quelle.Dimension), Name(Quelle.Name),
                BBurner(new Burner(this, Quelle.BBurner->Name))
                {}


Boiler::~Boiler(){
    delete this->BBurner;
}


Boiler& Boiler::operator=(const Boiler& rhs){
    ContentTemperature = rhs.ContentTemperature;
    ContainedVolume = rhs.ContainedVolume;
    Position = rhs.Position;
    Dimension = rhs.Dimension;
    Name = rhs.Name;

    delete BBurner;     //bisherigen Burner vom Objekt, das hier überschrieben wird, freigeben
    BBurner = new Burner(this, rhs.BBurner->Name);  //Deep copy

    return *this;
}


void Boiler::addContent(double MediaTemperature, double MediaAmount){
    ContentTemperature =
    (ContentTemperature*ContainedVolume + MediaTemperature*MediaAmount)/(ContainedVolume + MediaAmount);

    ContainedVolume += MediaAmount;
}


void Boiler::addHeat(double HeatAmount){
    double BackupT = ContentTemperature;
    ContentTemperature += HeatAmount/(ContainedVolume*4.17);

    if(ContentTemperature > 3000){
        ContentTemperature = BackupT;
        throw ExceptionBoilerOverheating(BackupT, ContainedVolume, HeatAmount, this);
    }   //Exception-Objekt wird hier erzeugt
}


void Boiler::activateHeating(double Amount){
    if(BBurner != nullptr){
        BBurner->feedFuel(Amount);
    }
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

    BBurner->show();
}


bool Boiler::contains(const Point& Pos){
    if(BBurner->contains(Pos) == true){     //Prüfe, ob Mausklick im Bereich von Burner ist
        return true;
    }
    if((Pos.X >= Position.X)&&(Pos.X <= (Position.X + Dimension.X))){       //Prüfe, ob Mausklick im
        if((Pos.Y >= Position.Y)&&(Pos.Y <= (Position.Y + Dimension.Y))){   //Bereich von Boiler ist
            return true;
        }
    }
    return false;
}


void Boiler::extractMedium(double AmountRequested, double& AmountDelivered, double& Temperature){
    Temperature = ContentTemperature;

    if(AmountRequested <= ContainedVolume){     //Menge kann bereitgestellt werden
        ContainedVolume -= AmountRequested;
        AmountDelivered = AmountRequested;
    }
    else{                                       //es wird mehr gefordert als da ist
        AmountDelivered = ContainedVolume;
        ContainedVolume = 0;
    }
}


ExceptionBoilerOverheating::ExceptionBoilerOverheating(double uBoilerTemperature,
                        double uBoilerContent, double uAddedHeat, Boiler* uFailingBoiler)
                        :BoilerTemperature(uBoilerTemperature), BoilerContent(uBoilerContent),
                         AddedHeat(uAddedHeat), FailingBoiler(uFailingBoiler)
                         {}


const char* ExceptionBoilerOverheating::what() const noexcept{
    std::stringstream Zeichenkette;
    Zeichenkette << "Betroffener Kessel: " << FailingBoiler->Name << ";   Temperatur vor Unfall: "
                 << BoilerTemperature << "Grad;   Fuellstand:" << BoilerContent
                 << "l;   zugef. Energie: " << AddedHeat << "kJ";

    Fehlermeldung = Zeichenkette.str();
    return Fehlermeldung.c_str();
}
