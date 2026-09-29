#include <stdio.h>


int main()
{
int i = 0x01020304;
int* pi = &i;                    //Pointervariablen speichern Adressen scheinbar rückwärts ab
short* ps = (short*) &i;
char* pc = (char*) &i;

int vi[4] = {0,1,2,3};            //Für einen int-Wert werden 4 Byte reserviert
char vc[] = "ABcdefghijklmno";    //Alternative, schnellere Schreibweise
                                  //Jeder Buchstabe bekommt ein Byte zugewiesen im Memory Dump

*pc = 'X';
printf("%d", i);

*pi = 0x4433;

printf("%x\n", i);



/*
printf("%p\n", &i);
printf("%p\n", pi);
printf("%p\n", &pi);
*/

    printf("\nENDE\n");
    return 0;
}
