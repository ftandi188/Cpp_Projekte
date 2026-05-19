#ifndef FARBE_H
#define FARBE_H

class RGBColor
{
    public:
	int R;
	int G;
	int B;
	RGBColor(int R, int G, int B);
	bool operator== (const RGBColor &f) const;
};

#endif
