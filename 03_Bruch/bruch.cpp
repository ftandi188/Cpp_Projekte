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

Bruch Bruch::operator-() const{
    Bruch NegBruch(*this);
    NegBruch.Zaehler = - NegBruch.Zaehler;
    return NegBruch;
}

Bruch Bruch::operator~() const{
    Bruch Kehrbruch(*this);
    int Zwischenspeicher = Zaehler;
    Kehrbruch.Zaehler = Kehrbruch.Nenner;
    Kehrbruch.Nenner = Zwischenspeicher;
    return Kehrbruch;
}

Bruch Bruch::operator*(const Bruch& rhs) const{    //Multiplizieren von 2 Brüchen
    Bruch Produkt(*this);
    (Produkt.Zaehler) *= (rhs.Zaehler);
    (Produkt.Nenner) *= (rhs.Nenner);
    return Produkt;
}

Bruch Bruch::operator*(int& rhs) const{        //Multiplizieren Bruch und int, int steht rechts
    Bruch Produkt(*this);
    Produkt.Zaehler *= rhs;
    return Produkt;
}

Bruch operator* (int lhs, const Bruch& rhs){       //Multiplizieren Bruch und int, int steht links
    int z = rhs.getZaehler();
    int n = rhs.getNenner();
    z *= lhs;

    Bruch Produkt(z,n);
    return Produkt;
}


int Bruch::getZaehler() const{
    return Zaehler;
}

int Bruch::getNenner() const{
    return Nenner;
}

double Bruch::getValue(){
    return (double)Zaehler/Nenner;
}
