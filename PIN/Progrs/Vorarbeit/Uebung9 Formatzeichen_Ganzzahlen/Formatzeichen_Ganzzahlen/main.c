#include <stdio.h>


int main()
{
//Vorzeichenbehaftete Ganzzahlen
signed char cVal = 4;
short sVal = -1386;
int iVal = 5639;
long lVal = 142584038;
long long llVal = -493593628572;

//Vorzeichenlose Ganzzahlen
_Bool bVal = 1;
unsigned char ucVal = 245;
unsigned short usVal = 35128;
unsigned int uiVal = 58349;
unsigned long ulVal = 3574819215;
unsigned long long ullVal = 7583;


printf("Ausgabe vorzeichenbehafteter Ganzzahlen:\n");
printf("signed char Wert = %hhd\n", cVal);
printf("short Wert = %hd\n", sVal);             // %hi auch möglich
printf("int Wert = %d\n", iVal);                // %i auch möglich
printf("long Wert = %ld\n", lVal);              // %li auch möglich
printf("long long Wert = %lld\n", llVal);       // %lli auch möglich
printf("\n");
printf("Ausgabe vorzeichenloser Ganzzahlen:\n");
printf("_Bool Wert = %u\n", bVal);
printf("unsigned char Wert = %hhu\n", ucVal);
printf("unsigned short Wert = %hu\n", usVal);
printf("unsigned int Wert = %u\n", uiVal);
printf("unsigned long Wert = %lu\n", ulVal);
printf("unsigned long long Wert = %llu\n", ullVal);
}
