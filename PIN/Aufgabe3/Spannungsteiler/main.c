#include <stdio.h>

void Ausgabe(int R_1, int R_2, int R_L, float Spannung, float SpannungR_2){
printf("R_1\t\t: %6i\n", R_1);
printf("R_2\t\t: %6i\n", R_2);
printf("R_L\t\t: %6i\n", R_L);
printf("Spannung\t: %6.2f\n", Spannung);
printf("SpannungR_2\t: %6.2f\n", SpannungR_2);
}



void AusgabeDiagramm(int R_L, float SpannungR_2){
printf("%i\t%f\n", R_L, SpannungR_2);

}


float Ersatzwiderstand(int Widerstand2, int Lastwiderstand){
int Produkt = Widerstand2 * Lastwiderstand;
int Summe = Widerstand2 + Lastwiderstand;

float Ersatzwiderstand = (float)Produkt / Summe;

return Ersatzwiderstand;
}


float SpannungsteilerUnbelastet(int Widerstand1, int Widerstand2, int Lastwiderstand, float Eingangsspannung){
float R_par = Ersatzwiderstand(Widerstand2, Lastwiderstand);
float Gesamtwiderstand = Widerstand1 + R_par;
float Verhaeltnis = R_par/Gesamtwiderstand;
float Ausgangsspannung = Verhaeltnis * Eingangsspannung;



if (Ausgangsspannung >= 4.7){
    Ausgangsspannung = 4.7;
}




return Ausgangsspannung;
}




int main()
{
    int R_1 = 200;
    int R_2 = 200;
    int R_L = 270;
    float Spannung = 12.0;

    /*
    printf("R_1\t\t: %6i\n", R_1);
    printf("R_2\t\t: %6i\n", R_2);
    printf("Spannung\t: %6.2f\n", Spannung);
    printf("RL:      U_RL:\n");
    */

    for (int i=0; i<=500; i++){
        R_L = (i/25.0) * R_1;

    float SpannungR_2 = SpannungsteilerUnbelastet(R_1, R_2, R_L, Spannung);
    //Ausgabe(R_1, R_2, R_L, Spannung, SpannungR_2);
    AusgabeDiagramm(R_L, SpannungR_2);
    }

    return 0;
}
