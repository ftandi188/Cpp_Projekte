#include <stdio.h>

#define HEIGHT 9
#define WIDTH 17

#define MAPLEN 15

int X_Abschnitt = (WIDTH - 2)/2;
int Y_Abschnitt = (HEIGHT - 2)/2;

int Spielfeld[WIDTH - 2][HEIGHT - 2];

unsigned char Mapping[MAPLEN] = {' ','.','o','+','=','*','B','0','X','@','%','&','#','/','^'};


void InitSpielfeld(){
int xcounter;
int ycounter;

for (xcounter = 0; xcounter <= WIDTH - 2; xcounter++){

    for (ycounter = 0; ycounter <= HEIGHT - 2; ycounter++){
        Spielfeld[xcounter][ycounter] = 0;
    }
}
}



void AusgabeSpielfeld(){

    //Spielfeld 0.Zeile
    printf("+");

    for (int counter = 1; counter < WIDTH - 1; counter++){
        printf("-");
    }
    printf("+\n");
    //Spielfeld 0.Zeile



    //Spielfeld Zeile 1 bis HEIGHT - 2
    //Äußere for-Schleife geht die Zeilen durch
    //Innere for-Schleife beschreibt in jeder Zeile die einzelnen Spalten

    int xcounter;
    int ycounter;

    for (ycounter = 0; ycounter < HEIGHT - 2; ycounter++){

        printf("|");
        for (xcounter = 0; xcounter < WIDTH - 2; xcounter++){

              printf("%c", Mapping[Spielfeld[xcounter][ycounter] % MAPLEN]);
        }
        printf("|\n");
    }
    //Spielfeld Zeile 1 bis HEIGHT - 2



    //Spielfeld Zeile HEIGHT - 1
    printf("+");
    for (int counter = 1; counter < WIDTH - 1; counter++){
        printf("-");
    }
    printf("+\n");
    //Spielfeld Zeile HEIGHT - 1
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
    if (X_Abschnitt > 0){
    X_Abschnitt = X_Abschnitt - 1;
    }
    if (Y_Abschnitt > 0){
    Y_Abschnitt = Y_Abschnitt - 1;
    }
}

//Schritt nach rechts oben
if (Richtungsvorgabe == 1){
    if (X_Abschnitt < WIDTH - 3){
    X_Abschnitt = X_Abschnitt + 1;
    }
    if (Y_Abschnitt > 0){
    Y_Abschnitt = Y_Abschnitt - 1;
    }
}

//Schritt nach links unten
if (Richtungsvorgabe == 2){
    if (X_Abschnitt > 0){
    X_Abschnitt = X_Abschnitt - 1;
    }
    if (Y_Abschnitt < HEIGHT - 3){
    Y_Abschnitt = Y_Abschnitt + 1;
    }
}

//Schritt nach rechts unten
if (Richtungsvorgabe == 3){
    if (X_Abschnitt < WIDTH - 3){
    X_Abschnitt = X_Abschnitt + 1;
    }
    if (Y_Abschnitt < HEIGHT - 3){
    Y_Abschnitt = Y_Abschnitt + 1;
    }
}
}




int main(){

InitSpielfeld();

Spielfeld[X_Abschnitt][Y_Abschnitt]++;

unsigned long long Routenwert = 0x0e2f8bca75842af2cULL;

int Groesse = sizeof (Routenwert);
for (int i = 0; i < 4*Groesse; i++){

int Richtungsvorgabe = Routenwert % 4;
    Routenwert = Routenwert/4;

BewegeLaufer(Richtungsvorgabe);

Spielfeld[X_Abschnitt][Y_Abschnitt] ++;

AusgabeSpielfeld();
}
}
