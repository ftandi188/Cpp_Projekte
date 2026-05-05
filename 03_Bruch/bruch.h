#ifndef BRUCH_H_INCLUDED
#define BRUCH_H_INCLUDED

#include <iostream>

class Bruch{
    int Zaehler;
    int Nenner;

public:
    Bruch(int z = 0, int n = 1);
    //Falls man beim Erstellen eines Objekts keinen oder nur einen Parameter
    //angibt, werden für die unbekannten Größen die Default-Werte genutzt
    void print(std::ostream& os) const;       //Parameter ist Referenz auf den Stream, mit dem die Ausgabe erfolgt
    void print(std::ostream& os, int Precision) const;

    Bruch operator-() const;
    Bruch operator~() const;
    Bruch operator*(const Bruch& rhs) const;
    Bruch operator*(int rhs) const;
    Bruch& operator*=(const Bruch& rhs);

    Bruch& operator++();
    Bruch operator++(int);

    bool operator==(Bruch rhs) const;

    int getZaehler() const;
    int getNenner() const;
    double getValue();

};

std::ostream& operator<<(std::ostream& os, const Bruch& b);

Bruch operator* (int lhs, const Bruch& rhs);

#endif // BRUCH_H_INCLUDED
