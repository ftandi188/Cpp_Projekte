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
    SwitchToggle(const Point& pos,const std::string& ToggleButtonLabel = "1/0");
    ~SwitchToggle();

    void onMouse(const Point& p) override;
    void setPosition(const Point& p);
    void show() const override;

    SwitchToggle& operator=(const SwitchToggle& s);
};


#endif // SWITCHTOGGLE_H_INCLUDED
