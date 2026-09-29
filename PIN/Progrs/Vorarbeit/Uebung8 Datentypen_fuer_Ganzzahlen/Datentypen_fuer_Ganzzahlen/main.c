#include <stdio.h>

//Datentypen für vorzeichenbehaftete Ganzzahlen
//Es stehen folgende Datentypen zur Verfügung:

signed char     //8bit,  [-128; 127]
short           //16bit, [-32768; 32767]                                                                oder short int
int             //16bit, [-32768; 32767]
long            //32bit, [-2.147.483.648; 2.147.483.647]                                                oder long int
long long       //64bit, [-9.223.372.036.854.775.808; 9.223.372.036.854.775.807]    9 Trillionen...     oder long long int

/*
Vor die oben aufgelisteten Datentypen kann man auch das Schlüsselwort signed schreiben,
dann verdeutlicht man, dass es ein vorzeichenbehafteter Datentyp ist.
Notwendig ist es jedoch nur bei char, dieser stellt eine Ausnahme dar.

Achtung: Die angegebenen Wertebereiche sind die Mindestgrößen der einzelnen Datentypen.
Je nach System können sie aber auch größer sein.

Man kann sich aber immer auf folgende Reihenfolge verlassen:

signed char <= short <= int <= long <= long long
*/

//Datentypen für vorzeichenlose Ganzzahlen
/*
Bei den vorzeichenlosen Ganzzahlen wird das Bit, das das Vorzeichen angibt, nicht gebraucht.
Dieses kann nun genutzt werden, um im Positiven noch weiter hochzuzählen.
Es stehen folgende Datentypen zur Verfügung:
*/

bool                        //1bit,   0 oder 1
unsigned char               //8bit,  [0; 255]
unsigned short              //16bit, [0; 65535]                                                 oder unsigned short int
unsigned int                //16bit, [0; 65535]
unsigned long               //32bit, [0; 4.294.967.295]                                         oder unsigned long int
unsigned long long          //64bit, [0; 18.446.744.073.709.551.615]    18 Trillionen...        oder unsigned long long int

/*
Hier ist es wichtig, unsigned davor zu schreiben
*/

//Suffixe für Ganzzahlen
/*
Will man den Compiler zusätzlich informieren, welcher Datentyp
eine Zahl ist, so kann man noch einen Suffix anhängen.
Suffix u oder U gibt an, dass es eine vorzeichenlose Zahl ist.
l oder L gibt an, dass es der Datentyp long ist.
ll oder LL gibt an, dass es der Datentyp long long ist.
u und l bzw. u und ll können auch kombiniert werden.
*/

unsigned int uVal = 1000u;
long lVal = 100000L;
unsigned long long ullVal = 12341234323ULL;
unsigned int uHexVal = 0X42U;




int main()
{

}
