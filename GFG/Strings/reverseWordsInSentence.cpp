//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0
//https://www.geeksforgeeks.org/reverse-words-in-a-given-string/ 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void reverseString(std::string &input, int s, int f)
{
  size_t iSize = input.size();

  if((s > iSize) || (f > iSize)) return;

  while(s<f)
  {
    swap(input[s],input[f]);
    s++;
    f--;
  }
}

// Time Complexity: O(n)
// Space Complexity : O(1)
void reverseWordsInString(std::string &input)
{
   size_t iSize = input.size();
   reverseString(input,0,iSize-1);
   int s = 0, e = 1;
   bool startValid = false;

   while(e < iSize)
   {
      if(input[s] != ' ')
      { 
        startValid = true;
      }
      else
      {
        startValid = false;
      }
      
      if(input[e] == ' ')
      {
         if(startValid){
         reverseString(input,s,e-1);
         }
         s= e+1;
      }
      e++;
   }

   if(e == iSize-1)
   {
      reverseString(input,s,e);
   } 
}

int main()
{
  string input = " I    love      programming very much  ";
  reverseWordsInString(input);
  cout << input << endl;
}
