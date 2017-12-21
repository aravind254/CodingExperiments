#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int strToInteger(string A)
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

for(int i = aSize-1;i>=0;i--)
{
  if((sign < 0) && (i == 0))
  {
     continue;
  }
 
  curVal = A[i] - '0';
  if((curVal >=0) && (curVal <=9))
  {
	result = result + curVal * pow(10,curIndex); // or Multiply result by 10 everytime before adding curVal
	curIndex++;
  }
  else
  {
	cout << "Error Unexpected character " << A[i] << endl;
	return -1; // assuming -1 is not valid input
  }
} 
return (result * sign);
}

int main()
{
int a  = strToInteger("123");
cout << "a = " << a << endl;
a = strToInteger("-123");
cout << "a = " << a << endl;
a = strToInteger("ABC");
cout << "a = " << a << endl;
}
