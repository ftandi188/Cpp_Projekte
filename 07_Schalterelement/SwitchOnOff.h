#include "TextBox.h"

#ifndef SWITCHONOFF_H_INCLUDED
#define SWITCHONOFF_H_INCLUDED


class SwitchOnOff : public Switch{
protected:
    TextBox* OnButton;
    TextBox* OffButton;

public:
    SwitchOnOff(const SwitchOnOff& s);
    SwitchOnOff(const Point& pos,const std::string& OnButtonLabel = "1",const std::string& OffButtonLabel = "0");
    ~SwitchOnOff();

    void onMouse(const Point& p) override;
    void setPosition(const Point& p);
    SwitchOnOff& operator=(const SwitchOnOff& s);
    void show() const override;
};


#endif // SWITCHONOFF_H_INCLUDED
