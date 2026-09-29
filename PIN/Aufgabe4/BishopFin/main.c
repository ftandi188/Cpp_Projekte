#include <stdio.h>

#define HEIGHT 9
#define WIDTH 17

#define MAPLEN 15

int X_Abschnitt = 0;
int Y_Abschnitt = 0;

int Spielfeld[WIDTH][HEIGHT];

unsigned char Mapping[MAPLEN] = {' ','.','o','+','=','*','B','0','X','@','%','&','#','/','^'};

int InitStatus = 1;


void BeschreibeSpielfeld(){

if (InitStatus == 1){
X_Abschnitt = (WIDTH/2) + 1;
Y_Abschnitt = (HEIGHT/2) + 1;

InitStatus = 0;
}

//Setze Cursor an neue Stelle
printf("\033[%d;%dH", Y_Abschnitt, X_Abschnitt);

//Erhöhe den zugehörigen Arrayplatz
Spielfeld[X_Abschnitt][Y_Abschnitt] ++;

//Gib Zeichen aus Mapping-Array aus, Element kommt aus Spielfeld-Array
//Modulo-Operator, um Überlauf zu vermeiden
printf("%c", Mapping[Spielfeld[X_Abschnitt][Y_Abschnitt] % MAPLEN]);
}



void AusgabeSpielfeld(){

    //Spielfeld 0.Zeile
    printf("+");
    for (int counter = 1; counter <=WIDTH - 2; counter++){
        printf("-");
    }
    printf("+\n");
    //Spielfeld 0.Zeile



    //Spielfeld Zeile 1 bis HEIGHT - 2
    //Äußere for-Schleife geht die Zeilen durch
    //Innere for-Schleife beschreibt in jeder Zeile die einzelnen Spalten

    for (int counter = 1; counter <=HEIGHT - 2; counter++){

        printf("|");
        for (int counter = 1; counter <=WIDTH - 2; counter++){

              printf(" ");
        }
        printf("|\n");
    }
    //Spielfeld Zeile 1 bis HEIGHT - 2



    //Spielfeld Zeile HEIGHT - 1
    printf("+");
    for (int counter = 1; counter <=WIDTH - 2; counter++){
        printf("-");
    }
    printf("+\n");
    //Spielfeld Zeile HEIGHT - 1
}



void InitArray(){
    int counter_x;
    int counter_y;
    for (counter_x = 0; counter_x < WIDTH; counter_x++){
        for (counter_y = 0; counter_y < HEIGHT; counter_y++){
            Spielfeld[counter_x][counter_y] = 0;
        }
    }
}



void BewegeLaufer(int Richtungsvorgabe){

/*
Äußere if-Abfrage: Prüfe, in welche Richtung
Läufer im nächsten Zug gehen soll

Innere if-Abfragen: Prüfe, ob Schritt in x- bzw. y-Richtung
ausgeführt werden kann, ohne die Grenzen zu überschreiten
*/

//Schritt nach links oben
if (Richtungsvorgabe == 0){
    if (X_Abschnitt > 1){
    X_Abschnitt = X_Abschnitt - 1;
    }
    if (Y_Abschnitt > 1){
    Y_Abschnitt = Y_Abschnitt - 1;
    }
}

//Schritt nach rechts oben
if (Richtungsvorgabe == 1){
    if (X_Abschnitt < WIDTH - 1){
    X_Abschnitt = X_Abschnitt + 1;
    }
    if (Y_Abschnitt > 1){
    Y_Abschnitt = Y_Abschnitt - 1;
    }
}

//Schritt nach links unten
if (Richtungsvorgabe == 2){
    if (X_Abschnitt > 1){
    X_Abschnitt = X_Abschnitt - 1;
    }
    if (Y_Abschnitt < HEIGHT - 1){
    Y_Abschnitt = Y_Abschnitt + 1;
    }
}

//Schritt nach rechts unten
if (Richtungsvorgabe == 3){
    if (X_Abschnitt < WIDTH - 1){
    X_Abschnitt = X_Abschnitt + 1;
    }
    if (Y_Abschnitt < HEIGHT - 1){
    Y_Abschnitt = Y_Abschnitt + 1;
    }
}
}



int main()
{

    unsigned long long Routenwert = 0x0e2f8bac75342a72cULL;

    //In Groesse wird gespeichert, wie viel Byte die Variable Routenwert belegt
    size_t Groesse = sizeof(Routenwert);
    //Faktor 4 zur Berechnung der Schleifendurchläufe, da wir 2bit-Pakete auswerten
    int Loops = Groesse * 4;

    InitArray();
    AusgabeSpielfeld();

    for (int i = 1; i <= Loops; i++){

    //Abspalten der beiden LSBs
    int Richtungsvorgabe = Routenwert % 4;
    Routenwert = Routenwert/4;

    BewegeLaufer(Richtungsvorgabe);
    BeschreibeSpielfeld();

    //Cursor am Ende jedes Loops nach unten setzen, wo er nicht stört
    printf("\033[%d;%dH", HEIGHT + 2, WIDTH + 2);
    }

    return 0;
}
