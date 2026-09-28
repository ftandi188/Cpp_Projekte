//Deklaration der ganzen Pins
#define Tag1_Bit0 27
#define Tag1_Bit1 29
#define Tag2_Bit0 15
#define Tag2_Bit1 25
#define Tag2_Bit2 23
#define Tag2_Bit3 17

#define Monat1 42
#define Monat2_Bit0 46
#define Monat2_Bit1 47
#define Monat2_Bit2 44
#define Monat2_Bit3 48

#define Stunde1_Bit0 3
#define Stunde1_Bit1 5
#define Stunde2_Bit0 7
#define Stunde2_Bit1 13
#define Stunde2_Bit2 11
#define Stunde2_Bit3 9

#define Minute1_Bit0 31
#define Minute1_Bit1 28
#define Minute1_Bit2 30
#define Minute2_Bit0 51
#define Minute2_Bit1 52
#define Minute2_Bit2 50
#define Minute2_Bit3 53



#define DPTag2 2
#define DPMonat2 41
#define LTPin 39

#define DeaktivierungStunde1 37
#define DeaktivierungTag1 35

#define Tasterkontakt 19
#define Impulskontakt 18
#define Drehrichtung 26


int AktiveStelle = 0;
int Anzeigewerte[8];  //Tag1, Tag2, Monat1, Monat2, Stunde1, Stunde2, Minute1, Minute2

bool BCDArray_Tag1 [4];
bool BCDArray_Tag2 [4];
bool BCDArray_Monat2 [4];
bool BCDArray_Stunde1 [4];
bool BCDArray_Stunde2 [4];
bool BCDArray_Minute1 [4];
bool BCDArray_Minute2 [4];

bool StatusDrehrichtung;

void setup() {
  Serial.begin(115200);

  pinMode(Tag1_Bit0, OUTPUT);
  pinMode(Tag1_Bit1, OUTPUT);
  pinMode(Tag2_Bit0, OUTPUT);
  pinMode(Tag2_Bit1, OUTPUT);
  pinMode(Tag2_Bit2, OUTPUT);
  pinMode(Tag2_Bit3, OUTPUT);

  pinMode(Monat1, OUTPUT);
  pinMode(Monat2_Bit0, OUTPUT);
  pinMode(Monat2_Bit1, OUTPUT);
  pinMode(Monat2_Bit2, OUTPUT);
  pinMode(Monat2_Bit3, OUTPUT);

  pinMode(Stunde1_Bit0, OUTPUT);
  pinMode(Stunde1_Bit1, OUTPUT);
  pinMode(Stunde2_Bit0, OUTPUT);
  pinMode(Stunde2_Bit1, OUTPUT);
  pinMode(Stunde2_Bit2, OUTPUT);
  pinMode(Stunde2_Bit3, OUTPUT);

  pinMode(Minute1_Bit0, OUTPUT);
  pinMode(Minute1_Bit1, OUTPUT);
  pinMode(Minute1_Bit2, OUTPUT);
  pinMode(Minute2_Bit0, OUTPUT);
  pinMode(Minute2_Bit1, OUTPUT);
  pinMode(Minute2_Bit2, OUTPUT);
  pinMode(Minute2_Bit3, OUTPUT);


  pinMode(DPTag2, OUTPUT);
  pinMode(DPMonat2, OUTPUT);
  pinMode(LTPin, OUTPUT);

  pinMode(DeaktivierungStunde1, OUTPUT);
  pinMode(DeaktivierungTag1, OUTPUT);

  pinMode(Tasterkontakt, INPUT);
  pinMode(Impulskontakt, INPUT);
  pinMode(Drehrichtung, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt (Impulskontakt), Zaehlen, FALLING);
  attachInterrupt(digitalPinToInterrupt (Tasterkontakt), StelleVerschieben, FALLING);

  digitalWrite(DPTag2, LOW);
  digitalWrite(DPMonat2, LOW);
  digitalWrite(LTPin, HIGH);
}


void Zaehlen(){
  StatusDrehrichtung = digitalRead(Drehrichtung);     //Einlesen des Pins, der die Drehrichtung vorgibt

  if (StatusDrehrichtung == 1){     //In diesem Fall wird hochgezaehlt
    if (AktiveStelle == 1||AktiveStelle == 3||AktiveStelle == 5||AktiveStelle == 7){    //Falls die Zahl 9 ist, soll sie auf 0 zurueckspringen
      if (Anzeigewerte[AktiveStelle] == 9){
        Anzeigewerte[AktiveStelle] = 0;
      }
      else{
        Anzeigewerte[AktiveStelle]++;
      }
    }
    else if (AktiveStelle == 0){    //Falls die Zahl 3 ist, soll sie auf 0 zurueckspringen
      if (Anzeigewerte[AktiveStelle] == 3){
        Anzeigewerte[AktiveStelle] = 0;
      }
      else{
        Anzeigewerte[AktiveStelle]++;
      }
    }
    else if (AktiveStelle == 2){    //Falls die Zahl 1 ist, soll sie auf 0 zurueckspringen
      if (Anzeigewerte[AktiveStelle] == 1){
        Anzeigewerte[AktiveStelle] = 0;
      }
      else{
        Anzeigewerte[AktiveStelle]++;
      }
    }
    else if (AktiveStelle == 4){    //Falls die Zahl 2 ist, soll sie auf 0 zurueckspringen
      if (Anzeigewerte[AktiveStelle] == 2){
        Anzeigewerte[AktiveStelle] = 0;
      }
      else{
        Anzeigewerte[AktiveStelle]++;
      }
    }
    else if (AktiveStelle == 6){    //Falls die Zahl 5 ist, soll sie auf 0 zurueckspringen
      if (Anzeigewerte[AktiveStelle] == 5){
        Anzeigewerte[AktiveStelle] = 0;
      }
      else{
        Anzeigewerte[AktiveStelle]++;
      }
    }
  }


  if (StatusDrehrichtung == 0){     //In diesem Fall wird runtergezaehlt
    if (AktiveStelle == 1||AktiveStelle == 3||AktiveStelle == 5||AktiveStelle == 7){    //Falls die Zahl 0 ist, soll sie auf 9 springen
      if (Anzeigewerte[AktiveStelle] == 0){
        Anzeigewerte[AktiveStelle] = 9;
      }
      else{
        Anzeigewerte[AktiveStelle]--;
      }
    }
    else if (AktiveStelle == 0){    //Falls die Zahl 0 ist, soll sie auf 3 springen
      if (Anzeigewerte[AktiveStelle] == 0){
        Anzeigewerte[AktiveStelle] = 3;
      }
      else{
        Anzeigewerte[AktiveStelle]--;
      }
    }
    else if (AktiveStelle == 2){    //Falls die Zahl 0 ist, soll sie auf 1 springen
      if (Anzeigewerte[AktiveStelle] == 0){
        Anzeigewerte[AktiveStelle] = 1;
      }
      else{
        Anzeigewerte[AktiveStelle]--;
      }
    }
    else if (AktiveStelle == 4){    //Falls die Zahl 0 ist, soll sie auf 2 springen
      if (Anzeigewerte[AktiveStelle] == 0){
        Anzeigewerte[AktiveStelle] = 2;
      }
      else{
        Anzeigewerte[AktiveStelle]--;
      }
    }
    else if (AktiveStelle == 6){    //Falls die Zahl 0 ist, soll sie auf 5 springen
      if (Anzeigewerte[AktiveStelle] == 0){
        Anzeigewerte[AktiveStelle] = 5;
      }
      else{
        Anzeigewerte[AktiveStelle]--;
      }
    } 
  }
}


void StelleVerschieben(){
  if (AktiveStelle == 7){        //Ist man bei der letzten Stelle angekommen, springt man auf die erste zurueck
    AktiveStelle = 0;
  }
  else{ 
    AktiveStelle++;
  }
}


void BeschreibeBCDArray(bool* Array, int Zahl){
  for (int i=3; i>=0; i--){
    Array [i] = Zahl % 2;
    Zahl = Zahl/2;
  }
}

void loop() {
  BeschreibeBCDArray(BCDArray_Tag1, Anzeigewerte[0]);     //Vor das erste Argument kein &-Zeichen: Hinter Arrayname steckt schon die Adresse
  BeschreibeBCDArray(BCDArray_Tag2, Anzeigewerte[1]);
  BeschreibeBCDArray(BCDArray_Monat2, Anzeigewerte[3]);
  BeschreibeBCDArray(BCDArray_Stunde1, Anzeigewerte[4]);
  BeschreibeBCDArray(BCDArray_Stunde2, Anzeigewerte[5]);
  BeschreibeBCDArray(BCDArray_Minute1, Anzeigewerte[6]);
  BeschreibeBCDArray(BCDArray_Minute2, Anzeigewerte[7]);


  if(Anzeigewerte[0] == 0){
    digitalWrite(DeaktivierungTag1, LOW);   //Null wird nicht angezeigt
  }
  else{
    digitalWrite(DeaktivierungTag1, HIGH);
  }
  digitalWrite(Tag1_Bit0, BCDArray_Tag1 [3]);
  digitalWrite(Tag1_Bit1, BCDArray_Tag1 [2]);
  digitalWrite(Tag2_Bit0, BCDArray_Tag2 [3]);
  digitalWrite(Tag2_Bit1, BCDArray_Tag2 [2]);
  digitalWrite(Tag2_Bit2, BCDArray_Tag2 [1]);
  digitalWrite(Tag2_Bit3, BCDArray_Tag2 [0]);

  if(Anzeigewerte[2] == 0){       //Invertiert wegen gemeinsamer Anode: Bei High-Pegel am Pin leuchtet Anzeige nicht, bei Low schon
    digitalWrite(Monat1, HIGH);   //Gleiches gilt für Dezimalpunkte
  }
  if(Anzeigewerte[2] == 1){
    digitalWrite(Monat1, LOW);
  }
  digitalWrite(Monat2_Bit0, BCDArray_Monat2 [3]);
  digitalWrite(Monat2_Bit1, BCDArray_Monat2 [2]);
  digitalWrite(Monat2_Bit2, BCDArray_Monat2 [1]);
  digitalWrite(Monat2_Bit3, BCDArray_Monat2 [0]);


  if(Anzeigewerte[4] == 0){
    digitalWrite(DeaktivierungStunde1, LOW);    //Null wird nicht angezeigt
  }
  else{
    digitalWrite(DeaktivierungStunde1, HIGH);
  }
  digitalWrite(Stunde1_Bit0, BCDArray_Stunde1 [3]);
  digitalWrite(Stunde1_Bit1, BCDArray_Stunde1 [2]);
  digitalWrite(Stunde2_Bit0, BCDArray_Stunde2 [3]);
  digitalWrite(Stunde2_Bit1, BCDArray_Stunde2 [2]);
  digitalWrite(Stunde2_Bit2, BCDArray_Stunde2 [1]);
  digitalWrite(Stunde2_Bit3, BCDArray_Stunde2 [0]);

  digitalWrite(Minute1_Bit0, BCDArray_Minute1 [3]);
  digitalWrite(Minute1_Bit1, BCDArray_Minute1 [2]);
  digitalWrite(Minute1_Bit2, BCDArray_Minute1 [1]);
  digitalWrite(Minute2_Bit0, BCDArray_Minute2 [3]);
  digitalWrite(Minute2_Bit1, BCDArray_Minute2 [2]);
  digitalWrite(Minute2_Bit2, BCDArray_Minute2 [1]);
  digitalWrite(Minute2_Bit3, BCDArray_Minute2 [0]);

  delay(50);
}
