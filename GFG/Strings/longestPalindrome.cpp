//https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
//https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

// Solution with O(n^2) time complexity and O(1) space complexity https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Time Complexuty Could be improved with DP to Time Complexity: O(n^2) and Space Complexity : O(n^2)
// Time Complexity : O(n^3)
// Space Complexity : O(1)
int longestPalindrome(string &input)
{
  size_t iSize = input.size();
  int s = 0,e = iSize-1;
  int result = 1;
  int curlength = 0;
  int count = 0;
 
  while(s<(iSize-1))
  {
     int i=s,j=iSize -1;
     e = iSize-1;
     cout << "s," << s << endl;
     while(i<j)
     {
        if(input[i] == input[j])
        {
             j--;
             i++;
        }
        else
        {
           e--;
           i = s;
           j = e;
        }
       count++;
     }
     if(s != e){
     int tSize = (e - s) + 1;
     string temp = input.substr(s,tSize);
     cout << "Found palindrome " << temp << "***" << "s," << s << ",e," << e << endl;
     result = (result < tSize) ? tSize: result;
     }
     s++;
  } 
  cout << "iSize," << iSize << ",count," << count << endl;
  return result;
}

// Could be improved with DP
// Time Complexity : O(n^3)
// Space Complexity : O(1)
int longestPalindrome2(string &input)
{
  size_t iSize = input.size();
  int s = 0,e = iSize-1;
  int result = 1; 
  int count = 0;
  for(int s = 0;s<iSize;s++)
  {
    for(int e = iSize-1;e>s;e--)
    {
        int i = s, j = e;
        while(i<j)
        {
           count++;
           if(input[i] == input[j])
           {
               i++;j--;
           }
           else {
           break;
           }
        }
        if(i >=j){
        int tSize = (e - s) + 1;
        string temp = input.substr(s,tSize);
        cout << "Found palindrome " << temp << "***" << "s," << s << ",e," << e << endl;
        result = (result < tSize) ? tSize: result; 
       }
    }
  }
  cout << "iSize," << iSize << ",count," << count << endl;
  return result;
}

int main()
{
  string input1 = "aaaabbaa"; 
  string input2 = "forgeeksskeegfor";
  int result = longestPalindrome2(input1);
  cout << "result," << result << endl;
  int result2 = longestPalindrome2(input2);
  cout << "result2," << result2 << endl;
}
