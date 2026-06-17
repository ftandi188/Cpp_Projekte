
// Mit dem Testlevel wird festgelegt, was alles getestet werden soll.
// Der Wert muss immer weiter erhoeht werden, bis alle Tests durchgefuehrt wurden.
#ifndef TEST_LEVEL

//constants, do not change:
#define TEST_EMPTY 0 //old value, do not use
#define TEST_COLORBOX 1 //old value, do not use
#define TEST_TEXTBOX 2 //old value, do not use
#define TEST_SWITCH 3 //old value, do not use
#define TEST_SWITCH_ONOFF 4 //old value, do not use
#define TEST_SWITCH_TOGGLE 5 //old value, do not use
#define TEST_ALL 10 //old value, do not use
#define TEST_DESTRUCTOR 11 //old value, do not use

// New values for logic circuit
#define TEST_START 40
#define TEST_LOGICGATE 41
#define TEST_INPUTSIGNAL 42
#define TEST_OUTPUTSIGNAL 43
#define TEST_LOGICGATECOMM 44
#define TEST_SIMPLEGATES 45
#define TEST_GATESWITCH 46
#define TEST_OSCILLATORS 47
#define TEST_CIRCUIT_AVAILABLE 48
#define TEST_COMPLEXGATES 49
#define TEST_CIRCUIT_COMPLETE 70

// define current testlevel here by using a constant from above

#define TEST_LEVEL TEST_LOGICGATECOMM

#endif

