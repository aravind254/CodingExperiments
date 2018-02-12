#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

struct repeatedEntry
{
 int minDistance = std::numeric_limits<int>::max();
 string key; 
};

repeatedEntry nearestRepeatedEntry(const vector<string> &input)
{
  repeatedEntry result;
  unordered_map<string,int> sMap;
  int tempDist = 0;
  string s;
  for(int i = 0;i<input.size();i++)
  {
     s = input[i];
     auto iter = sMap.find(s);
     if(iter != sMap.end())
     {
        tempDist = i - iter->second;
        if(tempDist < result.minDistance) 
        {
            result.minDistance = tempDist;
            result.key = s;
        }
     }
     sMap[s] = i;
  }
  return result; 
}

int main()
{
     vector<string>  input = {"All","work","and","no","play","makes","for","no","work","no","fun","and","no","results"};
     repeatedEntry result = nearestRepeatedEntry(input);
     cout << "minDistance," << result.minDistance << ",key," << result.key << endl;
}
