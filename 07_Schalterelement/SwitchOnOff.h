#include "TextBox.h"

#ifndef SWITCHONOFF_H_INCLUDED
#define SWITCHONOFF_H_INCLUDED


class SwitchOnOff : public Switch{
protected:
    TextBox* OnButton;
    TextBox* OffButton;

public:
    SwitchOnOff(const SwitchOnOff& s);
    SwitchOnOff(const Point& pos,const std::string& OnButtonLabel,const std::string& OffButtonLabel);
    ~SwitchOnOff();

    void onMouse(const Point& p);
    void setPosition(const Point& p);
    SwitchOnOff& operator=(const SwitchOnOff& s);
    void show();
};


#endif // SWITCHONOFF_H_INCLUDED
