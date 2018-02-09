#include<iostream>
#include<vector>
#include<array>
#include<bitset>

using namespace std;
typedef unsigned int uint;

uint FindMissingIpAddress(const vector<uint>::iterator &start,const vector<uint>::iterator end)
{
  const uint aSize = 1<<16;
  array<uint,aSize> upArray = {0};
  uint candidate = 0;
  vector<uint>::iterator cur = start;
  uint result = 0;
  
  while(cur != end)
  {
     upArray[(*cur >> 16)]++;
     cur++;
  }

  for(int i = 0;i<aSize;i++)
  {
     if(upArray[i] < aSize)
     {
        candidate  = i;
        cout << "candidate is " << candidate << endl;         
        break;
     }
  }
 
  cur = start;

  bitset<aSize> lowerArray;  
  while(cur != end)
  {
     if((*cur >> 16) == candidate)
     {
	   cout << "Found candidate, set lower Array with " << ((*cur) & 0x0000FFFF) << endl;
           lowerArray.set(((*cur) & 0x0000FFFF));
     }
     cur++;
  }

  for(int i =0; i<lowerArray.size();i++)
  {
      if(!lowerArray[i])
      {
          result = (candidate << 16) | i;
          break;
      }
  }

  return result;
}

int main()
{
   vector<uint> ipAddressArray = {
    0x00000000,0x00000001,0x00000002,
    0x00010001,0x00010002,0x00010003,
    0x00020001,0x00020002,0x00020003
   };
   uint ip = FindMissingIpAddress(ipAddressArray.begin(),ipAddressArray.end());
   cout << "Missing IP Address is " << ip << endl;
}
