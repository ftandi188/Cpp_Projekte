#include "Katapult.h"
#include "Geschoss.h"

Katapult::Katapult(Point uposition, int uSkalierung, bool uSeite, bool uZustand)
                :GestellKatapult(uposition, uSkalierung), Seite(uSeite), Zustand(uZustand),
                 Schussobjekt(nullptr)

{
    if(Seite == 0){
        Schussobjekt = new Geschoss(uposition + Point(-1*Skalierung,-10*Skalierung),Point(3*Skalierung, 3*Skalierung));
    }
    if(Seite == 1){
        Schussobjekt = new Geschoss(uposition + Point(18*Skalierung,-10*Skalierung),Point(3*Skalierung, 3*Skalierung));
    }
}


void Katapult::paint(){
    GestellKatapult::paint();
    Schussobjekt->paint();


    int Stuetzstellen[8];

    if(Seite == 0 && Zustand == 0){
            //Punkt 1
        Stuetzstellen[0] = position.X + 2*Skalierung;
        Stuetzstellen[1] = position.Y - 9*Skalierung;
            //Punkt 2
        Stuetzstellen[2] = position.X + 2*Skalierung;
        Stuetzstellen[3] = position.Y - 10*Skalierung;
            //Punkt 3
        Stuetzstellen[4] = position.X + 15*Skalierung;
        Stuetzstellen[5] = position.Y - 12*Skalierung;
            //Punkt 4
        Stuetzstellen[6] = position.X + 15*Skalierung;
        Stuetzstellen[7] = position.Y - 11*Skalierung;

        FillPoly(Stuetzstellen, 4);

        Elli(position.X + -1*Skalierung, position.Y - 9*Skalierung, position.X + 3*Skalierung, position.Y - 10*Skalierung);
    }
    if(Seite == 0 && Zustand == 1){
             //Punkt 1
        Stuetzstellen[0] = position.X + 9*Skalierung;
        Stuetzstellen[1] = position.Y - 20*Skalierung;
            //Punkt 2
        Stuetzstellen[2] = position.X + 10*Skalierung;
        Stuetzstellen[3] = position.Y - 20*Skalierung;
            //Punkt 3
        Stuetzstellen[4] = position.X + 12*Skalierung;
        Stuetzstellen[5] = position.Y - 7*Skalierung;
            //Punkt 4
        Stuetzstellen[6] = position.X + 11*Skalierung;
        Stuetzstellen[7] = position.Y - 7*Skalierung;

        FillPoly(Stuetzstellen, 4);

        Elli(position.X + 9*Skalierung, position.Y - 19*Skalierung, position.X + 10*Skalierung, position.Y - 23*Skalierung);
    }
    if(Seite == 1 && Zustand == 0){
             //Punkt 1
        Stuetzstellen[0] = position.X + 18*Skalierung;
        Stuetzstellen[1] = position.Y - 9*Skalierung;
            //Punkt 2
        Stuetzstellen[2] = position.X + 18*Skalierung;
        Stuetzstellen[3] = position.Y - 10*Skalierung;
            //Punkt 3
        Stuetzstellen[4] = position.X + 5*Skalierung;
        Stuetzstellen[5] = position.Y - 12*Skalierung;
            //Punkt 4
        Stuetzstellen[6] = position.X + 5*Skalierung;
        Stuetzstellen[7] = position.Y - 11*Skalierung;

        FillPoly(Stuetzstellen, 4);

        Elli(position.X + 17*Skalierung, position.Y - 9*Skalierung, position.X + 21*Skalierung, position.Y - 10*Skalierung);
    }
    if(Seite == 1 && Zustand == 1){
              //Punkt 1
        Stuetzstellen[0] = position.X + 11*Skalierung;
        Stuetzstellen[1] = position.Y - 20*Skalierung;
            //Punkt 2
        Stuetzstellen[2] = position.X + 10*Skalierung;
        Stuetzstellen[3] = position.Y - 20*Skalierung;
            //Punkt 3
        Stuetzstellen[4] = position.X + 8*Skalierung;
        Stuetzstellen[5] = position.Y - 7*Skalierung;
            //Punkt 4
        Stuetzstellen[6] = position.X + 9*Skalierung;
        Stuetzstellen[7] = position.Y - 7*Skalierung;

        FillPoly(Stuetzstellen, 4);

        Elli(position.X + 10*Skalierung, position.Y - 19*Skalierung, position.X + 11*Skalierung, position.Y - 23*Skalierung);
    }
}
