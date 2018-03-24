#include<iostream>

using namespace std;


// Assuming leftmost bit is bit 1
int toggleBitsInGivenRange(int a, int l, int r)
{
  int mask1 = (1 << (r)) - 1;
  int mask2 = (1 << (l-1)) - 1;
  int mask = mask1 ^ mask2;
  a = a ^ mask;
  return a; 
}


int main()
{
  cout << toggleBitsInGivenRange(17,2,3) << endl; 
  cout << toggleBitsInGivenRange(50,2,5) << endl; 
}
