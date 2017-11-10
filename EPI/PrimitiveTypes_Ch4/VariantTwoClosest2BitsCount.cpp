#include<iostream>
using namespace std;

using ulong = unsigned long;

// Time Complexity :  O(n) where n is the number of bits in input
// Space Complexity : O(1)

ulong Closest2BitCount(ulong a)
{
  ulong r=0;
  if((a == 0) || (a == ~0))
  {
	cout << "Unexpected input all 0s or 1s" << endl;
	return 0;
  }
  
  int size = sizeof(ulong);
  for(int i = 0;i<size-1;i++)
  {
	if((a&(1UL<<i)) != (a&(1UL<<(i+1))))
	{
		cout << "i = " << i << endl;
		a ^= ((1UL<<i) | (1UL<<(i+1)));
		break;
	}
  }
  return a;
}

// Time Complexity :  O(1) 
// Space Complexity : O(1)

ulong Closest2BitCountImproved(ulong a)
{
  ulong result1 = a & (a-1);
  ulong result2 = ((a & ~(a-1)) >> 1);
  a = result1 | result2;
  return a;
}

int main()
{
 ulong result = Closest2BitCount(92);
 cout << "result = " << result << endl; 
 result = Closest2BitCountImproved(92); 
 cout << "result Improved = " << result << endl; 
}
