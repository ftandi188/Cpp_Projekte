#include "Switch.h"
#include "SwitchOnOff.h"
#include "Point.h"
#include "ColorBox.h"

SwitchOnOff::SwitchOnOff(const SwitchOnOff& s)
                :Switch(s),         //Copy-Konstruktor der Basisklasse aufrufen
                                    //Möglich, weil jedes abgeleitete Objekt auch Objekt seiner Basisklasse ist
                 OnButton(new TextBox(s.OnButton->getPosition(),s.OnButton->getSize(),s.OnButton->getText())),
                 OffButton(new TextBox(s.OffButton->getPosition(),s.OffButton->getSize(),s.OffButton->getText()))

{}

SwitchOnOff::SwitchOnOff(const Point& pos,const std::string& OnButtonLabel="1",const std::string& OffButtonLabel="0")
                :OnButton(new TextBox(Point(pos.X-66,pos.Y),Point(30,30),OnButtonLabel)),    //für Farbe ist ein Default hinterlegt
                 OffButton(new TextBox(Point(pos.X-33,pos.Y),Point(30,30),OffButtonLabel)),  //Konstruktor für Textbox übernimmt bereits die
                 Switch(Point(pos.X,pos.Y))                                                  //Initialisierung der Attribute von ColorBox
{}                              //Hier kein Offset, ist bereits im aufgerufenen Konstruktor

SwitchOnOff::~SwitchOnOff(){
    delete OnButton;
    delete OffButton;
    //Switch::~Switch();  braucht man nicht! Destruktoren von Basisklassen werden automatisch aufgerufen
}

void SwitchOnOff::onMouse(const Point& p){
    if((p > (OnButton->getPosition()))&&(p < (OnButton->getPosition() + OnButton->getSize()))){
        setState(true);
    }
    if((p > (OffButton->getPosition()))&&(p < (OffButton->getPosition() + OffButton->getSize()))){
        setState(false);
    }
}

void SwitchOnOff::setPosition(const Point& p){
    Position = p - Point(69,-3);
    OnButton->setPosition(p - Point(66,0));
    OffButton->setPosition(p - Point(33,0));
    Indicator->setPosition(p);      //Hätte auch setPosition von Klasse Switch aufrufen können, un dann nur noch
}                                   //OnButton und OffButton manuell setzen müssen

SwitchOnOff& SwitchOnOff::operator=(const SwitchOnOff& s){
    if(this != &s){
        Switch::operator=(s);

        delete OnButton;
        delete OffButton;

        OnButton = new TextBox(s.OnButton->getPosition(),s.OnButton->getSize(),s.OnButton->getText());
        OffButton = new TextBox(s.OffButton->getPosition(),s.OffButton->getSize(),s.OffButton->getText());
    }
}

void SwitchOnOff::show(){
    Switch::show();
    OnButton->show();
    OffButton->show();
}
