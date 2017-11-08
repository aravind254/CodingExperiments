#include<iostream>
#include<sstream>
#include<cmath>

using namespace std;
/*
01010000 becomes
01011111 after forwarding rightmost set bit
*/

void forwarding(unsigned int a)
{
 unsigned int b = a | (a-1);
 cout << "b = " << b << endl;
}

// Last n bits will be the reminder when doing the modulo operation with 2^n
unsigned int ModuleWithPowerOfTwo(unsigned int a,int n)
{
  return (a & (int)(std::pow(2.0,n) - 1));
}

bool isPowerOf2(unsigned int a)
{
 return !(a & (a-1));
}

int main(int argc,char *argv[])
{
 cout << "argc " << argc << endl;
 if(argc < 2)
 {
 	return -1;
 }
 istringstream ss(argv[1]);
 unsigned int a;
 if(ss >> a)
 {
    forwarding(a);
    cout << "Reminder = " << ModuleWithPowerOfTwo(a,2) << endl; 
    cout << "isPowerOf2 = " << isPowerOf2(a) << endl;
 }
 else
 {
  cout << "Invalid integer" << endl;
 }
 cout << "eof " << ss.eof() << endl;
 cout << "fail " << ss.fail() << endl;
	
}
