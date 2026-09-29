#include <stdio.h>
#include <string.h>

    struct NameCounter{
    char Vorname[1500];
    int Anzahl;
    };



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

//Index startet bei 0, wie bei Arrays in C üblich
return Index;
}


int ErmittleZeilenanzahl(FILE* PointerListe){

    char Zaehlarray[500];
    int Zeilenanzahl = 0;
    while(fgets((Zaehlarray), sizeof(Zaehlarray), PointerListe) != NULL){
    Zeilenanzahl++;
    }
    //Achtung: Interner Cursor ist nun am Ende in der Datei!
    rewind(PointerListe);

    //Nun ist Cursor wieder auf Startposition

    //while (PointerListe != NULL); liefert eine Endlosschleife, da sich PointerListe nicht ändert!
    //fgets hat eine Art internen Cursor, der durch die Textdatei wandert, unabhängig von Pointerliste
    //Pointerliste ist ein Zeiger auf die File-Struktur, also nicht direkt auf die Daten, sondern
    //die Verwaltungsstruktur

    //printf("%d", Zeilenanzahl);

    return Zeilenanzahl;
}

int readNameDB(char* Dateiname, struct NameCounter* Liste, int MaxLaenge){

    char Datei[80];
    sprintf(Datei, "C:\\Users\\andi9\\Desktop\\PIN\\Aufgabe7\\%s", Dateiname);

    FILE* PointerListe = fopen(Datei, "r");

    int Zeilenanzahl = ErmittleZeilenanzahl(PointerListe);


    int i;
    char Puffer [1500];       //Zwischenspeicher für die einzelnen Zeilen

    int StatusGefunden = 0;
    int VerschiedeneNamen = 0;

    for (i=0; i<Zeilenanzahl; i++){

    fgets((Puffer), sizeof(Puffer), PointerListe);
    int ZuErsetzendeStelle = strcspn(Puffer, "\n");
    //string complement span: Sie zählt die Zeichen im char-Array so lange, bis
    //das angegebene Zeichen zum ersten mal kommt
    Puffer[ZuErsetzendeStelle] = '\0';
    //Bereinigung von

    //printf("%s\n", Puffer);

    StatusGefunden = 0;   //Noch vor der inneren Schleife!
    for (int counter = 0; counter < VerschiedeneNamen; counter++){      //Durchlaufen aller bisherigen Einträge
        if (strcmp(Liste[counter].Vorname, Puffer) == 0){
            Liste[counter].Anzahl++;
            //Mehrfachnennungen++;
            StatusGefunden = 1;
            break;
        }
    }
        if (StatusGefunden == 0){               //Darf nicht in der for-Schleife mit drin stehen!
            strcpy(Liste[VerschiedeneNamen].Vorname, Puffer);
            Liste[VerschiedeneNamen].Anzahl = 1;
            VerschiedeneNamen++;
        }
    }
/*
    //ZuErsetzendeStelle = strcspn(Liste[i].Vorname, "\n");
    //Liste[i].Vorname[ZuErsetzendeStelle] = '\0';
    for (int counter = 0; counter < VerschiedeneNamen; counter++){
    printf("%s\n", Liste[counter].Vorname);
    printf("%d\n", Liste[counter].Anzahl);
    }
*/
    return VerschiedeneNamen;
}

int main()
{
    struct NameCounter Liste[500];

    char Dateiname[] = "vornamen.txt";
    const int MaxLaenge = 1500;

    char GesuchterName[1500];
    printf("Geben sie den gesuchten Name ein!\n");
    scanf("%s", GesuchterName);

    int VerschiedeneNamen = readNameDB(Dateiname, Liste, MaxLaenge);

    int Index = find_Name(GesuchterName, Liste, VerschiedeneNamen);

    if (Index != -100){
    printf("\nGefunden am Index %d\n", Index);
    printf("Haufigkeit: %d\n", Liste[Index].Anzahl);
    }

    if (Index == -100){
    printf("\nName nicht in der Liste");
    }
    return 0;
}
