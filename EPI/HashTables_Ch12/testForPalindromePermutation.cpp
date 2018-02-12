#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;


// TimeComplexity : O(sizeof(input))
// SpaceComplexity : O(sizeof(input))
bool testForPalindrome(const string& input)
{
  unordered_map<char,int> charMap;
  for(char c:input)
  {
       charMap[c]++;
  }
  
  // If string is odd, then every character should be a multiple of 2, except one.
  // If string is even, then every character should be a multiple of 2.
  int inputOdd = input.size()%2;
  int oddCount = 0; 
  for(auto kv : charMap)
  {
     if((kv.second % 2) != 0) 
     {
        oddCount++;
     }
  }
  return inputOdd?(oddCount == 1):(oddCount == 0);
}


int main()
{
    string test = "abccbad";
    bool result =  testForPalindrome(test);
    cout << "result," << result << endl;
}
