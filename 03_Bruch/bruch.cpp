#include "bruch.h"

Bruch::Bruch(int z, int n)
        :Zaehler(z), Nenner(n)
    {}


void Bruch::print(std::ostream& os) const{
    os << "(" << Zaehler << "/" << Nenner << ")";
}

void Bruch::print(std::ostream& os, int Precision) const{
int Zaehlerh = Zaehler;

int Stelle = Zaehlerh/Nenner;
Zaehlerh = Zaehlerh - (Stelle*Nenner);
os << Stelle << ".";

int Rest;

for (int i=0; i<Precision; i++){
    Rest = Zaehlerh%Nenner;
    Zaehlerh = 10*Rest;
    Stelle = Zaehlerh/Nenner;
    Zaehlerh = Zaehlerh - (Stelle*Nenner);

    os << Stelle;
}
}

std::ostream& operator<<(std::ostream& os, const Bruch& b){
    b.print(os);
    return os;
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
