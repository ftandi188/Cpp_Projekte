#include <stdio.h>

//Variablen
/*
Vorab: Der Prozessor des PCs verwaltet über den Adressbus den Speicher.
Jeder einzelne Platz im Speicher hat eine eindeutige Nummer oder Adresse,
mit der er angesprochen werden kann. Da ein einzelner Speicherplatz 8 bit
groß ist, steckt hinter jeder Speicheradresse ein Byte.

Der Compiler legt für alle Variablen eine Variablentabelle an, dort verknüpft
er die Speicheradressen mit den jeweiligen Variablennamen bzw. Bezeichnern.


Damit der Compiler eine Variable in die Variablentabelle eintragen kann, muss man
ihm Datentyp und Bezeichner mitteilen. Diese Bekanntmachung nennt man Daklaration.

Wurde in einem weiteren Schritt der nötige Speicherplatz reserviert, dann spricht man von Definition.
*/

int ivar;

/*
Legt man eine Variable wie hier "ganz normal" an, so ist sie deklariert und auch schon
definiert, da der Speicher hierfür automatisch gleich reserviert wird.

Gibt man der Variable zusätzlich noch einen Startwert mit, so spricht man von Initialisierung.
Es ist eine gute Praxis, jede angelegte Variable zu initialisieren.
*/

int ivar = 7841;

/*
Wenn man eine Variable nur deklarieren möchte, muss man extern davorschreiben:
*/

extern int ivar;

/*
Somit hat man bestimmt, dass dafür kein Speicherplatz reserviert werden soll.
Die Definition der Variablen muss dann in einem anderen Modul erfolgen.
*/


int main()
{

}
