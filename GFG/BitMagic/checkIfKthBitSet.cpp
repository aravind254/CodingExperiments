#include<iostream>

using namespace std;

bool checkIfKthBitSet(int a,int k)
{
  int mask = 1 << k;
  return ((a & mask) > 0); 
}

int main()
{
  cout << checkIfKthBitSet(4,0) << endl;
  cout << checkIfKthBitSet(4,2) << endl;
  cout << checkIfKthBitSet(500,3) << endl;
}
