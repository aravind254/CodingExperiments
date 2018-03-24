#include<iostream>

using namespace std;

int rightMostDiffBit(int a, int b)
{
  int mask = 1;
  int pos = 1;
  while(a || b)
  {
    if((a & mask)^(b & mask))
    {
      break; 
    }
    pos++;
    a = a>>1;
    b = b>>1;
  }
  return pos;
}

int main()
{
   cout << rightMostDiffBit(11,9) << endl;
   cout << rightMostDiffBit(52,4) << endl;
}
