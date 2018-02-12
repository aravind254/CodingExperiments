#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

bool isLetterConstructible(const string &letter, const string &magazine)
{
  unordered_map<char,int> charMap;
  for(char c : letter)
  {
     charMap[c]++;
  }
 
  for(char c : magazine)
  {
     if(charMap.find(c) != charMap.end())
     {
         if(charMap[c] > 0)
         { 
            charMap[c]--;
            if(charMap[c] == 0)
            {
                charMap.erase(c);
            }
	 }
     }
  }

  return charMap.empty();
}

int main()
{
  string letter = "aaabbbccc";
  string mag = "aaabbbccceeee";
  bool result = isLetterConstructible(letter,mag); 
  cout << "result," << result << endl;
}
