#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string intToString(int A)
{
 string result;
 int quo,rem;
 char curChar;
 char signChar='+';

 if(A < 0)
 signChar = '-';

 while(A)
 {
  rem = abs(A%10); 
  curChar = rem + '0';
  result.push_back(curChar);
  A = ceil(A/10); 
 }

 if(signChar == '-')
 {
  result.push_back(signChar);
 }
  
 reverse(result.begin(),result.end());
   

 return result;
}

int main()
{
 string a = intToString(123);
 cout << "a = " << a << endl;
 a = intToString(-123);
 cout << "a = " << a << endl;
}
