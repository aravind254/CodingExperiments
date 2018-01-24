#include<iostream>
#include <sstream>
#include<stack>
#include<string>

using namespace std;

int evaluateRpn(const string input)
{
   string token;
   stringstream ss(input);
   stack<int> myStack;
   char delim = ',';
   while(getline(ss,token,delim))
   {
     cout << "token = " << token << endl;
     // Check if there is a operator
     if(token == "+" || token == "-" || token == "*" || token == "/")
     {
          int val1 = 0;
	  int val2 = 0;
	  if(token == "+")
	  {
		val1 = myStack.top();myStack.pop(); // skipping empty checks, assuming there will be 2 elements in the stack( i.e RPN exprssions are valid)
		val1 += myStack.top();myStack.pop();
	  }
	  else if(token == "*")
	  {
		val1 = myStack.top();myStack.pop(); 
		val1 *= myStack.top();myStack.pop();
	  }
	  else if(token == "/")
	  {
		val1 = myStack.top();myStack.pop();
		val2 = myStack.top();myStack.pop();
		val1 = val2/val1;
	  }   
	  else if(token == "-")
	  {
		val1 = myStack.top();myStack.pop();
		val2 = myStack.top();myStack.pop();
		val1 = val2-val1;
          }
          cout << "Push val1 = " << val1 << endl; 
          myStack.push(val1);
     }
     else
     {
	 int temp = stoi(token);
         cout << "Push temp = " << temp << endl;
         myStack.push(temp);
     }	
   }
   return myStack.top();
}


int main()
{
  string expr = "3,4,+,2,*,1,+";
  int result = evaluateRpn(expr);
  cout << "result = " << result << endl;
}
