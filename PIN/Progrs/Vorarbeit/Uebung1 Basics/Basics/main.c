
//Befehl für den Präprozessor, die Ein-/Ausgabebibliothek einzubinden

#include <stdio.h>

//Main ist die Hauptfunktion des Programms, beim Ablauf wird in sie als erstes gesprungen (Einsprungspunkt bzw. program startup)
//Die geschweiften Klammern legen Anfang und Ende der Main-Funktion fest, alles dazwischen nennt man Anweisungsblock
int main(void)
{
    //Folgende Variante bietet sich für mehrzeilige Kommentare an
    /*
    Die Funktion printf ist in der eingebundenen Bibliothek deklariert
    Der auszugebende Text muss zwischen doppelten Hochkommata stehen
    Die Endung \n löst in der Ausgabebox einen Zeilenumsprung aus
    Dies ist ein sogenanntes Metazeichen, es gibt noch einige weitere
    */

    printf("Deine Eltern sind Geschwister\n");

    //Der Rückgabewert 0 signalisiert, dass das Programm sauber beendet wurde
    return 0;
}
