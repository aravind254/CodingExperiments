#include<iostream>
#include<vector>
#include "arrUtil.h"

using namespace std;


// TimeComplexity : O(n)
// SpaceComplexity : O(1)
void applyPermutation(vector<char> &A, const vector<int> &P)
{
 unsigned int posBitMap=0;
 size_t aSize = A.size();
 size_t pSize = P.size();
 int pos = 0;
 int i = 0;
 int nextP=0;
 if(aSize != pSize) return;

 nextP = i;
 while(i<aSize)
 {
    pos = P[nextP];

    if((i == pos) || (posBitMap & (1<<i)))
    {
      i++;
      nextP = i;
      continue;
    }

    if(!(posBitMap & (1<<i)))
    {
	swap(A[i],A[pos]);
    }

    posBitMap |= (1<<pos);
    nextP = pos;
 }
}

int main()
{
vector<char> A = {'a','b','c','d'};
vector<int>  P = {2,0,1,3};

vector<char> A1 = {'a','b','c','d','e','f'};
vector<int>  P1 = {2,1,4,3,0,5};

applyPermutation(A,P);
printVector(A);

applyPermutation(A1,P1);
printVector(A1);
}
