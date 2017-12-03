#include<iostream>
#include<vector>

using namespace std;

/* 
A = [3 3 3 1 2 3 4 1], reachEndOfArray should return true
A = [3 1 0 0 2 3 4 1], reachEndOfArray should return false
*/

// Time Complexity   = O(n) 
// Space Complexity  = O(1)
bool reachEndOfArray(const std::vector<int> &A)
{
  int reachIndex = 0;
  int farthestIndex = 0;
  size_t size = A.size();
  for(int reachIndex = 0;reachIndex < size; reachIndex++)
  {
	//cout << "reachIndex=" << reachIndex << endl;
	//cout << "farthestIndex=" << farthestIndex << endl;
	if(reachIndex > farthestIndex)
        {
		break;
	}

	farthestIndex = std::max(farthestIndex,(A[reachIndex] + reachIndex));	
	if(farthestIndex >= size)
	{
		return true;
	}
  }
 return false;
}

/* 
A = [3 3 3 1 2 3 4 1], reachEndOfArray should return true
A = [3 1 0 0 2 3 4 1], reachEndOfArray should return false
*/

// Time Complexity   = O(n) 
// Space Complexity  = O(1)
int minNumOfStepsToReachEndOfArray(const std::vector<int> &A)
{
return -1;
}

int main()
{
std::vector<int> A = {3,3,3,1,2,3,4,1};
cout << "Min Steps = " << minNumOfStepsToReachEndOfArray(A) << endl;
cout << "Can reach end of array  = " << reachEndOfArray(A) << endl;
std::vector<int> B = {3,1,0,0,2,3,4,1};
cout << "Min Steps = " << minNumOfStepsToReachEndOfArray(B) << endl;
cout << "Can reach end of array  = " << reachEndOfArray(B) << endl;
return 1;
}
