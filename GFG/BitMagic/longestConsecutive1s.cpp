#include<iostream>

using namespace std;

//https://www.geeksforgeeks.org/length-longest-consecutive-1s-binary-representation/

// Optimized Solution
int maxConsecutiveOnes(int x)
{
    // Initialize result
    int count = 0;
 
    // Count the number of iterations to
    // reach x = 0.
    while (x!=0)
    {
        // This operation reduces length
        // of every sequence of 1s by one.
        x = (x & (x << 1));
 
        count++;
    }
 
    return count;
}

int longestConsecutiveOnes(int a)
{
  int result = 0;
  int count  = 0;

  while(a)
  {
     if(a & 1) 
     {
       count++;
       result = result < count? count:result;
     }
     else{
       count = 0;
     }
     a = a>>1;
  } 
  return result;
}

int main()
{
 cout << longestConsecutiveOnes(14) << endl;
 cout << longestConsecutiveOnes(222) << endl;
}
