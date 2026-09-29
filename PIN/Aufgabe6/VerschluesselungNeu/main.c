#include <stdio.h>
#include <string.h>

int BerechneLSBWert(int Temp){
    if (Temp > 127){
        Temp = Temp - 128;
    }
    if (Temp > 63){
        Temp = Temp - 64;
    }
    if (Temp > 31){
        Temp = Temp - 32;
    }
    if (Temp > 15){
        Temp = Temp - 16;
    }
return Temp;
}

void WandleTextBin(int* TextBin, int TempText){
for (int i=7; i >= 0; i--){
    TextBin[i] = TempText % 2;
    TempText = TempText / 2;
}
}

void WandleXORBin(int* XORBin, int XORErgebnis){
for (int i=3; i >= 0; i--){
    XORBin[i] = XORErgebnis % 2;
    XORErgebnis = XORErgebnis / 2;
}
}


void WandleText(char* Text, int* TextBin, int i){
Text[i] = TextBin[0]*128 + TextBin[1]*64 + TextBin[2]*32 + TextBin[3]*16 + TextBin[4]*8 + TextBin[5]*4 + TextBin[6]*2 + TextBin[7]*1;
}


void Verschluesselung(char* Text, char* Schluessel, int LaengeText, int LaengeSchluessel){

    for (int i=0; i < LaengeText; i++){
        int TempText = *(Text + i);

        if (TempText >= 32){

        int LSBWertText = BerechneLSBWert(TempText);


        int TempSchluessel = *(Schluessel + (i%LaengeSchluessel));      //Damit Schlüssel wieder von vorne losgeht
        int LSBWertSchluessel = BerechneLSBWert(TempSchluessel);


        int XORErgebnis = LSBWertText ^ LSBWertSchluessel;
        //printf("%d\n", XORErgebnis);

        //Text[i] = (Text[i] - LSBWertText) + XORErgebnis;
        int TextBin[8];
        WandleTextBin(TextBin, TempText);
        int XORBin[4];
        WandleXORBin(XORBin, XORErgebnis);

        for (int i=7; i >= 4;i--){
            TextBin[i] = XORBin[i - 4];
        }

        WandleText(Text, TextBin, i);

        /*
        printf("%d\n", LSBWert);
        for (int i=0; i<=3; i++){
            printf("%d\n", LSBs[i]);
        }
        */
    }
    }
}


int main()
{
    char Text[] = "Berlin Berlin Berlin ";
    int LaengeText = strlen(Text);

    char Schluessel[] = "ABHuber";
    int LaengeSchluessel = strlen(Schluessel);

    Verschluesselung(Text, Schluessel, LaengeText, LaengeSchluessel);

    printf("%s", Text);
    return 0;
}

