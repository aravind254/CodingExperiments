#include<iostream>
#include<vector>
#include<string>

#define UNDEFVAL -1

using namespace std;
// 1) Recursion without Memoization
// TimeComplexity:Exponential

int lis(vector<int> &A)
{


}



int longestCommonSubsequence(string &A,string &B, int n, int m)
{
   int result = 0;
   if((n==0) || (m == 0))
   {
      return 0;
   }
    
   if(A[n-1] == B[m-1])
   {
     result = 1 + longestCommonSubsequence(A,B,n-1,m-1);
   }
   else
   {
     result = max(longestCommonSubsequence(A,B,n-1,m),
                 longestCommonSubsequence(A,B,n,m-1)); 
   }

   return result;
}
 

// 2) Recursion with Memoization
// TimeComplexity : O(nm) 

string memString;
int longestCommonSubsequenceMemoized(string &A,string &B, int n, int m, vector<vector<int>> &LCS)
{
   // Look up in the cache and if present return
   if(LCS[n][m] != UNDEFVAL) 
   {
      cout << "Use Cache for " << n << "," << m << endl;
      return LCS[n][m];
   }

   int result = 0;

   if((n==0) || (m == 0))
   {
      return 0;
   }
   
   if(A[n-1] == B[m-1])
   { 
     result = 1 + longestCommonSubsequenceMemoized(A,B,n-1,m-1,LCS);
     //memString += A[n-1]; // doesn't work
   }
   else
   {
     result = max(longestCommonSubsequenceMemoized(A,B,n-1,m,LCS),
                 longestCommonSubsequenceMemoized(A,B,n,m-1,LCS));  
   }

   cout << "Populate Cache for " << n << "," << m << endl;
   LCS[n][m]  = result;

   return result;
}


// 3) Bottom Up Approach
// TimeComplexity : O(nm)
int longestCommonSubsequenceBottomUp(string &A,string &B)
{
 int rSize = A.size()+1;
 int cSize = B.size()+1;
 vector<vector<int>> R(rSize,vector<int>(cSize,0)); 
 string bUpString;
 
 for(int i = 0;i<rSize;i++)
 {
   for(int j = 0;j<cSize;j++)
   {
      if((i==0) || (j==0))
      {
        R[i][j] = 0;
      }
      else if (A[i-1] == B[j-1])
      {
         R[i][j] = R[i-1][j-1] + 1;
      }
      else
      {
         R[i][j] = max(R[i-1][j],R[i][j-1]);
      } 
   }
 }
 
 // Find the LCS 
 int i = rSize-1,j=cSize-1;
 while(i>0 && j>0)
 {
   if(A[i-1] == B[j-1])
   {
     bUpString += A[i-1];
     i = i-1;
     j = j-1;
   }
   else
   {
        if(R[i-1][j] > R[i][j-1])
        {
          i = i-1;
        }
        else
        {
          j = j-1;
        }
   }
 }
 reverse(bUpString.begin(),bUpString.end());
 cout << "LCS is " << bUpString << endl;
  
 return R[rSize-1][cSize-1];
}


int main()
{
  string A = "abcdaf";
  string B = "acbcf";
  cout << "result," << longestCommonSubsequence(A,B,A.size(),B.size()) << endl;
  vector<vector<int>> LCS(A.size()+1,vector<int>(B.size()+1,UNDEFVAL));
  int memResult =  longestCommonSubsequenceMemoized(A,B,A.size(),B.size(),LCS);
  cout << "Memoized Result, " << memResult << endl;
  cout << "Mem String " << memString << endl;
  int bUpResult = longestCommonSubsequenceBottomUp(A,B);
  cout << "bUpResult, " << bUpResult << endl;
}

