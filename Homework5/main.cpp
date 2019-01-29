#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;

//structure used to return values in euclid
struct dxy
{
	int d;
	int x;
	int y;
	dxy(int, int, int);
};

//constructor for the structure
dxy::dxy(int din, int xin, int yin)
{
	d = din;
	x = xin;
	y = yin;
}

char modExp(char a, int b, long int n);
dxy euclid(int a, int b);

int main(int argc, char *argv[])
{
	int p = atoi(argv[1]);
	int q = atoi(argv[2]);
	int e = atoi(argv[3]);
	long int n = p * q;
	long int phi = (p - 1)*(q - 1);

	//check to make sure e is not a factor of phi
	if(phi%e == 0)
	{
		cout << "E is invalid!\n";
		return 0;
	}

	dxy val = euclid(e, phi);
	int d = val.x;

	//if d is a negative value, add phi until it is positive
	while(d < 0)
		d = d + phi;

	string msg = argv[4];
	vector<int> nums;
	vector<long> encrypt;

	//fill vector with extra command line values to be decoded
	for(int i = 5; i < argc; i++)
		nums.push_back(atoi(argv[i]));

	cout << "D: " << d << endl;
	cout << "Encrypted (" << msg << "): ";
	for(int i = 0; i < msg.length(); i++)
	{	//fill a vector with the encrypted message
		encrypt.push_back(modExp(msg[i],e,n));
		cout << encrypt[i] << " ";
	}
	
		//decrypt the vector with the encrypted message.
	cout << "\nDecoding gives: ";
	for(int i = 0; i < msg.length(); i++)
		cout << modExp(encrypt[i],d,n);

	if(nums.size() > 0)
	{
		cout << "\nDecoding command line gives: ";
		for(int i = 0; i < nums.size(); i++)
			cout << modExp(nums[i],d,n);
	}
	cout << endl;
}

char modExp(char a, int b, long int n) //a ^ b mod n
{	//get around memory limitations by manually multiplying
	char d = 1;
	for(int i = 1; i <= b; i++)
		d = (d * a)%n;
	return d;
}

//Used to find the multiplicative inverse
dxy euclid(int a, int b)
{
	if (b == 0)
	{
		dxy temp(a,1,0);
		return temp;
	}

	else
	{
		dxy temp = euclid(b, a%b);
			//(d',x,y) = (d',y',x' - [a/b]y')
		int holdy = temp.y;
		temp.y = temp.x - (a/b)*temp.y;
		temp.x = holdy;
		return temp;
	}
}
