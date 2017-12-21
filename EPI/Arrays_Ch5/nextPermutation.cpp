#include<iostream>
#include<vector>
#include<algorithm> // reverse,sorted_until,upper_bound
#include "arrUtil.h"

using namespace std;


// Time Complexity : O(n)
// Space Complexity : O(1)
void findNextPermutation(vector<int> P)
{
  cout << "findNextPermutation" << endl;
  size_t pSize = P.size();
  int y=0,x=0,minIndex=0,min=std::numeric_limits<int>::max();
  for(y= pSize-1;y>=0;y--)
  {
	if(P[y] > P[y-1])
        break;
  }

  x = y-1;
  for(int i = y;i<=pSize-1;i++)
  {
	if(P[i] > P[x])
        {
		if(P[i] < min)
		{
			min = P[i];
			minIndex = i;
		}
	} 
  }

  swap(P[x],P[minIndex]);
  reverse(P.begin()+y,P.end()); 
  printVector(P);
}


// Reduce code using inbuilt C++ methods
void findNextPermutationCompact(vector<int> P)
{
  cout << "findNextPermutationCompact" << endl;
  auto x = is_sorted_until(P.rbegin(),P.rend()); // returns reverse iterator
  cout << "x = " << *x << endl;

  auto min = upper_bound(P.rbegin(),x,*x); // reverse iterator

  iter_swap(x,min);
  reverse(P.rbegin(),x);
  printVector(P);
}


int main()
{
 vector<int> P = {0,1,5,4,3,2};
 printVector(P);
 findNextPermutation(P);
 findNextPermutationCompact(P);

 vector<int> P1 = {0,1,2,3,4,5};
 printVector(P1);
 findNextPermutation(P1);
 findNextPermutationCompact(P1);
}
