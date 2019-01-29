#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

#ifndef COLOR_H
#define COLOR_H
class color
{
	public:

	color(int r, int g, int b);	//constructor
	~color();	//destructor

	int getR();
	int getG();
	int getB();
	void print();

	private:

	int red;
	int green;
	int blue;
};
#endif
