#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef int value_t;  // value_t ist unser int

struct list {
    size_t len; // Anzahl der Arrayeinträge
    value_t values[]; // Array
};


//Funktion zum Speicher reservieren für eine Strukturvariable
//Arraylänge als Übergabeparameter
//Rückgabewert ist Pointer auf den bereitgestellten Speicherbereich
struct list *listAllocate(size_t len)
{
    struct list *list = malloc(sizeof(size_t) + len * sizeof(value_t));
    list->len = len;

    return list;
}


//Funktion zum prüfen, ob 2 Strukturvariablen bzw. Listen genau identisch sind
//Parameter sind Pointer auf die zu vergleichenden Listen
//Rückgabewert ist true oder false
bool listEqual(struct list *a, struct list *b)
{
    if (a->len != b->len) {
	return false;
    }

    for(size_t i = 0; i < a->len; i++) {
	if (a->values[i] != b->values[i]) {
	    return false;
	}
    }
    return true;
}

//Funktion zum Ausgeben einer Liste (für Debugging)
void listPrint(struct list * l)
{
    printf("len = %ld; values = ", l->len);
    for (size_t i = 0; i < l->len; i++) {
        printf("%d%s", l->values[i], (i+1 < l->len)?";":"\n");
    }
}

/*
 * -- %< --------- Place your solution here --------------------
*/

struct list* ZahlenVereinzeln(value_t Zahl){
    int Laenge;
    if(Zahl < 100){
        Laenge = 2;
    }
    else{
        Laenge = 3;
    }

    struct list* VereinzelteZahlen = listAllocate(Laenge);

    if(Zahl < 100){
        VereinzelteZahlen->values[0] = Zahl/10;
        VereinzelteZahlen->values[1] = Zahl - (VereinzelteZahlen->values[0])*10;
    }
    else{
        VereinzelteZahlen->values[0] = Zahl/100;
        Zahl = Zahl - (VereinzelteZahlen->values[0])*100;   //Restzahl ist nur noch zweistellig
        VereinzelteZahlen->values[1] = Zahl/10;
        VereinzelteZahlen->values[2] = Zahl - (VereinzelteZahlen->values[1])*10;
    }
    return VereinzelteZahlen;
};


struct list* ZahlenZusammensetzen(struct list* VereinzelteZahlen){
    int Laenge;
    if(VereinzelteZahlen->len == 2){     //2 Einzelziffern
        Laenge = 1;                     //Es gibt eine andere Möglichkeit
    }
    else{   //3 Einzelziffern
        Laenge = 5;     //Es gibt 5 andere Möglichkeiten
    }

    struct list* ZusammengesetzteZ = listAllocate(Laenge);

    if(Laenge == 1){
        ZusammengesetzteZ->values[0] = (VereinzelteZahlen->values[1])*10 + VereinzelteZahlen->values[0];
    }
    else{
        ZusammengesetzteZ->values[0] = (VereinzelteZahlen->values[2])*100 + (VereinzelteZahlen->values[1])*10 + VereinzelteZahlen->values[0];
        ZusammengesetzteZ->values[1] = (VereinzelteZahlen->values[2])*100 + (VereinzelteZahlen->values[0])*10 + VereinzelteZahlen->values[1];
        ZusammengesetzteZ->values[2] = (VereinzelteZahlen->values[1])*100 + (VereinzelteZahlen->values[2])*10 + VereinzelteZahlen->values[0];
        ZusammengesetzteZ->values[3] = (VereinzelteZahlen->values[1])*100 + (VereinzelteZahlen->values[0])*10 + VereinzelteZahlen->values[2];
        ZusammengesetzteZ->values[4] = (VereinzelteZahlen->values[0])*100 + (VereinzelteZahlen->values[2])*10 + VereinzelteZahlen->values[1];
    }
    return ZusammengesetzteZ;
};

/*
 * global data



 */

//Initialisieren von globalen Variablen
void setup()
{


}

//Funktion:
//get all unique digit permutations of a list of numbers
//Alle eindeutigen Ziffernpermutationen einer Liste von Zahlen ermitteln

//Parameter: Eine Liste

//Rückgabewert:
//A list of numbers, which are unique digit permutations of above list
//Eine Liste von Zahlen, die eindeutige Ziffernpermutationen der obigen Liste darstellen.

struct list * getUniqPermutations(struct list *numbers)
{
    //listPrint(numbers);
    struct list* result = listAllocate(numbers->len);
    int i;
    int b = 0;
    int Flag = 0;

    for(i=0; i<(numbers->len); i++){
        Flag = 0;
        struct list* VereinzelteZahlen = ZahlenVereinzeln(numbers->values[i]);
        //listPrint(VereinzelteZahlen);
        struct list* MoeglicheZahlen = ZahlenZusammensetzen(VereinzelteZahlen);
        //listPrint(MoeglicheZahlen);

        for(int a=0; a<(numbers->len); a++){        //Innere for-Schleife vergleicht alle möglichen anderen Zahlen
                                                    //(aus der Funktion ZahlenZusammensetzen) mit allen anderen
                                                    //Zahlen im Array, bei einer gefundenen Übereinstimmung wird Flag
                                                    //auf 1 gesetzt und sie kommt somit nicht ins Resultarray
            if(MoeglicheZahlen->values[0] == numbers->values[a]){
                    Flag = 1;
                }
            if(MoeglicheZahlen->len == 5){
                if(MoeglicheZahlen->values[1] == numbers->values[a]){
                    Flag = 1;
                }
                if(MoeglicheZahlen->values[2] == numbers->values[a]){
                    Flag = 1;
                }
                if(MoeglicheZahlen->values[3] == numbers->values[a]){
                    Flag = 1;
                }
                if(MoeglicheZahlen->values[4] == numbers->values[a]){
                    Flag = 1;
                }
            }
        }
            if(Flag == 0){      //Wenn angeschaute Zahl mit keiner anderen möglichen Zahl übereinstimmt, wird sie gespeichert
                result->values[b] = numbers->values[i];
                b++;
            }
    }
    result->len = b;

    listPrint(result);
    return result;
    /*
    This returns the solution for first example
    struct list * result = listAllocate(numbers->len);
    result->len = 1; // overwrite len with the number of values in your result
    result->values[0] = 456;
    return result;
    */

}
//-- %< -------------------------------------------------------


#define EXAMPLES "examples.txt"     //Datei mit den Zahlenlisten
#define MAXLENGTH 2500
#define NUMLINES 3

struct test {            //Struktur, die 2 Pointer auf Strukturen vom bekannten Typ enthält
    struct list * result;
    struct list * numbers;
};

//Rückgabewert: Pointer auf Struktur der Strukturpointer
//Diese Funktion beschreibt die beiden Strukturen in der Struktur test mit den Zahlen der txt-Datei
struct test * readTest(char line[NUMLINES][MAXLENGTH])
{
    if (line[0][0] != 'C' || line[1][0] != 'R') {   //Es darf nicht anders sein (siehe txt-Datei)
	return NULL;
    }

    struct test *test = malloc(sizeof(struct test));    //Speicher reservieren für Struktur
                                                        //die der Rückgabewert der Funktion wird
    char *tok = NULL;
    size_t size = 0;


    tok = strtok(&line[0][2], " ");     //Im ersten Bsp. wird Pointer nur auf die 3
                                        //gesetzt (dann kommt Leerzeichen)
    size = atoi(tok);                   //Umwandlung string --> int (bzw. size_t)
                            //size sagt aus, wie viele Elemente folgen werden

    test->numbers = listAllocate(size);     //Nötigen Speicher reservieren für numbers-Struktur

    tok = strtok(NULL, ";");    //Beschreiben vom values-Array in numbers in test, ab jetzt ; als Trennzeichen
    for (size_t i = 0; i < size && tok; i++ ){
                    //Schaut ungewöhnlich aus, Abbruchbedingungen sind: i >= size oder tok == NULL
                    //wichtig: < wird vor && ausgewertet!
	test->numbers->values[i] = atoi(tok);
	tok = strtok(NULL, ";");
    }

    //Entsprechender Vorgang für zweite Zahlenauflistung
    tok = strtok(&line[1][2], " ");
    size = atoi(tok);
    test->result = listAllocate(size);
    tok = strtok(NULL, ";");
    for (size_t i = 0; i < size && tok; i++ ) {
	test->result->values[i] = atoi(tok);
	tok = strtok(NULL, ";");
    }

    return test;
}

void deleteTest(struct test *test)
{
    if (test) {
	free(test->result);
	free(test->numbers);
	free(test);
    }
}

value_t comp(const void *a, const void *b)
{
    return (*(value_t *)a - *(value_t *)b);
}

int main()
{
    FILE *f = fopen(EXAMPLES, "r");
    if (f == NULL) perror ("Error opening file");
    //perror gibt automatisch eine Fehlermeldung in der Konsole aus, was man
    //in den Klammern dahinter schreibt, ist die Überschrift davor

    setup();

    char multilinebuffer[NUMLINES][MAXLENGTH];

    int testnr = 1;
    int linenr = 0;
    while(fgets(multilinebuffer[linenr], MAXLENGTH, f) != NULL) {
	if (strlen(multilinebuffer[linenr]) < 2) {
	    continue;       //Wenn weniger als 2 Zeichen eingelesen wurden, wird der
	}                   //Rest in der while-Schleife (in dieser Iteration) übersprungen

	if (linenr < 1) {   //Durch dieses if/else-Konstrukt beschreibt man
	    linenr++;       //multilinebuffer abwechselnd in Zeile 0 und 1
	}                   //-->Man geht immer paarweise in readTest rein
	else {
	    linenr = 0;

	    //Aufrufen von readTest
	    struct test *test = readTest(multilinebuffer);

	    if (test == NULL) perror ("Error parsing example");

	    printf("Test %d ... ", testnr);         //Konsolenausgabe, während man wartet
	    struct list * result = getUniqPermutations(test->numbers);

	    // Sort the result
	    qsort(result->values, result->len, sizeof(result->values[0]), comp);
	    qsort(test->result->values, test->result->len, sizeof(test->result->values[0]), comp);


	    if (!listEqual(test->result, result)) {
		printf("FAILED expected result:\n");
		listPrint(test->result);
		printf("your result:\n");
		listPrint(result);

		//abort(); // stop execution. Remove this line to keep going
	    } else {
		printf("PASSED with result:\n");
		listPrint(result);
	    }
	    deleteTest(test);
	    testnr++;


    }
    }
    return 0;
}
