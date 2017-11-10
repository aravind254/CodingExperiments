#include<iostream>
using namespace std;

typedef unsigned char uint8_t;


// O(n) is time complexity.
// O(1) is space complexity.
uint8_t ReverseBits(uint8_t a)
{
 uint8_t r=0,c=0;
 uint8_t size = sizeof(uint8_t);
 for(uint8_t i = 0;i<sizeof(uint8_t)*8;i++)
 {
   if(a&(1<<i))
   {
       r |= (1<<(size*8-1-c));
   }
   c++;
 }
 return r;   
}


// Caching technique can be used to reduce the time complexity to O(n/L) as shown in EPI.
// L is the segment size used to compute the cache.


int main()
{
  uint8_t result = ReverseBits(7);
  cout << "result = " << unsigned(result) << endl;
}
