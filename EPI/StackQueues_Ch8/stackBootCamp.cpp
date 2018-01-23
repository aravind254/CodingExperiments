#include<iostream>
#include<stack>
using namespace std;

#include "Stack.cpp"

int main()
{

  // Use C++ stack
  stack<int> myStack;
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  

  while(!myStack.empty())
  {
	cout << myStack.top() << endl;
        myStack.pop();
  }

  // Use Custom Stack with Max
  cout << "Custom Stack" << endl;
  Stack customStack;
  customStack.push(5);
  customStack.push(6);
  customStack.push(2);
  customStack.push(1);
  
  while(!customStack.empty())
  {     
        cout <<  "data = " << customStack.top() << endl;
        cout <<  "max = " << customStack.max() << endl;
        customStack.pop();
  }
}
