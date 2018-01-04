#include<iostream>
#include<string>

using namespace std;

string snakeString(const string &s)
{
 size_t sSize = s.size();
 string r;
 
 for(int i = 1;i<sSize;i+=4) 
 {
   r += s[i];
 }
 for(int i = 0;i<sSize;i+=2) 
 {
   r += s[i];
 }
 for(int i = 3;i<sSize;i+=4) 
 {
   r += s[i];
 }
 return r;
}

int main()
{
  cout << snakeString("Hello World") << endl;
}
