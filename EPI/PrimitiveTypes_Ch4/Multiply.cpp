#include<iostream>

using namespace std;
using uint = unsigned int;



uint Add(uint B, uint R)
{
 uint tempB = B;
 uint tempR = R;
 uint pC = 0;
 uint cC = 0;
 uint mask = 1;
 uint sum = 0;
 uint pB = 0;
 uint pR = 0;
 
 while((tempB > 0) || (tempR > 0))
 {
   cC = pC;
   pB = B & mask;
   pR = R & mask;
   sum |= pB ^ pR ^ cC;
   cC  = (pB & pR) | (pB & pC) | (pR & pC);
   tempB = tempB >> 1;
   tempR = tempR >>  1;
   mask = mask << 1;
   cout << "sum = " << sum  << endl;
   cout << "cC = " << cC  << endl;
 }
 return sum;
}

uint Multiply(uint A, uint B)
{
 uint R = 0;
 
 while(A)
 {
  if(A&1)
  {
	  R |= Add(B,R);
          cout << "B = " << B << endl;
          cout << "R = " << R << endl;
  }

  A = A >> 1;
  B = B << 1;
 }
 return R;
}

int main()
{
 uint Result = Multiply(5,5);
  
 cout << "Result = " <<  Result << endl;
}
