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
    void print(std::ostream& os);       //Parameter ist Referenz auf den Stream, mit dem die Ausgabe erfolgt

};


#endif // BRUCH_H_INCLUDED
