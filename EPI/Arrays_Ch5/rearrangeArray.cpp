#include<iostream>
#include "arrUtil.cpp"

using namespace std;

void rearrange(const vector<int> &B,vector<int>& A)
{
	int maxI = -1;
	int end = B.size()-1;
	A = B;
	
	for(int i = 1;i<end;i+=2)
	{
		maxI = i;
		if(A[i] < A[i-1]) { maxI = i-1;}
		if(A[maxI] < A[i+1]){ maxI = i+1;}
		if(maxI != i)
		{
			swap(A[maxI],A[i]);
		}

	}
}

int main()
{
	vector<int> B =  {3,1,7,4,6,8,9};
	vector<int> B1 = {3,1,7,4,6,3,2};
	vector<int> A; 
	rearrange(B,A);
	printVector(A);
	rearrange(B1,A);
	printVector(A);
}
