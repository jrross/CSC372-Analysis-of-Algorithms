#include "functions.h"

void radix(vector<color> &data)
{
	sortBlue(data);
	sortGreen(data);
	sortRed(data);
}

void sortGreen(vector<color> &data)
{
	int temp[256]; //set to go from 0 to 255
	vector<color> dCopy(data.size(), color(0,0,0)); //copy vector to hold values after sort

	//initialize temp array to 0
	for(int i = 0; i < 256; i++)
		temp[i] = 0;

	//set temp[i] to contain # of elements = i
	for(int i = 0; i < data.size(); i++)
		temp[data[i].getG()] = temp[data[i].getG()] + 1;

	//set temp[i] to contain number of elements <= i
	for(int i = 1; i < 256; i++)
		temp[i] = temp[i] + temp[i-1];

	//step through backwards and sort into copy
	for(int i = data.size() - 1; i >= 0; i--)
	{
		dCopy[temp[data[i].getG()] - 1] = data[i];
		temp[data[i].getG()] = temp[data[i].getG()] - 1;
	}
	data = dCopy;	//put the sorted vector into original
}

void sortRed(vector<color> &data)
{
	int temp[256]; //set to go from 0 to 255
	vector<color> dCopy(data.size(), color(0,0,0)); //copy vector to hold values after sort

	//initialize temp array to 0
	for(int i = 0; i < 256; i++)
		temp[i] = 0;

	//set temp[i] to contain # of elements = i
	for(int i = 0; i < data.size(); i++)
		temp[data[i].getR()] = temp[data[i].getR()] + 1;

	//set temp[i] to contain number of elements <= i
	for(int i = 1; i < 256; i++)
		temp[i] = temp[i] + temp[i-1];

	//step through backwards and sort into copy
	for(int i = data.size() - 1; i >= 0; i--)
	{
		dCopy[temp[data[i].getR()] - 1] = data[i];
		temp[data[i].getR()] = temp[data[i].getR()] - 1;
	}
	data = dCopy;	//put the sorted vector into original
}

void sortBlue(vector<color> &data)
{
	int temp[256]; //set to go from 0 to 255
	vector<color> dCopy(data.size(), color(0,0,0)); //copy vector to hold values after sort

	//initialize temp array to 0
	for(int i = 0; i < 256; i++)
		temp[i] = 0;

	//set temp[i] to contain # of elements = i
	for(int i = 0; i < data.size(); i++)
		temp[data[i].getB()] = temp[data[i].getB()] + 1;

	//set temp[i] to contain number of elements <= i
	for(int i = 1; i < 256; i++)
		temp[i] = temp[i] + temp[i-1];

	//step through backwards and sort into copy
	for(int i = data.size() - 1; i >= 0; i--)
	{
		dCopy[temp[data[i].getB()] - 1] = data[i];
		temp[data[i].getB()] = temp[data[i].getB()] - 1;
	}
	data = dCopy;	//put the sorted vector into original
}

void runTest1()
{
	vector<color> data;
	vector<color> sorted;

	data.push_back(color(5,1,1));
	data.push_back(color(4,2,2));
	data.push_back(color(3,3,3));
	data.push_back(color(2,4,4));
	data.push_back(color(1,5,5));
	

	sorted = data;

	radix(sorted);
	cout << "Test #1: Checking to make sure red has priority\nUnsorterd list:\n";
	for(int i = 0; i < data.size(); i++)
	{
		data[i].print();
	}
	cout << "Sorted list:\n";
	for(int i = 0; i < sorted.size(); i++)
	{
		sorted[i].print();
	}
	bool pass = checkSorted(sorted);

	if(pass)
		cout << "passed\n";
	else
		cout << "failed\n";
}

void runTest2()
{
	vector<color> data;
	vector<color> sorted;

	data.push_back(color(1,5,1));
	data.push_back(color(1,4,2));
	data.push_back(color(1,3,3));
	data.push_back(color(1,2,4));
	data.push_back(color(1,1,5));

	sorted = data;

	radix(sorted);
	cout << "Test #2: Checking to make sure green has priority over blue\nUnsorterd list:\n";
	for(int i = 0; i < data.size(); i++)
	{
		data[i].print();
	}
	cout << "Sorted list:\n";
	for(int i = 0; i < sorted.size(); i++)
	{
		sorted[i].print();
	}
	bool pass = checkSorted(sorted);

	if(pass)
		cout << "passed\n";
	else
		cout << "failed\n";
}

void runtest3()
{
	vector<color> data;
	vector<color> sorted;

	data.push_back(color(255,255,255));
	data.push_back(color(0,0,0));
	data.push_back(color(255,0,255));
	data.push_back(color(0,255,255));
	data.push_back(color(255,255,0));
	data.push_back(color(0,0,255));
	data.push_back(color(0,255,0));
	data.push_back(color(255,0,0));

	sorted = data;

	radix(sorted);
	cout << "Test #3: Checking upper and lower bounds\nUnsorterd list:\n";
	for(int i = 0; i < data.size(); i++)
	{
		data[i].print();
	}
	cout << "Sorted list:\n";
	for(int i = 0; i < sorted.size(); i++)
	{
		sorted[i].print();
	}
	bool pass = checkSorted(sorted);

	if(pass)
		cout << "passed\n";
	else
		cout << "failed\n";
}

void runTest4()
{
	vector<color> data;
	vector<color> sorted;

	data.push_back(color(15,237,132));
	data.push_back(color(199,190,202));
	data.push_back(color(29,209,135));
	data.push_back(color(150,114,111));
	data.push_back(color(98,20,81));
	data.push_back(color(42,13,128));
	data.push_back(color(15,152,117));
	data.push_back(color(60,161,144));
	data.push_back(color(172,37,87));
	data.push_back(color(236,92,229));

	sorted = data;

	radix(sorted);
	cout << "Test #4: randomly generated list of 10 colors\nUnsorterd list:\n";
	for(int i = 0; i < data.size(); i++)
	{
		data[i].print();
	}
	cout << "Sorted list:\n";
	for(int i = 0; i < sorted.size(); i++)
	{
		sorted[i].print();
	}
	bool pass = checkSorted(sorted);
	
	if(pass)
		cout << "passed\n";
	else
		cout << "failed\n";
}

bool checkSorted(vector<color> sorted)
{
	if(sorted.size() == 1)//special case where array is one element
		return true;
	for(int i = 0; i < sorted.size()-1; i++)
	{
		//make sure red is properly sorted
		if(sorted[i].getR() > sorted[i + 1].getR())
		{
			return false;
		}
		//make sure green is properly sorted if reds are equal
		if((sorted[i].getR() == sorted[i + 1].getR()) &&
		   (sorted[i].getG() > sorted[i + 1].getG())) 
		{
			return false;
		}
		//make sure blue is properly sorted if reds and greens are equal
		if((sorted[i].getR() == sorted[i + 1].getR()) &&
		   (sorted[i].getG() == sorted[i + 1].getG()) &&
		   (sorted[i].getB() > sorted[i + 1].getB()))
		{
			return false;
		}
	}
	return true;
}
