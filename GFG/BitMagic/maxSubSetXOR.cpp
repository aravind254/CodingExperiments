#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Brute Force approach of generating all the subsets
// TimeComplexity : O(2^n)
int maxSubSetXORValueBF(vector<int> A)
{
  int n = A.size();
  int result = 0;
  int cur = 0;
  for(int i = 1;i<(1<<n);i++) // loop to track the number of combinations
  {
     // Pick elements to XOR based on combination
     int indexCount = 0;
     int mask = 1; 
     cur = 0;
     while(indexCount < n)
     {
        if(i & mask)
        {
           cur ^= A[indexCount];
        }
        mask = mask<<1;
     	indexCount++; 
     }
     result = max(cur,result);
  }
  return result;
}

// TimeComplexity : O(n)
int maxSubSetXORValue(vector<int> A)
{
  int maxBits = sizeof(int) * 8;
  int index = 0;
  int n = A.size();
  int result = 0;

  for(int i = (maxBits-1);i>=0;i--)
  {
     int maxElem = -1;
     int maxIndex = 0;
     // Find the max element with ith bit set
     for(int j = index; j < n;j++)
     {
          if(A[j] & (1<<i))
          {
              if(A[j] > maxElem)
              {
                 maxElem = A[j];
                 maxIndex = j;
              } 
          }
     }

     // No Element had ith Bit set. 
     if(maxElem == -1)
     {
        continue;
     }

     swap(A[index],A[maxIndex]);
   
     // Remove the ith Bit from rest of the elements which have the ith Bit set in A
     for(int k = 0; k<n;k++)
     {
          if((k != index) && (A[k] & (1<<i)))
          {
             A[k] = A[k] ^ A[index];
          }
     }
     index++;
  }
  for(int i = 0;i<n;i++)
  {
    result = result^A[i];
  }  

  return result;
}

int main()
{
  vector<int> i1 = {2, 4, 5};
  vector<int> i2 = {9, 8, 5};
  vector<int> i3 = {8, 1, 2, 12, 7, 6};
  vector<int> i4 = {4, 6};
  cout << maxSubSetXORValueBF(i1) << endl;
  cout << maxSubSetXORValueBF(i2) << endl;
  cout << maxSubSetXORValueBF(i3) << endl;
  cout << maxSubSetXORValueBF(i4) << endl;
  cout << maxSubSetXORValue(i1) << endl;
  cout << maxSubSetXORValue(i2) << endl;
  cout << maxSubSetXORValue(i3) << endl;
  cout << maxSubSetXORValue(i4) << endl;
}
