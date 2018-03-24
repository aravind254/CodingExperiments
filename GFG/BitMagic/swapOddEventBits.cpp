#include<iostream>
using namespace std;

void swapOddEvenBits(int a)
{
  int oddMask =  0x55555555;
  int evenMask = 0xAAAAAAAA;
  int odd = a & oddMask;
  int even = a & evenMask;
  int result = (odd<<1) | (even>>1);
  cout << result << endl;
}

int main()
{
  swapOddEvenBits(23);
}
