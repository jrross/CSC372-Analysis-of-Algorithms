#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

void printOrig(vector<vector<int> >,vector<vector<int> >, int);
int solveDynamic(vector<vector<int> >, vector<vector<int> >,
				 vector<vector<int> >&, vector<vector<int> >&, int, int);
void runDynamic(vector<vector<int> >,vector<vector<int> >,int,int);
void runPermute(vector<vector<int> >,vector<vector<int> >, int);
void printPath(vector<vector<int> >, vector<vector<int> >, int, int);
void getCombos(vector<vector<int> >, int, vector<int>,vector<vector<int> > &);
int min(int, int);
int max(int, int);
