#include "bruch.h"

Bruch::Bruch(int z, int n)
        :Zaehler(z), Nenner(n)
    {}


void Bruch::print(std::ostream& os){
    os << "(" << Zaehler << "/" << Nenner << ")";
}

int Bruch::getZaehler(){
    return Zaehler;
}

int Bruch::getNenner(){
    return Nenner;
}

double Bruch::getValue(){
    return (double)Zaehler/Nenner;
}
