#include<iostream>
#include<vector>

using namespace std;

// TimeComplexity : O(n)
// SpaceComplexity : O(1)
int minNumJumps(vector<int> &A)
{
  int i = 0,result= 0;
  size_t aSize = A.size();
  int end = aSize-1;
  while(i<=end)
  {
      result += 1;
      int curMaxStep = A[i];
      if((i + curMaxStep) >= end)
      {
         return result;
      }

      if(curMaxStep == 0)
      {
        break;
      }   

      int max = -1;
      int maxIndex = -1;
  
      for(int j = 1;j<=curMaxStep;j++)
      {
         if((A[i+j] - (curMaxStep - j)) > max)
         {
            max = A[i+j] - (curMaxStep-j);
            maxIndex = i + j;
         }
      }
      i = maxIndex;
  }
  return -1;
}

// Approach #1 Recursive

// Approach #2 Recusize Memoized

// Approach #3 Bottom Up


int main()
{
 vector<int> A = {1,3,5,8,9,2,6,7,6,8,9};
 int minJumps  =  minNumJumps(A);
 cout << "minJumps, " << minJumps << endl;
}
