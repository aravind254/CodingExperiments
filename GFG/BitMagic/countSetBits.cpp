#include<iostream>

using namespace std;


int countSetBits(int a)
{
  int count = 0;
  while(a)
  {
   if(a & 1){
   count++;
   }
   a = a>>1;
  }
  return count;
}


int sumOfSetBits(int n)
{
  int result = 0;
  for(int i = 1;i<=n;i++)
  {
    result += countSetBits(i);
  }
 return result;
}

int main()
{
 cout << sumOfSetBits(4) << endl;
 cout << sumOfSetBits(6) << endl;
}
