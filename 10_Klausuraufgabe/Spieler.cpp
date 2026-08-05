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


void Spieler::abschiessen(double uv0, int Schrittweite){
    MeinKatapult->Schussobjekt->v0 = uv0;

    //Erster Teil: Katapult ausklappen

    if(MeinKatapult->Zustand == 0){
        MeinKatapult->Zustand = 1;

        if(MeinKatapult->Seite == 0){
            MeinKatapult->Schussobjekt->position += Point(11*(MeinKatapult->Skalierung), -10*(MeinKatapult->Skalierung));
            MeinKatapult->Schussobjekt->Backup = MeinKatapult->Schussobjekt->position;
        }
        if(MeinKatapult->Seite == 1){
            MeinKatapult->Schussobjekt->position += Point(-11*(MeinKatapult->Skalierung), -10*(MeinKatapult->Skalierung));
            MeinKatapult->Schussobjekt->Backup = MeinKatapult->Schussobjekt->position;
        }
        return;
    }

    //Zweiter Teil: Waagrechter Wurf
    int i = MeinKatapult->Schussobjekt->counter;

    if(MeinKatapult->Seite == 0){
        MeinKatapult->Schussobjekt->position.X += Schrittweite;
    }
    if(MeinKatapult->Seite == 1){
        MeinKatapult->Schussobjekt->position.X -= Schrittweite;
    }

    MeinKatapult->Schussobjekt->position.Y = MeinKatapult->Schussobjekt->Backup.Y + (5*Schrittweite*Schrittweite*i*i)/(uv0*uv0);

    MeinKatapult->Schussobjekt->counter++;
}
