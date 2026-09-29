#include <stdio.h>
#include <string.h>
#include "Zeitmessung.h"

    struct NameCounter{
    char Vorname[1500];
    int Anzahl;
    };


void sortNameDB(struct NameCounter* Liste, int VerschiedeneNamen){

struct NameCounter TempSpeicher;
int Statusflag = 1;

while (Statusflag == 1){
    Statusflag = 0;
for (int i = 0; i < (VerschiedeneNamen - 1); i++){
    if(Liste[i].Anzahl < Liste[i+1].Anzahl){
        Statusflag = 1;
        TempSpeicher = Liste[i];
        Liste[i] = Liste[i+1];
        Liste[i+1] = TempSpeicher;
    }
}
}
}


int find_Name(char* GesuchterName, struct NameCounter* Liste, int VerschiedeneNamen){

int StatusFlag = 0;
int Index = 0;
StatusFlag = 0;

for (int counter = 0; counter < VerschiedeneNamen; counter++){
    if (strcmp(Liste[counter].Vorname, GesuchterName) == 0){
        Index = counter;
        StatusFlag = 1;
        break;
    }
}

if (StatusFlag == 0){
    Index = -100;
}

return Index;
}


int ErmittleZeilenanzahl(FILE* PointerListe){

    char Zaehlarray[500];
    int Zeilenanzahl = 0;
    while(fgets((Zaehlarray), sizeof(Zaehlarray), PointerListe) != NULL){
    Zeilenanzahl++;
    }
    rewind(PointerListe);

    return Zeilenanzahl;
}


int readNameDB(char* Dateiname, struct NameCounter* Liste, int MaxLaenge){

    char Datei[80];
    sprintf(Datei, "C:\\Users\\andi9\\Desktop\\PIN\\Aufgabe7\\%s", Dateiname);
    FILE* PointerListe = fopen(Datei, "r");

    int Zeilenanzahl = ErmittleZeilenanzahl(PointerListe);

    int i;
    char Puffer [1500];
    int StatusGefunden = 0;
    int VerschiedeneNamen = 0;

    for (i=0; i<Zeilenanzahl; i++){

    fgets((Puffer), sizeof(Puffer), PointerListe);
    int ZuErsetzendeStelle = strcspn(Puffer, "\n");
    Puffer[ZuErsetzendeStelle] = '\0';


    StatusGefunden = 0;
    for (int counter = 0; counter < VerschiedeneNamen; counter++){
        if (strcmp(Liste[counter].Vorname, Puffer) == 0){
            Liste[counter].Anzahl++;
            StatusGefunden = 1;
            break;
        }
    }
        if (StatusGefunden == 0){
            strcpy(Liste[VerschiedeneNamen].Vorname, Puffer);
            Liste[VerschiedeneNamen].Anzahl = 1;
            VerschiedeneNamen++;
        }
    }
    return VerschiedeneNamen;
}

int main()
{
    struct NameCounter Liste[500];
    char Dateiname[] = "vornamen.txt";
    const int MaxLaenge = 1500;
    char GesuchterName[1500];

    t_timevalue Messwert = 0;   //Ohne diese Initialisierung funktioniert es nicht!

    int VerschiedeneNamen = readNameDB(Dateiname, Liste, MaxLaenge);


    t_stopwatch* StoppUhr;

    startStopwatch(StoppUhr);
    sortNameDB(Liste, VerschiedeneNamen);
    Messwert = stopStopwatch(StoppUhr);

    printf("%llu", Messwert);

    //printf("%d", (sizeof (Liste[0])));
    /*
    printf("Geben sie den gesuchten Name ein!  ");
    scanf("%s", GesuchterName);

    int Index = find_Name(GesuchterName, Liste, VerschiedeneNamen);


    if (Index != -100){
        printf("\n%s steht an %d. Stelle und ist %d mal vorhanden.\n", GesuchterName, Index, Liste[Index].Anzahl);

        if (Index != 0){
        printf("%d. %s    %dx\n", Index - 1, Liste[Index - 1].Vorname, Liste[Index - 1].Anzahl);
        }
        printf("%d. %s    %dx\n", Index, Liste[Index].Vorname, Liste[Index].Anzahl);
        if (Index != VerschiedeneNamen - 1){
        printf("%d. %s    %dx\n", Index + 1, Liste[Index + 1].Vorname, Liste[Index + 1].Anzahl);
        }
    }

    if (Index == -100){
    printf("\nName nicht in der Liste");
    }
    */

    return 0;
}
