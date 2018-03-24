#include<iostream>

using namespace std;


void setKthBit(int &a, int k)
{
  a = a | (1 << k);
}

int main()
{
 int a=10,b=15;
 setKthBit(a,2);
 cout << a << endl;
 setKthBit(b,3);
 cout << b << endl;
}
