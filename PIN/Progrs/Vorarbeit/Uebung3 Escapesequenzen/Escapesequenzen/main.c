#include <stdio.h>

int main()
{
    //Die Sequenz \n ist bereits bekannt, sie verursacht einen Zeilenumsprung (newline). \a löst ein akustisches Warnsignal aus.
    printf("Deine Eltern sind Geschwister!\a\n");

    // \b setzt den Cursor eine Position nach links (backspace).
    printf("Deine Eltern sind \bGeschw\bister\n");

    // \r setzt den Cursor zurück an den Zeilenanfang und überschreibt das, was bisher dastand
    printf("Deine Eltern \r sind Geschwister\n");

    // \t setzt den Cursor an die nächste Tabulatorposition
    printf("Deine   \tEltern sind Geschwister\n");

    // Um "'? oder \ auszugeben, muss \ davorgeschrieben werden
    printf("\"\'\?\\");

    return 0;
}
