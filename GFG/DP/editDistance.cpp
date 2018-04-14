#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Utility function

int FindMin(int a,int b,int c)
{
   return min(a,min(b,c));
}

// Approach #1     : Recursive solution
// TimeComplexity  : Exponential


int editDistanceHelper(string str1,string str2, int n,int m);
int editDistance(string str1,string str2)
{
   return editDistanceHelper(str1,str2,str1.size(),str2.size());
}

int editDistanceHelper(string str1,string str2, int n,int m)
{
  // if string1 is empty then we need to add all elements from str2
  if(n == 0)
  {
    return m;
  }
 
  // if string2 is empty then we need to delete all elements from str1 
  if(m == 0)
  {
    return n;
  }

  if(str1[n-1] == str2[m-1])
  {   
    return editDistanceHelper(str1,str2,n-1,m-1);
  }
  
  int minDistance = 1 + FindMin(editDistanceHelper(str1,str2,n,m-1), // Insert element 
                            editDistanceHelper(str1,str2,n-1,m), // Delete element
                            editDistanceHelper(str1,str2,n-1,m-1)); // Replace element

  return minDistance;
}

// Approach #2 : Recursive Memoized solution
// TimeComplexity : O(n*m)
#define INVALID -1
int editDistanceMemoizedHelper(string str1,string str2, int n,int m,vector<vector<int>> &cache);
int editDistanceMemoized(string str1,string str2)
{
   vector<vector<int>> cache(str1.size()+1,vector<int>(str2.size()+1,INVALID));
   return editDistanceMemoizedHelper(str1,str2,str1.size(),str2.size(),cache);
}

int editDistanceMemoizedHelper(string str1,string str2, int n,int m,vector<vector<int>> &cache)
{ 
  // if string1 is empty then we need to add all elements from str2
  if(n == 0)
  { 
    return m;
  }
  
  // if string2 is empty then we need to delete all elements from str1
  if(m == 0)
  { 
    return n;
  }

  if(cache[n][m] != INVALID)
  {
     cout << "Use Cache n," << n << ",m," << m << endl;
     return cache[n][m];
  }

  cout << "Work for n," << n << ",m," << m << endl; 
  
  if(str1[n-1] == str2[m-1])
  {   
    return editDistanceMemoizedHelper(str1,str2,n-1,m-1,cache);
  }
  
  int minDistance = 1 + FindMin(editDistanceMemoizedHelper(str1,str2,n,m-1,cache), // Insert element
                            editDistanceMemoizedHelper(str1,str2,n-1,m,cache), // Delete element
                            editDistanceMemoizedHelper(str1,str2,n-1,m-1,cache)); // Replace element

  cache[n][m] = minDistance;

  return minDistance;
}


// Utility
void findEdits(string str1, string str2, const vector<vector<int>> &R)
{  
 int n = R.size();
 int m = R[0].size();
 int i = n-1;
 int j = m-1;

 while((i > 0) && (j>0))
 {
   if(str1[j-1] == str2[i-1])
   {
     cout << str1[j-1] << " is equal to " << str2[i-1] << endl;
     i = i-1;
     j = j-1;
   }
   else
   {
        if(R[i][j] == (1 + R[i-1][j-1])) // str1[j-1] != str2[i-1], so replace str1[j-1] with str2[i-1]
	{
             cout << "Replace " << str1[j-1] << " with " << str2[i-1] << endl;
	     i = i-1;
	     j = j-1;
	}
	else if(R[i][j] == (1 + R[i-1][j])) // str1[j-1] != str2[i-1]. Need to add str2[i-1] to str1 after i-1
	{
	   cout << "Add " << str2[i-1] << " to str1 at " << i-1 << endl;
           i = i -1;
	}
	else if(R[i][j] == (1 + R[i][j-1])) // str1[j-1] != str2[i-1]. Need to delete str1[j-1]
	{
	   cout << "Delete " << str1[j-1] << endl;
           j = j-1;
	}
   } 
 }

}


// Approach #3 : Bottom Up approach
// TimeComplexity : O(n*m)
int editDistanceBup(string str1,string str2)
{
   int m = str1.size()+1;
   int n = str2.size()+1;
   vector<vector<int>> cache(n,vector<int>(m,0));

   for(int j = 0; j<m;j++)
   {
     cache[0][j] = j;
   }

   for(int i = 0;i<n;i++)
   {
     cache[i][0] = i;
   }

   for(int i = 1;i<n;i++)
   {
     for(int j = 1;j<m;j++)
     {
	   if(str1[j-1] == str2[i-1])
	   {
	      cache[i][j] = cache[i-1][j-1];
	   }
	   else
	   {
	      int minDistance = FindMin(cache[i-1][j],cache[i][j-1],cache[i-1][j-1]);
	      cache[i][j] = minDistance + 1;
	   }
     }
   }

   for(int i = 0; i<n;i++)
   {
     for(int j = 0 ; j < m ; j++)
     {
         cout << cache[i][j] << " ";
     }
     cout << endl;
   }

  findEdits(str1,str2,cache);

  return cache[n-1][m-1];
}

int main()
{
  //string str1 = "sunday";
  //string str2 = "saturday";
  string str1 = "azced";
  string str2 = "abcdef";
  int minD = editDistance(str1,str2);
  int minDMemoized = editDistanceMemoized(str1,str2);
  int minDBup = editDistanceBup(str1,str2);
  cout << "minD, " << minD << endl;
  cout << "minDMemoized, " << minDMemoized << endl;
  cout << "minDBup, " << minDBup << endl;
}
