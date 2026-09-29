#include <stdio.h>
#include <string.h>

int main()
{
    char Kette[20];
    char Kopie[20];

    int Status = 0;

    scanf("%s", Kette);
    strcpy(Kopie, Kette);

    for (int i=0; i<20; i++){
        if((Kopie[i] > 64)&&(Kopie[i] < 91)){
            Kopie[i] = Kopie[i] + 32;
            Status = 1;
        }

        if((Kopie[i] > 96)&&(Kopie[i] < 123)&&Status == 0){
            Kopie[i] = Kopie[i] - 32;
        }
        Status = 0;
    }

    printf("%s\n", Kette);
    printf("%s\n", Kopie);
}
