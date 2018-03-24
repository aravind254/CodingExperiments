#include<iostream>
using namespace std;

int countNumberOfBitsTobeFlipped(int a, int b)
{
  int temp = a ^ b;
  int count = 0;

  while(temp)
  {
    if(temp & 1)
    {
      count++;
    }
    temp  = temp >> 1;
  }
  
  return count;
}

int main()
{
  cout << countNumberOfBitsTobeFlipped(10,20) << endl;
}
