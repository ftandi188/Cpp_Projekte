#include "Geschoss.h"
#include "WinAdapt.h"

Geschoss::Geschoss(Point uposition, Point usize, double uv0, int ucounter)
                :Paintable(uposition, usize), BackupOben(uposition), BackupUnten(uposition), v0(uv0), counter(ucounter)
{}


void Geschoss::paint(){
    Elli(position.X, position.Y, position.X + size.X, position.Y - size.Y);
}
