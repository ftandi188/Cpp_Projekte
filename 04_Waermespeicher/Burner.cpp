#include <algorithm>
#include <sstream>
using std::max;
#include "WinAdapt.h"
#include "Burner.h"
#include "Boiler.h"
#include "Point.h"
using std::stringstream;


Burner::Burner(Boiler* uMyBoiler, const string& uName, const Point& uPosition)
                :MyBoiler(uMyBoiler), Name(uName), Position(uPosition), ConsumedFuel(0.0),
                 ActualDimension(0.0, 0.0),ActualPosition(0.0, 0.0)
                 {
                    updateCoordinates();
                 }


void Burner::feedFuel(double Amount){       //Brennstoff in Litern
    if(MyBoiler != nullptr){
        MyBoiler->addHeat(Amount*34.3);         //Faktor: siehe Aufzeichnungen
        ConsumedFuel += Amount;
    }
}

void Burner::show(){
    updateCoordinates();
    Rect(ActualPosition.X, ActualPosition.Y, ActualPosition.X + ActualDimension.X, ActualPosition.Y + ActualDimension.Y);
    Text(ActualPosition.X + 10, ActualPosition.Y + 10, Name.c_str());

    stringstream Textbuffer;
    Textbuffer << "C:    " << ConsumedFuel;
    Text(ActualPosition.X + 10, ActualPosition.Y + ActualDimension.Y -25, Textbuffer.str().c_str());
}

void Burner::updateCoordinates(){
    ActualPosition.X = Position.X;
    ActualPosition.Y = Position.Y;

    if(MyBoiler == nullptr){        //Kein Kessel verbunden
        ActualDimension.X = 100;
        ActualDimension.Y = 100;


        if(ActualPosition.X < 0){
            ActualPosition.X = 0;
        }
        if(ActualPosition.Y < 0){
            ActualPosition.Y = 0;
        }
    }
    else{                           //Kessel verbunden
        ActualDimension.X = (MyBoiler->Dimension).X * 0.75;
        ActualDimension.Y = (MyBoiler->Dimension).Y * 0.25;
        if(ActualDimension.Y < 60){
            ActualDimension.Y = 60;
        }
                                        //Berechnungen: siehe Aufzeichnungen
        if(ActualPosition.X < 0){
            ActualPosition.X = (MyBoiler->Position).X + ((MyBoiler->Dimension).X - ActualDimension.X)/2;
        }
        if(ActualPosition.Y < 0){
            ActualPosition.Y = (MyBoiler->Position).Y + (MyBoiler->Dimension).Y;
        }
    }
}


bool Burner::contains(const Point& Pos){

    if((Pos.X >= ActualPosition.X)&&(Pos.X <= (ActualPosition.X + ActualDimension.X))){
        if((Pos.Y >= ActualPosition.Y)&&(Pos.Y <= (ActualPosition.Y + ActualDimension.Y))){
            return true;
        }
    }

    return false;
}

