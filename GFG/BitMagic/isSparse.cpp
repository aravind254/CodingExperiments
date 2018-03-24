#include<iostream>
//https://www.geeksforgeeks.org/check-if-a-given-number-is-sparse-or-not/

using namespace std;

bool isSparse(int a)
{
  bool result = true;
  int conscount = 0;
  while(a)
  { 
    if(a & 1)
    {
      conscount++; 
      if(conscount > 1){
      result = false;
      break;
      }
    }
    else
    {
      conscount = 0; 
    }
   a = a>>1;      
  }  
  return result;
}


// Optimal solution
// Return true if n is sparse, else false
bool checkSparse(int n)
{
    // n is not sparse if there is set
    // in AND of n and n/2
    if (n & (n>>1))
        return false;
 
    return true;
}

int main()
{
  cout << isSparse(72) << endl;
  cout << isSparse(12) << endl;
  cout << isSparse(2) << endl;
  cout << isSparse(3) << endl;
}



