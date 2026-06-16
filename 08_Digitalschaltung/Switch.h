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
    virtual ~Switch();

    virtual void onMouse(const Point& Position);
    virtual void setPosition(const Point& Position);

    bool getState() const;
    void setState(bool State);
    virtual void show() const;

    Switch& operator=(const Switch& rhs);


};


#endif // SWITCH_H_INCLUDED
