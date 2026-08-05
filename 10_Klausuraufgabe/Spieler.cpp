#include "Spieler.h"
#include "Katapult.h"

Spieler::Spieler(Point upositionM, Point usizeM, int uAnzahlM, Point upositionK, int uSkalierungK, bool uSeiteK, bool uZustandK)
                :MeineMauer(new Mauer(upositionM, usizeM, uAnzahlM)),
                 MeinKatapult(new Katapult(upositionK, uSkalierungK, uSeiteK, uZustandK))
{}


void Spieler::show(){
    MeineMauer->paint();
    MeinKatapult->paint();
}


void Spieler::abschiessen(double v0){
    if(MeinKatapult->Zustand == 0){
        MeinKatapult->Zustand = 1;

        if(MeinKatapult->Seite == 0){
            MeinKatapult->Schussobjekt->position += Point(11*(MeinKatapult->Skalierung), -10*(MeinKatapult->Skalierung));
        }
        if(MeinKatapult->Seite == 1){
            MeinKatapult->Schussobjekt->position += Point(-11*(MeinKatapult->Skalierung), -10*(MeinKatapult->Skalierung));
        }
    }
}
