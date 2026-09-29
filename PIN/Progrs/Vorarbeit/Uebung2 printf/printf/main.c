#include <stdio.h>


int main()
{
    //Um Hochkommata auszugeben, muss davor \ geschrieben werden
    printf("Deine Eltern sind \"Geschwister\"!\n");

    //Man kann den Text auch über mehrere Zeilen schreiben, wenn man zum Umbruch \ schreibt
    printf("Deine Eltern \
sind \
Geschwister!\n");

    //Zur Ausgabe von Zahlen gibt es 2 Optionen: Option 1 (einfach)
    printf("Deine Eltern sind 2 Geschwister\n");

    //Option 2
    //%d dient hier als Platzhalter für einen Zahlenwert und zeigt gleichzeitig an, dass es eine Dezimalzahl ist
    printf("Deine Eltern sind %d Geschwister\n", 2);

    //Man kann mehrere Platzhalter in eine Funktion packen, die anzuzeigende Zahl kann auch durch einen Term ausgedrückt werden
    printf("Deine Eltern sind %d Geschwister, dein Vater ist %d\n", 2, (11+8)*2);

    //Solche Platzhalter heißen Formatanweisungen bzw. Formatzeichen, sie beginnen immer mit %
    return 0;
}
