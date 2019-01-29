#include "functions.h"

int main(int argc, char *argv[])
{
	if(argc > 2) //too many arguments provided
	{
		cout << "Improper usage, only use one file" << endl;
		return 0;
	}

	bool fileInc = false;	//bool to tell if a file had been included
	vector<color> data;

	if(argc == 2)	//file provided
	{
		fileInc = true;
		ifstream file;
		file.open(argv[1]);
		if(!file)	//check if file was unable to open
		{
			cout << "Unable to open file.\n";
			return 0;
		}

		while (!file.eof())
		{
			int r, g, b;	//read in each primary color individually
			file >> r;		//store together in a color class to
			file >> g;		//hold all three
			file >> b;
			color temp(r, g, b);
			data.push_back(temp);
		}
		data.erase(data.end() - 1);	//remove repeat at end caused by eof
	}
	
	if(!fileInc)
	{
		char choice;
		cout << "Enter T to run tests\nEnter U to run accept user input" << endl;
		cin >> choice;
		if(choice == 't' || choice == 'T')
		{
			runTest1();
			runTest2();
			runtest3();
			runTest4();
			return 0;
		}

		else if(choice == 'u' || choice == 'U')
		{
			int hold = 1;
			while(!cin.eof())	//run until user inputs ctrl+d or ctrl+z
			{
				cin >> hold;
				int r = hold;	//get red
				cin >> hold;	
				int g = hold;	//get green
				cin >> hold;
				int b = hold;	//get blue
				color temp(r, g, b);
				data.push_back(temp);
			}
			data.erase(data.end() - 1);	//remove repeat at end caused by eof
		}

		else
		{
			cout << "not a valid input" << endl;
			return 0;
		}
		
	}
	cout << "\nOriginal order:\n";
	for(int i = 0; i < data.size(); i++)
	{
		data[i].print();
	}
	radix(data);
	cout << "Sorted order:\n";
	for(int i = 0; i < data.size(); i++)
	{
		data[i].print();
	}
	return 0;
}
