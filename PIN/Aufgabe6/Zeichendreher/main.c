#include <stdio.h>
#include <string.h>

#define MaxGroesse 50

int main()
{
char Text[MaxGroesse];
char Kopie[MaxGroesse];

scanf("%s", Text);

int Laenge = strlen(Text);

for (int i=0; i < Laenge; i++){
    Kopie[Laenge - i] = Text[i];
}

for (int i=0; i <= Laenge; i++){
    printf("%c", Kopie[i]);
}
}
