#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SortEvaluation.h"
#include "Zeitmessung.h"


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



int main()
{
    srand(time(NULL));

    long ExperimentSize=100;
    char AlgorithmName[2][20]={"Bubblesort", "Shakersort"};

    SortAlgorithm MyAlgorithms[2]= {Bubblesort, Shakersort};
    int NumberOfAlgorithms=sizeof(MyAlgorithms)/sizeof(SortAlgorithm);

    printf("Testing %s:\n", AlgorithmName[1]);


    t_stopwatch MyWatch;
    t_timevalue SortDuration;


    t_sortdata* Sampledata;
    Sampledata = generateRandomData(ExperimentSize);

    startStopwatch(&MyWatch);


    MyAlgorithms[1](Sampledata, ExperimentSize);
    SortDuration=stopStopwatch(&MyWatch);

/*
    //Gezieltes Vertauschen, um die Funktion PruefeSortierung zu testen
    double Zwischensp = Sampledata[10];
    Sampledata[10] = Sampledata[11];
    Sampledata[11] = Zwischensp;
*/

    int Flag1 = PruefeSortierung(Sampledata, ExperimentSize);

    printDataArray(Sampledata, ExperimentSize);
    free(Sampledata);


    printf("\nSort Duration was: %15f ms\n", SortDuration/1000000.0);
    printf("Flag = %d\n", Flag1);
    return 0;
}
