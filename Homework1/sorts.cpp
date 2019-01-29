#include "sorts.h"

void mergesort(vector<int> &A, int p, int r, int k)
{
	if ((r - p) <= k) //if the size of chunk is <= k
		{
			vector<int> temp; //hold current chunk
			for(int i = p; i <= r; i++)
			{
				temp.push_back(A[i]); //transfer over chunk
			}
			insertionsort(temp);//sort the chunk
			int j = 0;
			for(int i = p; i <= r; i++)
			{
				A[i] = temp[j]; //transfer chunk back over
				j++;
			}
		}
	else if (p < r) //if size is 1, exit out (base case)
		{
		    int q = (p + r)/2;
			mergesort(A, p, q, k);
			mergesort(A, q+1, r, k);
			merge(A, p, q, r, k);
		}
}

//p is left end point. q is mid point. r is right end point.
void merge(vector<int> &A, int p, int q, int r, int k)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> L(n1 + 2);
	vector<int> R(n2 + 2);
	for(int i = 1; i <= n1; i++)
		L[i] = A[p + i - 1];
	for(int i = 1; i <= n2; i++)
		R[i] = A[q + i];
	L[n1+1] = INT_MAX;
	R[n2+1] = INT_MAX;
	int i = 1;
	int j = 1;
	for(int k = p; k <= r; k++)
	{
		if( L[i] <= R[j])
		{
			A[k] = L[i];
			i = i + 1;
		}
		else
		{
			A[k] = R[j];
			j = j + 1;
		}
	}
}

void insertionsort(vector<int> &A)
{
	for(int j = 1; j< A.size(); j++)
	{
		int key = A[j];
		int i = j - 1;
		while(i >= 0 && A[i] > key)
		{
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}
