#include<iostream>
#include<vector>

using namespace std;

// Approach #1:  Recursive Solution for LIS
// TimeComplexity : O(2^n)
// This method computes all possible longest Increasing Subsequences and finds the largest of them.
// There are repeated calls to the function with same params. 
// for example 10,22,33 or 10,33 would result in a call with prev as 33 and curPos as 4.
int LISRecursive(const vector<int>&A, int prev, int curPos)
{
   cout << "prev," << prev << ",curPos," << curPos << endl;
   // Base Case
   if(curPos == A.size())
   {
      return 0;
   }

   int selectCurPos = 0;
   if(A[curPos] > prev)
   { 
     selectCurPos = 1 + LISRecursive(A,A[curPos],curPos+1); 
   }
   
   int notSelectedCurPos = LISRecursive(A,prev,curPos+1);
   
   return max(selectCurPos,notSelectedCurPos);
}

// Approach #2:  Memoized Recursive Solution for LIS
// TimeComplexity : O(n^2)
// SpaceComplexity : O(n^2)
// This method computes all possible longest Increasing Subsequences and finds the largest of them.
// There are repeated calls to the function with same params. 
// for example 10,22,33 or 10,33 would result in a call with prev as 33 and curPos as 4.
int LISRecursiveMemoizedHelper(const vector<int>&A, int prevPos, int curPos,vector<vector<int>> &LIS);
#define INVALID_VAL -1
int LISRecursiveMemoized(const vector<int>&A)
{
   vector<vector<int>> memoized(A.size()+1,vector<int>(A.size(),INVALID_VAL));
   return LISRecursiveMemoizedHelper(A,-1,0,memoized);
}

int LISRecursiveMemoizedHelper(const vector<int>&A, int prevPos, int curPos,vector<vector<int>> &LIS)
{
   // Base Case
   if(curPos == A.size())
   {
      return 0;
   }

   if(LIS[prevPos+1][curPos] != INVALID_VAL)
   {
       cout << "Using Cache prevPos," << prevPos << ",curPos," << curPos << endl;
      return LIS[prevPos+1][curPos];
   }

    cout << "Perform Work prevPos," << prevPos << ",curPos," << curPos << endl; 

   int selectCurPos = 0;
   if((prevPos < 0) || (A[curPos] > A[prevPos]))
   {
     selectCurPos = 1 + LISRecursiveMemoizedHelper(A,curPos,curPos+1,LIS);
   }
  
   int notSelectedCurPos = LISRecursiveMemoizedHelper(A,prevPos,curPos+1,LIS);
  
   LIS[prevPos+1][curPos] = max(selectCurPos,notSelectedCurPos);
   return  LIS[prevPos+1][curPos];
}

/*
// Approach #2 B:  Memoized Recursive Solution for LIS, with String LIS
// TimeComplexity : O(n^2)
// SpaceComplexity : O(n^2)
// This method computes all possible longest Increasing Subsequences and finds the largest of them.
// There are repeated calls to the function with same params.
// for example 10,22,33 or 10,33 would result in a call with prev as 33 and curPos as 4.
int LISRecursiveMemoizedHelper(const vector<int>&A, int prevPos, int curPos,vector<vector<int>> &LIS);
#define INVALID_VAL -1
vector<int> LISRecursiveMemoizedWithString(const vector<int>&A)
{  
   vector<vector<int>> memoized(A.size()+1,vector<int>(A.size(),INVALID_VAL));
   vector<int> result = LISRecursiveMemoizedWithStringHelper(A,-1,0,memoized);
   return result;
}

vector<int> LISRecursiveMemoizedWithStringHelper(const vector<int>&A, int prevPos, int curPos,vector<vector<int>> &LIS)
{  
   // Base Case 
   if(curPos == A.size())
   {  
      return 0;
   }

   if(LIS[prevPos+1][curPos] != INVALID_VAL)
   {
       cout << "Using Cache prevPos," << prevPos << ",curPos," << curPos << endl;
      return LIS[prevPos+1][curPos];
   }

    cout << "Perform Work prevPos," << prevPos << ",curPos," << curPos << endl;

   vector<int> selectCurPos; 
   if((prevPos < 0) || (A[curPos] > A[prevPos]))
   {
     selectCurPos.emplace_back(A[curPos]);
     vector<int> temp = LISRecursiveMemoizedHelper(A,curPos,curPos+1,LIS);
     selectCurPos.insert(selectCurPos.end(),temp.begin(),temp.end());
   }

   vector<int> notSelectedCurPos = LISRecursiveMemoizedHelper(A,prevPos,curPos+1,LIS);

   LIS[prevPos+1][curPos] = max(selectCurPos.size(),notSelectedCurPos.size());
   return  LIS[prevPos+1][curPos];
}


// END

*/


// Approach #3 A: This solution uses bottom Up DP technique and finds the length of LIS
// Time Complexity : O(n^2)
int longestIncreasingSubSequence(const vector<int> &A)
{
  size_t iSize = A.size();
  vector<int> LIS(iSize,1);
  int result = -1;
  
  for(int i = 1;i<iSize;i++)
  {
    int curMax = 0;
    for(int j = 0;j<i;j++)
    {
      if(A[i] > A[j])
      {
         curMax = max(LIS[j],curMax);
      }
    }
    LIS[i] = curMax + 1;
    result = max(result,LIS[i]);
  }

  return result;
}

// Approach #3 B:  This solution uses bottom Up DP technique and finds the LIS
// Time Complexity : O(n^2)
vector<int> longestIncreasingSubSequenceWithString(const vector<int> &A)
{
  size_t iSize = A.size();
  vector<vector<int>> LIS(iSize); // create iSize rows
  LIS[0].emplace_back(A[0]);
  int maxRow = 0;
  int maxLength = 0;
  
  for(int i = 1; i < iSize; i++)
  {
     for(int j = 0;j<i;j++)
     {
         if(A[i] > A[j])
         {
            if(LIS[j].size() > LIS[i].size())
            {
               LIS[i] = LIS[j];
            }
         } 
     }
     LIS[i].emplace_back(A[i]);
     size_t temp = LIS[i].size();
     if(maxLength < temp)
     {
       maxLength = temp;
       maxRow  = i;
     }
  }

  return LIS[maxRow];
}

// Approach #4 : Most optimal DP solution, with Binary Search
// Time Complexity : O(nlogn)
int longestIncreasingSubSequenceOptimized(const vector<int> &input)
{
  return 1;
}

int main()
{
  vector<int> A = {10,22,9,33,21,50,41,60,80};
  int lisRecursiveLength = LISRecursive(A,-1,0);
  cout << "lisRecursiveLength, " << lisRecursiveLength << endl;

  int lisMemoizedLength = LISRecursiveMemoized(A);
  cout << "lisMemoizedLength, " << lisMemoizedLength << endl;

  vector<int> LIS = longestIncreasingSubSequenceWithString(A);
  cout << "test LIS" << endl;
  for(auto s : LIS)
  {  
    cout << s << ",";
  }
  cout << endl;

  int lengthLCS = longestIncreasingSubSequence(A);
  cout << "lengthLCS," << lengthLCS << endl;
}

