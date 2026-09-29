#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SortEvaluation.h"
#include "Zeitmessung.h"

void Bubblesort(t_sortdata Data[], long DataCount)
{
    bool DataChanged;
    do
    {
        DataChanged=false;
        for(long i=0; i<DataCount-1; i++)
        {
            if (Data[i]>Data[i+1])
            {
                /* Swap Items */
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

    /* Numer of data items to be used in sorting */
    long ExperimentSize=100;
    /* Array of names of Algorithms for display purposes */
    char AlgorithmName[][20]={"Bubblesort"};
    /* Array of sorting functions implementing various algorithms */
    /* currently only the studpidly simple Bubblesort */
    //Array von Funktionspointern
    SortAlgorithm MyAlgorithms[]= {Bubblesort};
    /* Calculation of the number of available algorithms */
    int NumberOfAlgorithms=sizeof(MyAlgorithms)/sizeof(SortAlgorithm);

    printf("Testing %s:\n", AlgorithmName[0]);

    /* prepare for measurement */
    t_stopwatch MyWatch;
    t_timevalue SortDuration;

    //Pointer auf den Speicherbereich, wo das Zufallsarray hingeschrieben wird
    //t_sortdata ist ein typedef von double (absolut unnötig)
    t_sortdata* Sampledata;
    /* prepare random data for sorting */
    Sampledata = generateRandomData(ExperimentSize);
    /* perform the measurement of the sorting duration */
    startStopwatch(&MyWatch);

    //Aufruf der Funktion über Funktionspointer
    MyAlgorithms[0](Sampledata, ExperimentSize);
    SortDuration=stopStopwatch(&MyWatch);
    /* print sorted data, just for checking...*/
    printDataArray(Sampledata, ExperimentSize);
    /* clean up sorted data */
    free(Sampledata);

    /* print result, scaling to ms for convenience */
    printf("\nSort Duration was: %15f ms\n\n", SortDuration/1000000.0);

    return 0;
}
