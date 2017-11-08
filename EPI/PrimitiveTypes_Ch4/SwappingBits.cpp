#include<iostream>
using namespace std;

using uint = unsigned int;

uint SwapBits(uint a,uint i,uint j)
{
 uint mask1 = 1<<i;
 uint mask2 = 1<<j;

 if((a & mask1) == (a & mask2))
 {
    return a;
 }

 uint mask3 = 1<<i | 1<<j;
 return (a ^= mask3); 
}

int main()
{
uint a = SwapBits(8,1,3);  
cout << "a = " << a << endl;
}
