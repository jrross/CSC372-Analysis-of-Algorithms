#include "color.h"

color::~color() {}	//destructor

color::color(int r, int g, int b)	//constructor
{
	red = r;
	green = g;
	blue = b;
}

int color::getR()
{
	return red;
}

int color::getG()
{
	return green;
}

int color::getB()
{
	return blue;
}

void color::print()
{
	cout << setw(3) << red << ", "
		 << setw(3) << green << ", "
		 << setw(3) << blue << endl;
}
