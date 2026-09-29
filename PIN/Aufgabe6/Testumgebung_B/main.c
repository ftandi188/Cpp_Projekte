#include <stdio.h>


void set4711(int *pI)
{
    printf("\nIn 4711 vor  Zuweisung:\n Add: %p Inh: %i",pI,*pI);
    *pI = 4711;
    printf("\nIn 4711 nach Zuweisung:\n Add: %p Inh: %i",pI,*pI);
    printf("\n\n");
}

void set4712(int i)
{
    printf("\nIn 4712 vor  Zuweisung:\n Add: %p Inh: %i",&i,i);
    i = 4712;
    printf("\nIn 4712 nach  Zuweisung:\n Add: %p Inh: %i",&i,i);
    printf("\n\n");
}




int main()
{
int i = 0;
int vi[4] = {0,1,2,3};
char vc[] = "abcdefghijklmno";    //Alternative, schnellere Schreibweise

int* pi = vi;                   //kein und-Zeichen nötig, da hinter Arrayname bereits
                                //die Adresse steckt

short* ps = NULL;
char* pc = vc;


/*
    printf("%d\n", vi[2]);          //6 äquivalente Schreibweisen
    printf("%d\n", pi[2]);
    printf("%d\n", *(vi + 2));
    printf("%d\n", *(pi + 2));
    printf("%d\n", (2[vi]));
    printf("%d\n", (2[pi]));
*/
/*
    printf("%p\n", vi);             //Ausgabe der Array-Adressen
    printf("%p\n", &vi[0]);
    printf("%p\n", vc);

    pi++;                   //pi zeigt nun auf das zweite Array-Element
    printf("%d\n", *pi);      //Ausgabe des 2.Arrayelements

    //Rätsel
    printf("%c\n", *((char*)(((int*)pc)+1)));
*/

int* PointerI = &i;
i = 99;

//set4711(PointerI);
set4712(i);

    printf("%d\n", i);
    printf("\nENDE\n");


    return 0;
}
