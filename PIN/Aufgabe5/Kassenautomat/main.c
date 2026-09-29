#include <stdio.h>

float Zahlmittel[15] = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
int Anzahlen[15];

    struct Struktur{    //Struktur ist nun ein Datentyp so wie int, float usw.
    int Anzahl;
    float Betrag;
    } Werte;            //Anlegen eines solchen Datentyps namens Werte



struct Struktur NoetigeAnzahl(int i, struct Struktur Werte){
Werte.Anzahl = Werte.Betrag/Zahlmittel[i];

Werte.Betrag = Werte.Betrag - (Werte.Anzahl * Zahlmittel[i]);
return Werte;
}


void Ausgabe(float Startbetrag){
    int Eurobetrag = Startbetrag;
    int Centbetrag = (Startbetrag - Eurobetrag) * 100;

    printf("Der Gesamtbetrag von %d Euro und %d Cent kann aus\n", Eurobetrag, Centbetrag);

    for (int i = 0; i < 7; i++){
        printf("%d mal %5.0f-Euro-Schein\n", Anzahlen[i], Zahlmittel[i]);
    }
    for (int i = 7; i < 9; i++){
        printf("%d mal %5.0f-Euro-Muenze\n", Anzahlen[i], Zahlmittel[i]);
    }
    for (int i = 9; i < 15; i++){
        printf("%d mal %5.2f-Cent-Muenze\n", Anzahlen[i], Zahlmittel[i]);
    }
    printf("zusammengesetzt werden\n");
}

int main()
{
    Werte.Betrag = 42.46;
    float Startbetrag = Werte.Betrag;

    for (int i = 0; i < 15; i++){

    Werte = NoetigeAnzahl(i, Werte);
    Anzahlen[i] = Werte.Anzahl;
    }
    Ausgabe(Startbetrag);
}
