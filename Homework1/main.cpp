#include "sorts.h"

void runTests();
void acceptInput();
void runEmpirical();

int main()
{
	cout << "Enter \"t\" to run tests" << endl;
	cout << "Enter \"u\" to run accept user input" << endl;
	cout << "Enter \"e\" to run empirical tests" << endl;
	char choice;
	bool done = false;
	while(done != true)
	{
		cin >> choice;
		if(choice == 't')
		{
			runTests();
			done = true;
		}
		else if(choice == 'u')
		{
			acceptInput();
			done = true;
		}
		else if(choice == 'e')
		{
			runEmpirical();
			done = true;
		}
		else
			cout << "not a valid choice, please re-enter" << endl;
	}
	
}

void runTests()
{
	vector<int> list;

	list.push_back(41);
	list.push_back(32);
	cout << "test 1: using k = 1" << endl << "unsorted: ";
	for(int i = 0; i < list.size(); i++)
		cout << list[i] << "  ";
	cout << endl << "sorted: ";
	mergesort(list,0,list.size() - 1,1);
	for(int i = 0; i < list.size(); i++)
		cout << list[i] << "  ";
	cout << endl << endl;

	list.clear();
	list.push_back(43);
	list.push_back(32);
	list.push_back(16);
	list.push_back(54);
	list.push_back(72);
	list.push_back(64);
	list.push_back(23);
	list.push_back(19);
	cout << "test 2: using k = 1" << endl << "unsorted: ";
	for(int i = 0; i < list.size(); i++)
		cout << list[i] << "  ";
	cout << endl << "sorted: ";
	mergesort(list,0,list.size() - 1,1);
	for(int i = 0; i < list.size(); i++)
		cout << list[i] << "  ";
	cout << endl << endl;

	list.clear();
	list.push_back(52);
	list.push_back(17);
	list.push_back(42);
	list.push_back(78);
	list.push_back(64);
	list.push_back(23);
	list.push_back(18);
	list.push_back(89);
	list.push_back(17);
	cout << "test 3: using k = 1" << endl << "unsorted: ";
	for(int i = 0; i < list.size(); i++)
		cout << list[i] << "  ";
	cout << endl << "sorted: ";
	mergesort(list,0,list.size() - 1,1);
	for(int i = 0; i < list.size(); i++)
		cout << list[i] << "  ";
	cout << endl << endl;

	list.clear();
	list.push_back(21);
	list.push_back(18);
	list.push_back(43);
	list.push_back(62);
	list.push_back(8);
	list.push_back(19);
	list.push_back(12);
	list.push_back(14);
	list.push_back(82);
	cout << "test 4: using k = 3" << endl << "unsorted ";
	for(int i = 0; i < list.size(); i++)
		cout << list[i] << "  ";
	cout << endl << "sorted: ";
	mergesort(list,0,list.size() - 1,3);
	for(int i = 0; i < list.size(); i++)
		cout << list[i] << "  ";
	cout << endl << endl;
}

void acceptInput()
{
	int temp = 1;
	int k;
	vector<int> list;
	cout << "Enter values to sort, enter a negative number when finished" << endl;
	while(temp >= 0 )
	{
		cin >> temp;
		if(temp >= 0)
			list.push_back(temp);
	}
	cout << "sorting using a k value of 2" << endl;
	mergesort(list, 0, list.size() - 1, 2);
	cout << "sorted list is: ";
	for(int i = 0; i < list.size(); i++)
		cout << list[i] << " ";
	cout << endl;
}

void runEmpirical()
{
	vector<int> list;
	int k;
	clock_t t1, t2;
	for(int j = 0; j < 200; j++)
	{
		list.clear();
		for(int i = 0; i < 600000; i++)
			list.push_back(rand() % 1000);
		t1 = clock();
		mergesort(list,0,list.size() - 1, j);
		t2 = clock();
		double diff = (double)t2 - (double)t1;
		diff = diff / CLOCKS_PER_SEC;
		cout << diff << endl;
	}
}
