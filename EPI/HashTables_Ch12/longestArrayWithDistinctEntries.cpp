#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


int lengthOfLongestSubArray(const string &input)
{
  unordered_map<char,int> myMap;
  int result = 0,i=0,tlength=0,start=0,iTemp = 0;
  while(i<input.size())
  {
     cout << "i," << i << endl;
     cout << "find " << input[i] << endl;
     auto temp = myMap.find(input[i]);
     if((temp != myMap.end()) && (temp->second >= start))
     {
       tlength = i - start;
       cout << "tlength," << tlength << endl;
       result = (result < tlength)? tlength : result;
       start = temp->second + 1; 
       myMap[input[i]] = i;
       cout << "Update start to " << start << endl;
     }
     myMap[input[i]] = i;
     i++;
  }
  return result;
}


int main()
{
 string s = "fsfetwenwe";
 int result = lengthOfLongestSubArray(s);
 cout << "result," << result << endl;
 return 0;
}
