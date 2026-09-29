#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SortEvaluation.h"
#include "Zeitmessung.h"

#define Groesse 14


int PruefeSortierung(t_sortdata Data[], long DataCount){
int Flag1 = 1;

for (long i=0; i<DataCount-1; i++){
    if(Data[i] > Data[i+1]){
        Flag1 = 0;
    }
}
return Flag1;
}


void Bubblesort(t_sortdata Data[], long DataCount)
{
    bool DataChanged;
    do{
        DataChanged=false;
        for(long i=0; i<DataCount-1; i++){
            if (Data[i]>Data[i+1]){
                swapdata(&Data[i], &Data[i+1]);
                DataChanged=true;
            }
        }
    }
    while (DataChanged);
}


void Shakersort(t_sortdata Data[], long DataCount){
bool DataChanged;

do{
        DataChanged=false;
        for(long i=0; i<DataCount-1; i++){
            if (Data[i]>Data[i+1]){
                swapdata(&Data[i], &Data[i+1]);
                DataChanged=true;
            }
        }
        for(long i=DataCount-2; i>=0; i--){
            if (Data[i]>Data[i+1]){
                swapdata(&Data[i], &Data[i+1]);
                DataChanged=true;
            }
        }
    }
    while (DataChanged);
}

t_sortdata getPivot (t_sortdata Data[], long DataCount){
t_sortdata Summe = 0;

for (int i=0; i<DataCount; i++){
    Summe += Data[i];
}

t_sortdata Mittelw = Summe/DataCount;
return Mittelw;
}


int checkIdentical (t_sortdata Data[], long DataCount){
int Flag1 = 1;

for (int i=0; i<DataCount-1; i++){
    if(Data[i] != Data[i+1]){
        Flag1 = 0;
    }
}
return Flag1;
}


void Quicksort(t_sortdata Data[], long DataCount){
int Flag1 = 0;
int Gleichheit;
long links = 0;
long rechts = DataCount - 1;
long Trennelement;
t_sortdata Pivot = getPivot(Data, DataCount);

if(DataCount < 2){
    Flag1 = 1;
}
if((DataCount == 2)&&(Flag1 == 0)){
    if(Data[0] > Data[1]){
        swapdata(&Data[0], &Data[1]);
    }
    Flag1 = 1;
}

Gleichheit = checkIdentical(Data, DataCount);
if((Gleichheit == 1)&&(Flag1 == 0)){
    Flag1 = 1;
}

if(Flag1 == 0){
    while(links <= rechts){
        while((Data[links] < Pivot)){
            links++;
        }
        while((Data[rechts] > Pivot)){
            rechts--;
        }

        if(links<=rechts){
            swapdata(&Data[links], &Data[rechts]);
            links++;
            rechts--;
        }
    }
    Trennelement = rechts;
    Quicksort(Data, Trennelement+1);
    Quicksort(&(Data[Trennelement + 1]), DataCount - (Trennelement+1));
}
}


void Selectionsort(t_sortdata Data[], long DataCount){
    t_sortdata Maxwert;
    long IndexMaxwert = 0;
    long Obergrenze = DataCount - 1;

    while(Obergrenze > 0){
        Maxwert = 0.0;
        for(long i=0; i<=Obergrenze; i++){
            if(Data[i] > Maxwert){
                Maxwert = Data[i];
                IndexMaxwert = i;
            }
        }
        swapdata(&Data[IndexMaxwert], &Data[Obergrenze]);
        Obergrenze--;
    }
}



void VermesseFunktion(SortAlgorithm Algo, long ExperimentSize, t_timevalue* SortDuration,
                      t_timevalue* SortDurationPresorted, t_sortdata** KopieSampleData){

t_stopwatch MyWatch;

t_sortdata* Sampledata;
Sampledata = generateRandomData(ExperimentSize);
*KopieSampleData = Sampledata;


startStopwatch(&MyWatch);
Algo(Sampledata, ExperimentSize);

*SortDuration=stopStopwatch(&MyWatch);

/*
t_sortdata Zwischensp = Sampledata[ExperimentSize - 1];
Sampledata[ExperimentSize - 1] = Sampledata[0];
Sampledata[0] = Zwischensp;
*/
swapdata(&Sampledata[0], &Sampledata[ExperimentSize - 1]);

startStopwatch(&MyWatch);
Algo(Sampledata, ExperimentSize);

*SortDurationPresorted = stopStopwatch(&MyWatch);

free(Sampledata);
}


int main()
{
    srand(time(NULL));
    FILE* AusgabeU = fopen("C:\\Users\\andi9\\Desktop\\PIN\\Aufgabe9\\Ergebnis_unsortiert.txt", "w");
    FILE* AusgabeV = fopen("C:\\Users\\andi9\\Desktop\\PIN\\Aufgabe9\\Ergebnis_vorsortiert.txt", "w");

    long ExperimentSize[Groesse] = {100, 200, 500, 1000, 2000, 5000, 7000, 10000,
                                20000, 30000, 40000, 50000, 60000, 70000};
    int counter;


    char AlgorithmName[4][20]={"Bubblesort", "Shakersort", "Quicksort", "Selectionsort"};

    t_timevalue SortDuration;
    t_timevalue SortDurationPresorted;

    double ZeitenNVorsortiert[4][Groesse];   //Erste Dimension: Die 4 Algorithmen
                                        //Zweite Dimension: Die 14 zu sortierenden Datenmengen
    double ZeitenVorsortiert[4][Groesse];

    t_sortdata* KopieSampleData;

    int AktiverAlgo = 0;


    SortAlgorithm MyAlgorithms[4]= {Bubblesort, Shakersort, Quicksort, Selectionsort};

    int NumberOfAlgorithms=sizeof(MyAlgorithms)/sizeof(SortAlgorithm);

    for(int i=0; i<Groesse; i++){
        for(AktiverAlgo = 0; AktiverAlgo < NumberOfAlgorithms; AktiverAlgo++){
            printf("Testing %s:\n", AlgorithmName[AktiverAlgo]);
            VermesseFunktion(MyAlgorithms[AktiverAlgo], ExperimentSize[i],
                         &SortDuration, &SortDurationPresorted, &KopieSampleData);

            ZeitenVorsortiert[AktiverAlgo][i] = SortDurationPresorted/1000000.0;
            ZeitenNVorsortiert[AktiverAlgo][i] = SortDuration/1000000.0;

        }
    }

    fprintf(AusgabeU, "Samples\t");
    for (int i=0; i<NumberOfAlgorithms; i++){
        fprintf(AusgabeU, "%s\t", AlgorithmName[i]);
    }
    fprintf(AusgabeU, "\n");

    for (counter=0; counter<Groesse; counter++){
        fprintf(AusgabeU, "%ld\t", ExperimentSize[counter]);
        for (int i=0; i<NumberOfAlgorithms; i++){
                fprintf(AusgabeU, "%lf\t", ZeitenNVorsortiert[i][counter]);
        }
        fprintf(AusgabeU, "\n");
    }



    fprintf(AusgabeV, "Samples\t");
    for (int i=0; i<NumberOfAlgorithms; i++){
        fprintf(AusgabeV, "%s\t", AlgorithmName[i]);
    }
    fprintf(AusgabeV, "\n");

    for (counter=0; counter<Groesse; counter++){
        fprintf(AusgabeV, "%ld\t", ExperimentSize[counter]);
        for (int i=0; i<NumberOfAlgorithms; i++){
                fprintf(AusgabeV, "%lf\t", ZeitenVorsortiert[i][counter]);
        }
        fprintf(AusgabeV, "\n");
    }


    fclose(AusgabeU);
    fclose(AusgabeV);

    return 0;
}
