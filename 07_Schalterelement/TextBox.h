#include "ColorBox.h"
#include <string>

#ifndef TEXTBOX_H_INCLUDED
#define TEXTBOX_H_INCLUDED


class TextBox : public ColorBox{

    std::string Text;

public:
    TextBox(const Point& Position, const Point&Size, const std::string& Text);

    std::string getText() const;
    void setText(const std::string& Text);
    virtual void show() const;
};


#endif // TEXTBOX_H_INCLUDED
