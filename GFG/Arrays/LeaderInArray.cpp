// https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
#include<iostream>
#include<vector>

using namespace std;

vector<int> LeaderInArray(const std::vector<int> &input)
{
 size_t iSize = input.size();
 int curMax = input[iSize-1];
 vector<int> result;
 result.emplace_back(curMax);
 
 for(int i = iSize-2;i>=0;i--)
 { 
    if(input[i] > curMax)
    {
       curMax = input[i];
       result.emplace_back(curMax);
    }
 }

 return result;
  
}

int main()
{
  //vector<int> input = {16,17,4,3,5,2};
  vector<int> input = {1,2,3,4,0};
  vector<int> result = LeaderInArray(input);
  for(int i : result)
  {
    cout << i << ",";
  }
  cout << endl;

}

