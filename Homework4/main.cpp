#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

float getArea(vector<float>, vector<float>);
float det(vector<float>, vector<float>, int);

int main(int argc, char *argv[])
{
	if(argc < 2 || argc > 2) //too many arguments provided or not enough
	{
		cout << "Improper usage, exiting" << endl;
		return 0;
	}

	vector<float> x;	//will hold all x values in order
	vector<float> y;	//will hold all y values in order
	ifstream file;
	file.open(argv[1]);

	if(!file)	//check if file was unable to open
	{
		cout << "Unable to open file.\n";
		return 0;
	}

	while (!file.eof())
	{
		float temp;
		file >> temp;
		x.push_back(temp);	//read in x value
		file >> temp;
		y.push_back(temp);	//read in y value
	}
	x.erase(x.end() - 1);	//remove repeat at end caused by eof
	y.erase(y.end() - 1);

	cout << fixed;
	cout << setprecision(1);

	for(int i = 0; i < x.size(); i++)
		cout << left << setw(5) << x[i] << " " << y[i] << "\n";
	
	float area = getArea(x,y);
	cout << "Area: " << area << endl;
}


float getArea(vector<float> x, vector<float> y)
{
	float area = 0;
	for( int i = 0; i < x.size(); i++)	//step through and calculat the area of
	{									//every pair of lines from (0,0) to the
		area = area + det(x,y,i);		//coords specified in x and y vectors
	}
	if(area >= 0)
		return area;			//in cases where the shape goes around backwards
	else						//change from a negative area to a positive area
		return 0 - area;	
}

float det(vector<float> x, vector<float> y, int i)
{
	if(i != x.size() - 1)
	{
		float x1 = x[i];		//vector from (0,0) to point i
		float y1 = y[i];
		float x2 = x[i+1];      //vector from (0,0) to point i + 1
		float y2 = y[i+1];
		float det = ( x1 * y2 ) - ( y1 * x2);	//calculate determinant
		return det/2;
	}
	else
	{
		float x1 = x[i];		//vector from (0,0) to point i
		float y1 = y[i];
		float x2 = x[0];		//vector from (0,0) to point i + 1
		float y2 = y[0];
		float det = ( x1 * y2 ) - ( y1 * x2 );	//calculate determinant
		return det/2;
	}
}
