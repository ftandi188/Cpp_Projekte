#include "TextBox.h"
#include "Point.h"
#include "Switch.h"
#include <string>

#ifndef SWITCHTOGGLE_H_INCLUDED
#define SWITCHTOGGLE_H_INCLUDED

class SwitchToggle : public Switch{
protected:
    TextBox* ToggleButton;

public:
    SwitchToggle(const SwitchToggle& s);
    SwitchToggle(const Point& pos,const std::string& ToggleButtonLabel);
    ~SwitchToggle();

    void onMouse(const Point& p);
    void setPosition(const Point& p);
    void show() const;

    SwitchToggle& operator=(const SwitchToggle& s);
};


#endif // SWITCHTOGGLE_H_INCLUDED
