

#include "RGBColor.h"

RGBColor::RGBColor(int R, int G, int B)
: R(R), G(G), B(B)
{
}

bool RGBColor::operator== (const RGBColor &f) const
{
    return (R==f.R) && (G==f.G) && (B==f.B);
}
