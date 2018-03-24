#include<iostream>
//https://www.geeksforgeeks.org/rotate-bits-of-an-integer/

using namespace std;

int rightMostSetBit(int a)
{
  int count = 0;
  int rightMostSetBitPos = -1;
  
  while(a)
  {
    if(a & 1)
    {
      rightMostSetBitPos = count;
    }
    a  = a>>1; 
    count++;
  }
  cout << "a, " << a << ",rightMostSetBitPos, " << rightMostSetBitPos << endl;
  return rightMostSetBitPos;
}


void rotateBits(int a, int k)
{
 cout << "a, " << a << ",k, " << k << endl;

 // leftRotate
 {
 cout << "leftRotate" << endl;
 int temp = a;
 int leftPos = rightMostSetBit(temp);
 int pos = leftPos - (k-1);
 temp = temp >> pos; 
 int temp1 = (((1 << pos)-1) & a) << k;
 int leftResult = temp | temp1; 
 cout << "leftResult, " << leftResult << endl; 
 }

 // rightRotate
 {
 int temp = a;
 int leftPos = rightMostSetBit(temp);
 int pos = leftPos - (k-1);
 temp = temp >> k;
 int temp1 = (((1<<(k)) - 1) & a) << pos;
 int rightResult = temp | temp1;
 cout << "rightResult, " << rightResult << endl;  
 } 
}

/*Function to left rotate n by d bits*/
int leftRotate(int n, unsigned int d)
{
   int iSize = sizeof(int) * 8;
   cout << iSize << endl;
   /* In n<<d, last d bits are 0. To put first 3 bits of n at 
     last, do bitwise or of n<<d with n >>(INT_BITS - d) */
   return (n << d)|(n >> (iSize - d));
}
 
/*Function to right rotate n by d bits*/
int rightRotate(int n, unsigned int d)
{
   int iSize = sizeof(int) * 8;
   /* In n>>d, first d bits are 0. To put last 3 bits of at 
     first, do bitwise or of n>>d with n <<(INT_BITS - d) */
   return (n >> d)|(n << (iSize - d));
}

int main()
{
  rotateBits(229,3);
  rotateBits(28,2);
  cout << "leftRotate " << leftRotate(229,3) << endl;
  cout << "rightRotate " << rightRotate(229,3) << endl;
}
