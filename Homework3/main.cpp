#include "functions.h"

int main(int argc, char *argv[])
{
	if(argc > 3 || argc < 3)
	{
		cout << "improper usage\n";
		return 0;
	}

	ifstream file;
	file.open(argv[1]);
	if(!file)
	{
		cout << "unable to open " << argv[1] << endl;
		return 0;
	}

	if(file.peek() == std::ifstream::traits_type::eof())
	{
		cout << "no data provided" << endl;
		return 0;
	}

	istringstream ss(argv[2]);
	int startAmt;
	ss >> startAmt;			//convert command line argument to integer
	int locationNum;
	int optionNum;
	file >> locationNum;	//start off by getting number of locations
	vector<vector<int> > cost(locationNum);
	vector<vector<int> > revenue(locationNum);

	for(int i = 0; i < locationNum; i++)	//go for each location
	{
		file >> optionNum;		//find the number of options per location
		int temp;
		cost[i].push_back(0);		//Include option where no plan is chosen
		revenue[i].push_back(0);	
		for(int j = 0; j < optionNum; j++)	//read in all the options to
		{									//corresponding location
			file >> temp;
			cost[i].push_back(temp);
			file >> temp;
			revenue[i].push_back(temp);
		}
	}

	printOrig(cost, revenue, locationNum);
	runDynamic(cost, revenue, startAmt, locationNum);
	runPermute(cost, revenue, startAmt);
}
