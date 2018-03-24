#include<iostream>
using namespace std;


//Time Complexity : O(NO OF BITS)
void reverseBits(unsigned int a)
{
  int n = sizeof(int) * 8;
  unsigned int result = 0;
  for(int i = 0;i<n;i++)
  {
       if(a&(1<<i))
       {
          result |= 1<<((n-1)-i);
       }
  }
  cout << "result, " << result << endl; 
}

int main()
{
   reverseBits(1);

}
