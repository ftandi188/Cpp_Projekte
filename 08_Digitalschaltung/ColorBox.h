#include "Point.h"
#include "RGBColor.h"

#ifndef COLORBOX_H_INCLUDED
#define COLORBOX_H_INCLUDED


class ColorBox{
protected:
    Point Position;
    Point Size;
    RGBColor Color;

public:
    ColorBox(const Point& Position, const Point& Size, const RGBColor& Color);

    bool contains(const Point& f) const;
    virtual void show() const;

    Point getPosition() const;
    Point getSize() const;
    RGBColor getColor() const;
    void setPosition(const Point& p);
    void setSize(const Point& s);
    void setColor(const RGBColor& c);
};


#endif // COLORBOX_H_INCLUDED
