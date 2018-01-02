#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
// Initialization
string test1("Hello World"); 
string test2 = "Hello World";

// Copy
string test3(test1);
string test4; test4 = test2;

// SubString
string test5 = test1.substr(6,5);

// Compare strings,using class Method
int result =  test1.compare(test2);

cout << "test1 = " << test1 << endl;
cout << "test2 = " << test2 << endl;
cout << "result comparing test1,test2 = " << result << endl;
cout << "test3 = " << test3 << endl;
cout << "test4 = " << test4 << endl;
cout << "test5 = " << test5 << endl;


// Operators to compare strings
if(test1 < test2) { cout << "test1 < test2" << endl;}
else if(test1 == test2){cout << "test1 == test2" << endl;}
else {cout << "test1 > test2" << endl;}
// Append to a string
test1.append(". How are you?");
cout << "test1 after append = " << test1 << endl;

// Push and Pop
test3.push_back('A');
cout << "test3 after push = " << test3 << endl;

test3.pop_back(); // Doesn't return the character
cout << "test3 after pop = " << test3 << endl;

// Insert into a string
test2.insert(6,"Welcome ");
cout << "test2 after insert = " << test2 << endl;


// Reverse a string
reverse(test3.begin(),test3.end());
cout << "test3 after reverse = " << test3 << endl;

// isalnum,isupper,islower,isalpha,isdigit
// tolower, toupper



}
