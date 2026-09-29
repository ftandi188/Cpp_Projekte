#include <stdio.h>

//Bezeichner sind Namen für Objekte in einem Programm, die sich der Programmierer frei aussucht
//Also z.B. für Variablen und Funktionen. Er muss sich jedoch an gewisse Regeln halten

//Das erste Zeichen darf keine Zahl sein
int 2terSpieler;        //nicht erlaubt

//Im Bezeichner darf kein Leerzeichen sein
int Zweiter Spieler;    //nicht erlaubt

//Schlüsselwörter dürfen nicht genutzt werden (siehe Tabelle S.47)
int for;                //nicht erlaubt

//Es darf nichts in Klammern eingeschlossen werden, weil dies normalerweise teil einer Funktionsdeklaration ist
int Spieler(maxAnz);    //nicht erlaubt


//Bezeichner, die mit _ beginnen, sind nicht verboten, sollten aber vermieden werden,
//weil sie für C-Implementierungen reserviert sind

int _Spieler;           //möglich, aber nicht gut


//printf als Bezeichner für eine eigene Funktion zu verwenden, wäre den Regeln nach möglich
//Es wäre aber dumm: Wenn stdio eingebunden ist, wird sich der Compiler beschweren, da es nicht
//eindeutig ist, welche Funktion aufgerufen werden soll

int main()
{

}
