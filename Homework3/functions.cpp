#include "functions.h"

void printOrig(vector<vector<int> > c,vector<vector<int> >r, int l)
{
	cout << "INPUT\n";
	for(int i = 0; i < l; i++)
	{
		cout << "location " << i + 1 << endl;
		for(int j = 0; j < c[i].size(); j++)
		{
			cout << left << setw(3)<< c[i][j] << " " << r[i][j] << endl;
		}
	}
	cout<< "-----------------------------------\n";
}

void runDynamic(vector<vector<int> >cost,vector<vector<int> > revenue,
				int startAmt,int locationNum)
{
	vector<vector<int> > total(locationNum,vector<int>(startAmt + 1, -32767));
	vector<vector<int> > split(locationNum,vector<int>(startAmt + 1, 0));
	clock_t t1, t2;
	int soln = 0;
	t1 = clock();	//take the time before starting

	//for loop to go through every location, each call on solveDynamic solves the most
	//optimal solutions for every budget 0 to n, each call will return the largest value
	for (int i = 0; i < cost.size(); i++)
	{
		soln = solveDynamic(cost, revenue, total, split, startAmt, i);
		cout << "Location " << i + 1 << "\nn   best  split\n";
		for(int j = 0; j < total[i].size(); j++)
			cout << left << setw(6) << j << setw(6) << total[i][j] << split[i][j] << endl;	
	}

	t2 = clock();	//take the time after finishing
	cout << "max profit is: " << soln  << endl;
	printPath(split, cost, startAmt, locationNum);	//print what options to take
	double diff = (double)t2 - (double)t1;
	diff = diff / CLOCKS_PER_SEC;		//find the total amount of time taken
	cout << "runtime for dynamic: "<< diff << endl;
}

//HERE I = LOCATION NUMBER AND N = TOTAL BUDGET AVAILABLE
int solveDynamic(vector<vector<int> >cost,vector<vector<int> >revenue,
				 vector<vector<int> >&total,vector<vector<int> >&split, int n, int i)
{
	if(total[i][n] > 0)
		return total[i][n];
	int val;
	if(n == 0)
		val = 0;
	else
	{
		val = solveDynamic(cost, revenue, total, split, n-1, i);
		bool found; //indicates if a better option than previous has been found
		for(int j = 0; j < cost[i].size(); j++)
		{
			if(cost[i][j] > n)	//if plan is too expensive
				break;
			int result;
			if(i == 0)	//check if this is the first location if it is,
						//find whether any affordable values in revenue are greater
						//than the profit for the profit found at n-1
				result = max(val, revenue[i][j]);
			//if is not first location, check if the revenue for option j + the
			//value at the previous location for a budget of n-j is greater than
			//any value found thus far
			else
				result = max(val, revenue[i][j] + total[i-1][n-cost[i][j]]);
			if(result > val)
			{
				val = result;
				split[i][n] = j;
				found = true;		//indicate something better has been found
			}
		}
		if(!found)		//if nothing new found, copy previous 
			split[i][n] = split[i][n-1];
	}
	total[i][n] = val;
	return val;
}

void printPath(vector<vector<int> >split, vector<vector<int> > cost, int n, int loc)
{
	cout<< "-----------------------------------\n";
	cout << "The options taken are: \n";
	loc = loc - 1;
	while(loc >= 0)
	{
		if(split[loc][n] != 0)
			cout << "Option " << split[loc][n] << " from location " << loc + 1 << endl;;
		n = n - cost[loc][split[loc][n]];
		loc = loc - 1;
	}
	cout<< "-----------------------------------\n";
}

void runPermute(vector<vector<int> >cost,vector<vector<int> >rev, int n)
{
	vector<vector<int> > combinations;
	vector<int> temp;
	clock_t t1, t2;
	t1 = clock();		//get time of starting
	getCombos(cost,0,temp,combinations);	//get all combinations of options
	
	int max = 0;
	int ival;	//i value to identify the vector containing optimal solution
	for(int i = 0; i < combinations.size(); i++)
	{
		int ctemp = 0;
		int rtemp = 0;
		for(int j = 0; j < combinations[i].size(); j++)
		{
			ctemp = ctemp + cost[j][combinations[i][j]];
			rtemp = rtemp + rev[j][combinations[i][j]];
		}
		if(ctemp <= n && rtemp > max)
		{
			max = rtemp;
			ival = i;
		}
		
	}
	t2 = clock();	//take the time after finishing
	double diff = (double)t2 - (double)t1;
	diff = diff / CLOCKS_PER_SEC;		//find the total amount of time taken
	cout << "runtime for naive: " << diff << endl << endl;

	/*cout << "values found from naive:" << endl;
	cout << "Max profit of: " << max << endl;
	cout << "using options: ";
	for( int i = 0; i < combinations[ival].size(); i++)
		cout << combinations[ival][i] << ", ";
	cout << "from locations 1-" << combinations[ival].size() << endl;*/
	
}
//function to step through and fill a 2d vector with vectors of all the option combinations
void getCombos(vector<vector<int> > array, int i, vector<int> combos,
			   vector<vector<int> > &combinations)
{
    if (i == array.size()) // done, no more rows
    {
        combinations.push_back(combos);
    }
    else
    {
        vector<int> row = array[i];
        for(int j = 0; j < row.size(); ++j)
        {
            vector<int> tmp(combos);
            tmp.push_back(j);
            getCombos(array,i+1,tmp, combinations);
        }
    }
}

int min(int a, int b)
{
	if(a < b)
		return a;
	else
		return b;
}

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}
