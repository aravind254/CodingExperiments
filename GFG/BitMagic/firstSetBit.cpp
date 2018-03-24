//https://practice.geeksforgeeks.org/problems/find-first-set-bit/0
#include<iostream>

using namespace std;

int findFirstSetBit(int a)
{
   int mask = 1;
   int pos = 1;
   while(a)
   {
     if(a & mask){
     break;
     }

     a = a>>1;
     pos++;
   }
   
 return pos; 
}

int main()
{
  int a = 18, b = 12,c= 8;
  cout << findFirstSetBit(a) << endl;
  cout << findFirstSetBit(b) << endl;
  cout << findFirstSetBit(c) << endl;
}
