#include "mersenne.h"
//LOOK HERE TO TEST
//TAKES INPUT OF A FILE OF NAMES/VALUES TO CHOOSE FROM (VALUES SEPERATED BY LINE)
//FOLLOWED BY THE NUMBER OF VALUES TO PICK, THE THIRD INPUT VALUE IS OPTIONAL AND
//FOR TESTING PURPOSES, BUT TELLS HOW MANY TIMES TO RUN THE PROCESS AND OUTPUTS
//HOW MANY TIMES EACH VALUE HAS BEEN CHOSEN. THIS THIRD VALUE IS CODED TO BE RUN
//CHOOSING 1 NUMBER PER RUN, IT STILL WORKS WITH OTHER VALUES BUT THE ENDING VALUES
//WILL NOT BE UNIFORM WITH THE REST OF THE SET.
int main(int argc, char *argv[])
{
	ifstream file;
	file.open(argv[1]);
	if(!file)
	{
		cout << "Unable to open file.\n";
		return 0;
	}
	int calls = atoi(argv[2]);
	//default run once
	int runs = 1;	
	//if the testing option was used indicate how many times to run
	if(argc == 4)
		runs = atoi(argv[3]);
		

	vector<string> names;
	vector<int> visits;
	//vector used to hold the initial list since it gets cut down in process
	vector<string> hold;
	string temp;
	while (!file.eof())	//read the entire file into a vector
	{
		getline(file,temp);
		names.push_back(temp);
		//initialize test case to 0s
		visits.push_back(0);
	}
	names.erase(names.end());	//erase duplicate at end
	hold = names;
	
	//for testing purposes, run the selection process multiple times
	for(int j = 0; j < runs; j++)
	{	//reset the names vector after every run
		names = hold;
		//choose the number of winners as indicated by the user
		for(int i = 0; i < calls; i++)
		{	//if the user has entered a number greater than the number of names
			if(names.size() == 0)
			{
				cout << "There are no names remaining.\n";
				return 0;
			}
	
			int seed = nano();
			int random = getRand(seed);
			//mod the number down to fit within size of vector
			random = random % names.size();
			visits[random] = visits[random] + 1;
			//do not print out values if this is a test run
			if(runs == 1)
				cout << names[random] << endl;
			//delete the point in the vector to prevent duplicates
			names.erase(names.begin() + random);
		}
	}

	//if test run print out how many times each value was visited
	if(runs != 1)
	{
		for(int i = 0; i < hold.size(); i++)
			cout << hold[i] << ":  " << visits[i] << endl;
	}
}
