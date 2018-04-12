#include<iostream>
#include<vector>

using namespace std;

// Approach #1 : Recursive solution.
// Try every possible combination.
// Time Complexity : O(2^n)
int knapSackRecuriveHelper(const vector<int> &value, const vector<int> &weight,int curWt, int curPos,int maxWeight);
int knapSackRecursive(const vector<int> &value,const vector<int> &weight,int maxWeight)
{
  return knapSackRecuriveHelper(value,weight,0,0,maxWeight);
}

int knapSackRecuriveHelper(const vector<int> &value, const vector<int> &weight,int curWt, int curPos,int maxWeight)
{
   cout << "curPos, " << curPos << ",curWt, " << curWt << endl;

   if((curPos == value.size()) || (curWt >= maxWeight))
   {
     return 0;
   }

   int selectedCurWeight = 0;
   int notSelectedCurWeight = 0;

   if((curWt + weight[curPos]) <= maxWeight)
   {
      selectedCurWeight = value[curPos] + knapSackRecuriveHelper(value,weight,curWt+weight[curPos],curPos+1,maxWeight); 
   } 
   notSelectedCurWeight = knapSackRecuriveHelper(value,weight,curWt,curPos+1,maxWeight);

   return max(selectedCurWeight,notSelectedCurWeight);
}

// #Approach #2 : Recusive Memoized Solution
// TimeComplexity : O(nm), m is maxWeight
// SpaceComplexity : O(nm), m is maxWeight
#define INVALID -1
int knapSackRecursiveMemoizedHelper(const vector<int> &value, const vector<int> &weight,int curWt, int curPos,int maxWeight,vector<vector<int>> &Cache);
int knapSackRecursiveMemoized(const vector<int> &value,const vector<int> &weight,int maxWeight)
{
  vector<vector<int>> cache(value.size(),vector<int>(maxWeight+1,INVALID));
  return knapSackRecursiveMemoizedHelper(value,weight,0,0,maxWeight,cache);
}

int knapSackRecursiveMemoizedHelper(const vector<int> &value, const vector<int> &weight,int curWt, int curPos,int maxWeight,vector<vector<int>> &cache)
{
   cout << "curPos, " << curPos << ",curWt, " << curWt << endl;

   if((curPos == value.size()) || (curWt >= maxWeight))
   {
     return 0;
   }

   if(cache[curPos][curWt] != INVALID)
   {
     cout << "Using cache for curPos," << curPos << ",curWt," << curWt << endl;
     return cache[curPos][curWt];
   }

   cout << "Work for curPos," << curPos << ",curWt," << curWt << endl;

   int selectedCurWeight = 0;
   int notSelectedCurWeight = 0;

   if((curWt + weight[curPos]) <= maxWeight)
   {
      selectedCurWeight = value[curPos] + knapSackRecursiveMemoizedHelper(value,weight,curWt+weight[curPos],curPos+1,maxWeight,cache);
   }
   notSelectedCurWeight = knapSackRecursiveMemoizedHelper(value,weight,curWt,curPos+1,maxWeight,cache);
   cache[curPos][curWt] = max(selectedCurWeight,notSelectedCurWeight);

   return cache[curPos][curWt];
}

// #Approach3 : BottomUp DP
// TimeComplexity : O(nm), m is max weight
// SpaceComplexity : O(nm), m is max weight
#define INVALID -1
int knapSackBupHelper(const vector<int> &value, const vector<int> &weight,int curWt, int curPos,int maxWeight,vector<vector<int>> &Cache);
int knapSackBup(const vector<int> &value,const vector<int> &weight,int maxWeight)
{ 
  vector<vector<int>> cache(value.size()+1,vector<int>(maxWeight+1,0));
  return knapSackBupHelper(value,weight,0,0,maxWeight,cache);
}

int knapSackBupHelper(const vector<int> &value, const vector<int> &weight,int curWt, int curPos,int maxWeight,vector<vector<int>> &cache)
{
  size_t n = cache.size();
  size_t m = cache[0].size();

  cout << "n, " << n << ",m," << m << endl;
  
  for(int i = 1;i<n;i++)
  {
    for(int  j = 1;j<m;j++) // j is current Max weight
    {
       if(weight[i-1] > j)
       {
          cache[i][j] = cache[i-1][j];
       }
       else
       {
          int curMaxWeight = j - weight[i-1];
          int selectingCurRow = value[i-1] + cache[i-1][curMaxWeight];
          int notSelectCurRow = cache[i-1][j];
          cache[i][j] = max(selectingCurRow,notSelectCurRow);
       }
    }
  }
 return cache[n-1][m-1];
}

int main()
{
   vector<int> value  = {60,100,120};
   vector<int> weight = {10,20,30};
   int maxWeight = 50;
   //vector<int> value  = {15,5,10,9};
   //vector<int> weight = {1,4,5,3};
   //int maxWeight = 8;
   int recursiveMaxValue = knapSackRecursive(value,weight,maxWeight); 
   cout << "recursiveMaxValue,"<< recursiveMaxValue << endl;
   int recursiveMemoizedMaxValue = knapSackRecursiveMemoized(value,weight,maxWeight);
   cout << "recursiveMemoizedMaxValue,"<< recursiveMemoizedMaxValue << endl;
   int bupValue =  knapSackBup(value,weight,maxWeight);
   cout << "bupValue, " << bupValue << endl;

}
