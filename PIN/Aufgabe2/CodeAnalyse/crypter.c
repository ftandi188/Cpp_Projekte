#include <stdio.h>
#include <stdlib.h>
#define CHARACTERAMOUNT 21
char cryptCharacter(char InputCharacter)
{
    char ReturnCharacter='?';
    if (InputCharacter >= 'a' && InputCharacter <= 'z')
    {
        ReturnCharacter = 'Z' - (InputCharacter - 'a');
    }
    else
    {

        if (InputCharacter >= 'A' && InputCharacter <= 'Z')
        {
            ReturnCharacter = 'z' - (InputCharacter - 'A');
        }
        else
        {
            ReturnCharacter = InputCharacter;
        }
    }
    return ReturnCharacter;
}

int main()
{
    char SampleCharacterStorage[CHARACTERAMOUNT] =
    {
        'H', 'e', 'r', 'z', 'l',
        'i','c','h', ' ', 'w', 'i',
        'l', 'l', 'k', 'o', 'm', 'm',
        'e', 'n', '!', '\n'
    };
    for (int RunningIndex=0; RunningIndex<CHARACTERAMOUNT;
            RunningIndex=RunningIndex+1)
    {
        printf("%c", SampleCharacterStorage[RunningIndex]);
    }
    int RunningIndex2=0;
    while (RunningIndex2<CHARACTERAMOUNT)
    {
        char TemporaryCharacterStorage='?';
        TemporaryCharacterStorage =
            cryptCharacter(SampleCharacterStorage[RunningIndex2]);
        SampleCharacterStorage[RunningIndex2] = TemporaryCharacterStorage;
        RunningIndex2++;
    }
    int RunningIndex3=0;
    do
    {
        printf("%c", SampleCharacterStorage[RunningIndex3]);
        RunningIndex3++;
    }
    while (RunningIndex3<CHARACTERAMOUNT);
    return 0;
}
