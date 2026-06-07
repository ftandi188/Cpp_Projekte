#include "ColorBox.h"
#include "Point.h"

#ifndef SWITCH_H_INCLUDED
#define SWITCH_H_INCLUDED


class Switch : public ColorBox{
protected:
    bool State;
    ColorBox* Indicator;

public:
    Switch();
    Switch(const Switch& Source);
    Switch(const Point& Position);
    ~Switch();

    void onMouse(Point& Position);
    void setPosition(Point Position);

    bool getState() const;
    void setState(bool State);
    void show() const;

    Switch& operator=(Switch& rhs);
};


#endif // SWITCH_H_INCLUDED
