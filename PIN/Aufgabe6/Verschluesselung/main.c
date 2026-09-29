#include <stdio.h>


int BerechneLSBWert(int TempText){
    if (TempText > 127){
        TempText = TempText - 128;
    }
    if (TempText > 63){
        TempText = TempText - 64;
    }
    if (TempText > 31){
        TempText = TempText - 32;
    }
    if (TempText > 15){
        TempText = TempText - 16;
    }
return TempText;
}

void BerechneLSBsText(int* LSBs, int LSBWert){
for (int i=0; i<=3; i++){
    *(LSBs + i) = LSBWert %2;
    LSBWert = LSBWert / 2;
}
}


void BerechneLSBsSchluessel(int* LSBs, int LSBWert){
for (int i=0; i<=3; i++){
    *(LSBs + i) = LSBWert %2;
    LSBWert = LSBWert / 2;
}
}

void VergleicheLSBs(*int XORAuswertung, int* LSBsText, int* LSBsSchluessel){
for (int i=0; i <= 3; i++){
    if (LSBsText[i] == 0 && LSBsSchluessel[i] == 1){
        LSBsText[i] = 1;
        LSBsSchluessel[i] = 0;
    }
    if (LSBsText[i] == 1 && LSBsSchluessel[i] == 0){
        LSBsText[i] = 0;
        LSBsSchluessel[i] = 1;
}


}


void Verschluesselung(char* Text, char* Schluessel){

    for (int i=0; i<10; i++){
        int TempText = *(Text + i);
        int LSBWertText = BerechneLSBWert(TempText);

        int LSBsText [4];
        //Hier sind die 4LSBs des aktuellen Buchstaben abgespeichert
        //Anordnung: Element 0 hat Wertigkeit 1, Element 3 hat Wertigkeit 8
        BerechneLSBsText(LSBsText, LSBWertText);


        int TempSchluessel = *(Schluessel + i);
        int LSBWertSchluessel = BerechneLSBWert(TempSchluessel);

        int LSBsSchluessel [4];
        BerechneLSBsSchluessel(LSBsSchluessel, LSBWertSchluessel);


        int XORAuswertung [4];
        VergleicheLSBs(XORAuswertung, LSBsText, LSBsSchluessel);


        /*
        printf("%d\n", LSBWert);
        for (int i=0; i<=3; i++){
            printf("%d\n", LSBs[i]);
        }
        */


    }
}

int main()
{

    char Text[] = "TungSahur";
    char Schluessel[] = "Sigmabcde";

    Verschluesselung(Text, Schluessel);
    return 0;
}






