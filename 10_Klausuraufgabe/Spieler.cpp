#include "Spieler.h"
#include "Katapult.h"
#include "Game.h"
#include <vector>
#include "Mauerstueck.h"
#include "Point.h"

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

    //Game::checkCollision();
}

void Spieler::checkCollision(Spieler* Gegner){
    std::vector<Point> zupruefendePunkte;
    Point TempPunkt(1,1);
    int AnzahlPunkte;
    //int Index = 0;      //Um ausgewählte Mauerstücke zu löschen
    bool Getroffen = 0;

    double Geschossradius = 0.5*(MeinKatapult->Schussobjekt->size.X);
    Point Geschossmitte(1,1);


    for(int m=0; m < Gegner->MeineMauer->Steine.size(); ){       //Durchlaufen der Mauerstücke
        Mauerstueck* TempM = Gegner->MeineMauer->Steine[m];

        Geschossmitte.X = MeinKatapult->Schussobjekt->position.X + 0.5*(MeinKatapult->Schussobjekt->size.X);
        Geschossmitte.Y = MeinKatapult->Schussobjekt->position.Y - 0.5*(MeinKatapult->Schussobjekt->size.X);


        AnzahlPunkte = (TempM->size.Y)/3;
        if(AnzahlPunkte < 2){
            AnzahlPunkte = 2;
        }
        //Ermittlung, wie viele Stellen geprüft werden müssen abhängig von der vertikalen Ausdehnung eines Mauerstücks (mindestens die Ecken, also 2)

        for(int i=0; i < AnzahlPunkte; i++){                //Berechnung der Punkte
            float Faktor = float(i)/(AnzahlPunkte-1);
            TempPunkt.X = TempM->position.X;
            TempPunkt.Y = TempM->position.Y + Faktor * TempM->size.Y;

            zupruefendePunkte.push_back(TempPunkt);
        }
        for(int i=0; i < AnzahlPunkte; i++){                //Punkte auf der anderen Seite der Mauer
            float Faktor = float(i)/(AnzahlPunkte-1);
            TempPunkt.X = TempM->position.X + TempM->size.X;
            TempPunkt.Y = TempM->position.Y + Faktor * TempM->size.Y;

            zupruefendePunkte.push_back(TempPunkt);
        }
        //nun sind im vector alle Punkte, die geprüft werden sollen, abgelegt
        //Nun: Vergleich dieser Punkte mit Geschossposition

        for(auto p : zupruefendePunkte){
            if((p - Geschossmitte).abs() < Geschossradius){
                Gegner->MeineMauer->Steine.erase(Gegner->MeineMauer->Steine.begin() + m);
                Getroffen = 1;
                break;              //Wurde eine Überschneidung festgestellt, wird das entsprechende Mauerstück entfernt
            }                       //und die Schleife beendet (also zum nächsten Mauerstück übergegangen)
        }
        if(Getroffen == 0){
            m++;
        }
        Getroffen = 0;
        zupruefendePunkte.clear();
    }
}
