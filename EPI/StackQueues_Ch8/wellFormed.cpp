#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>

using namespace std;


bool isWellFormed(const string &input)
{
  unordered_map<char,char> match = {{'(',')'},{'{','}'},{'[',']'}};
  int iSize = input.size();
  stack<char> myStack;
  int i = 0;
  while(i < iSize)
  {
	if(match.count(input[i]))
        {
		cout << "push " << input[i] << endl;
		myStack.emplace(input[i]);
        }
	else
	{
		if(match.at(myStack.top()) != input[i])
		{
		  cout << "Mismatch " << input[i] << endl;
  		  return false;
		}
                cout << "match " << input[i] << endl;
		myStack.pop();
	}
    i++;
  }

  return myStack.empty();

}


int main()
{
   string val = "[((())])";
   cout << isWellFormed(val) << endl;
}
