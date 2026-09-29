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

    long ExperimentSize=1000;
    char AlgorithmName[2][20]={"Bubblesort", "Shakersort"};

    t_timevalue SortDuration;
    t_timevalue SortDurationPresorted;

    double ZeitenNVorsortiert[10];
    double ZeitenVorsortiert[10];

    t_sortdata* KopieSampleData;

    int AktiverAlgo = 0;

    SortAlgorithm MyAlgorithms[2]= {Bubblesort, Shakersort};
    int NumberOfAlgorithms=sizeof(MyAlgorithms)/sizeof(SortAlgorithm);

    for(AktiverAlgo = 0; AktiverAlgo < NumberOfAlgorithms; AktiverAlgo++){
        printf("Testing %s:\n", AlgorithmName[AktiverAlgo]);
        VermesseFunktion(MyAlgorithms[AktiverAlgo], ExperimentSize, &SortDuration, &SortDurationPresorted, &KopieSampleData);

        ZeitenVorsortiert[AktiverAlgo] = SortDurationPresorted/1000000.0;
        ZeitenNVorsortiert[AktiverAlgo] = SortDuration/1000000.0;
    }

    printf("\nNicht vorsortiert:\n");

    printf("Samples\t\t");
    for (int i=0; i< NumberOfAlgorithms; i++){
        printf("%s\t\t", AlgorithmName[i]);
    }
    printf("\n");
    printf("%d\t\t", ExperimentSize);
    for (int i=0; i< NumberOfAlgorithms; i++){
        printf("%lf\t\t", ZeitenNVorsortiert[i]);
    }


    printf("\n\nVorsortiert:\n");

    printf("Samples\t\t");
    for (int i=0; i< NumberOfAlgorithms; i++){
        printf("%s\t\t", AlgorithmName[i]);
    }
    printf("\n");
    printf("%d\t\t", ExperimentSize);
    for (int i=0; i< NumberOfAlgorithms; i++){
        printf("%lf\t\t", ZeitenVorsortiert[i]);
    }

    //int Flag1 = PruefeSortierung(Sampledata, ExperimentSize);

    //printDataArray(KopieSampleData, ExperimentSize);

    //printf("\nSort Duration was: %15f ms\n", SortDuration/1000000.0);
    //printf("Sort Duration Presorted was: %15f ms\n", SortDurationPresorted/1000000.0);
    //printf("Flag = %d\n", Flag1);

    return 0;
}
