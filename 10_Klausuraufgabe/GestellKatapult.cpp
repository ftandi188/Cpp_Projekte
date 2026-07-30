#include "GestellKatapult.h"
#include "Paintable.h"
#include "WinAdapt.h"

GestellKatapult::GestellKatapult(Point uposition, int uSkalierung)
                    :Paintable(uposition, uposition), Skalierung(uSkalierung)
{}


void GestellKatapult::paint(){
    FillCol(255,255,255);
    LineCol(100,100,100);

    Rect(position.X + 9*Skalierung, position.Y - 2*Skalierung, position.X + 11*Skalierung, position.Y - 10*Skalierung);
    Rect(position.X + 2*Skalierung, position.Y - 2*Skalierung, position.X + 18*Skalierung, position.Y - 4*Skalierung);

    //Räder zeichnen
    Elli(position.X, position.Y, position.X + 6*Skalierung, position.Y - 6*Skalierung);
    Elli(position.X + 14*Skalierung, position.Y, position.X + 20*Skalierung, position.Y - 6*Skalierung);

    Elli(position.X + 9*Skalierung, position.Y - 9*Skalierung, position.X + 11*Skalierung, position.Y - 11*Skalierung);

    Line(position.X, position.Y - 3*Skalierung, position.X + 6*Skalierung, position.Y - 3*Skalierung);
    Line(position.X + 14*Skalierung, position.Y - 3*Skalierung, position.X + 20*Skalierung, position.Y - 3*Skalierung);

    Line(position.X + 3*Skalierung, position.Y, position.X + 3*Skalierung, position.Y - 6*Skalierung);
    Line(position.X + 17*Skalierung, position.Y, position.X + 17*Skalierung, position.Y - 6*Skalierung);

    FillCol(100,100,100);
    Elli(position.X + 2*Skalierung, position.Y - 2*Skalierung, position.X + 4*Skalierung, position.Y - 4*Skalierung);
    Elli(position.X + 16*Skalierung, position.Y - 2*Skalierung, position.X + 18*Skalierung, position.Y - 4*Skalierung);
}
