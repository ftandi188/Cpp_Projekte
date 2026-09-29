#include <stdio.h>

#define HEIGHT 11
#define WIDTH 11

#define MAPLEN 15

int X_Abschnitt = 0;
int Y_Abschnitt = 0;

int Spielfeld[WIDTH][HEIGHT];

unsigned char Mapping[MAPLEN] = {' ','.','o','+','=','*','B','0','X','@','%','&','#','/','^'};

int InitStatus = 1;
int Richtungsvorgabe;

int Maincounter;


void BeschreibeSpielfeld(){

if (InitStatus == 1){
X_Abschnitt = (WIDTH/2) + 1;
Y_Abschnitt = (HEIGHT/2) + 1;

InitStatus = 0;
}

printf("\033[%d;%dH", Y_Abschnitt, X_Abschnitt);

Spielfeld[X_Abschnitt][Y_Abschnitt] ++;

printf("%c", Mapping[Spielfeld[X_Abschnitt][Y_Abschnitt] % MAPLEN]);

printf("\033[%d;%dH", HEIGHT, WIDTH);
}



void AusgabeSpielfeld(){
    //X_Abschnitt = 0;
    //Y_Abschnitt = 0;

    printf("+");
    //X_Abschnitt++;

    for (int counter = 1; counter <=WIDTH - 2; counter++){
        printf("-");
        //X_Abschnitt++;
    }
    printf("+\n");
    //X_Abschnitt++;

    int SaveCounter;

    for (SaveCounter = 1; SaveCounter <=HEIGHT - 2; SaveCounter++){
        printf("|");
        //Y_Abschnitt = SaveCounter;

        for (int counter = 1; counter <=WIDTH - 2; counter++){
            //X_Abschnitt = counter;

            //if ((Y_Abschnitt = HEIGHT/2) && (X_Abschnitt = WIDTH/2)){
            //    BeschreibeSpielfeld();
            //}

            //else{
              printf(" ");
            //}
        }
        printf("|\n");
    }


    printf("+");
    for (int counter = 1; counter <=WIDTH - 2; counter++){
        printf("-");
    }
    printf("+\n");

}



void InitSpielfeld(){
    int counter_x;
    int counter_y;
    for (counter_x = 0; counter_x < WIDTH; counter_x++){
        for (counter_y = 0; counter_y < HEIGHT; counter_y++){
            Spielfeld[counter_x][counter_y] = 0;
        }
    }
}



void BewegeLaufer(){
    if (Maincounter <=2){
        Richtungsvorgabe = 2;
    }

    if (Maincounter == 3 || Maincounter == 4){
        Richtungsvorgabe = 3;
    }

    if (Maincounter >=5){
        Richtungsvorgabe = 0;
    }

if (Richtungsvorgabe == 0){
    X_Abschnitt = X_Abschnitt - 1;
    Y_Abschnitt = Y_Abschnitt - 1;
}

if (Richtungsvorgabe == 1){
    X_Abschnitt = X_Abschnitt + 1;
    Y_Abschnitt = Y_Abschnitt - 1;
}

if (Richtungsvorgabe == 2){
    X_Abschnitt = X_Abschnitt - 1;
    Y_Abschnitt = Y_Abschnitt + 1;
}

if (Richtungsvorgabe == 3){
    X_Abschnitt = X_Abschnitt + 1;
    Y_Abschnitt = Y_Abschnitt + 1;
}
}


int main()
{
    InitSpielfeld();
    AusgabeSpielfeld();

    for (Maincounter=1; Maincounter<=6; Maincounter++){
    BeschreibeSpielfeld();
    BewegeLaufer();
    printf("\033[%d;%dH", HEIGHT + 2, WIDTH + 2);
    }


    return 0;
}
