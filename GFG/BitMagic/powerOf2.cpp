#include<iostream>

using namespace std;

bool isPowerOf2(int a)
{
  return !(a & (a-1));
}

int main()
{ 
 cout << isPowerOf2(16) << endl;
 cout << isPowerOf2(128) << endl;
 cout << isPowerOf2(10) << endl;
}
