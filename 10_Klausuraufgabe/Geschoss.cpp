#include "Geschoss.h"
#include "WinAdapt.h"

Geschoss::Geschoss(Point uposition, Point usize)
                :Paintable(uposition, usize)
{}


void Geschoss::paint(){
    Elli(position.X, position.Y, position.X + size.X, position.Y - size.Y);
}
