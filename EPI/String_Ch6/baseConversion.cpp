#include<iostream>
#include<string>
#include<cmath>

using namespace std;


int getIntValue(char a)
{
 int curVal;
 curVal = a - '0';
 if((curVal >= 0) && (curVal <=9))
 {
   cout << "curVal " << curVal << endl;
   return curVal; 
 }
 
 switch(a)
 {
   case 'A':
   case 'a':
    return 10;
   case 'B':
   case 'b':
    return 11;
   case 'C':
   case 'c':
    return 12;
   case 'D':
   case 'd':
    return 13;
   case 'E':
   case 'e':
    return 14;
   case 'F':
   case 'f':
    return 15;
 }
return -1;
}

int strToInteger(string A,unsigned int b)
{
char signChar;int sign=0;size_t aSize = A.size();int result = 0,curVal = 0,curIndex = 0;
signChar = A[0];
if(signChar == '-')
{
 sign = -1;
}
else
{
 sign = 1;
}

for(int i = 0;i<aSize;i++)
{
  if((sign < 0) && (i == 0))
  {
     continue;
  }
  result = result*b + getIntValue(A[i]); 
}
return (result * sign);
}

char getCharValue(int rem)
{
 if(rem > 9)
 {
  switch(rem)
 { 
   case 10:
    return 'A';
   case 11:
    return 'B';
   case 12:
    return 'C';
   case 13:
    return 'D';
   case 14:
    return 'E';
   case 15:
    cout << "F " << endl; 
    return 'F';
 }
 }
 return (rem + '0'); 
}

string intToString(int A,unsigned int b)
{
 string result;
 int quo,rem;
 char curChar;
 char signChar='+';

 if(A < 0)
 signChar = '-';

 while(A)
 {
  rem = abs((int)(A%b));
  curChar = getCharValue(rem);
  result.push_back(curChar);
  A = ceil(A/b);
 }

 if(signChar == '-')
 {
  result.push_back(signChar);
 }

 reverse(result.begin(),result.end());
 return result;
}

string baseConversion(const string &A,unsigned int b1,unsigned int b2)
{
 int intResult = strToInteger(A,b1);
 cout << "intResult = " << intResult << endl;
 string result = intToString(intResult,b2);
 return result; 
}

int main()
{
  string input = "16";
  string result =  baseConversion(input,8,10);
  cout << "input = " << input << " converted to " << result << endl;
  input = "FFFF";
  result =  baseConversion(input,16,10);
  cout << "input = " << input << " converted to " << result << endl;
  return 0;
}
