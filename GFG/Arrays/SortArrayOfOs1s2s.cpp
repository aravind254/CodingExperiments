//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0#ExpectOP
#include<iostream>
#include<vector>

using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(1), ignoring the returned result array
vector<int> sortArrayOfOs1s2s(const vector<int> &input)
{
  vector<int> myBuf(3,0);
  vector<int> result;
  result.reserve(input.size());
  for(int i = 0; i<input.size();i++)
  {
     myBuf[input[i]]++;
  }

  for(int i = 0;i<myBuf.size();i++)
  { 
     int count = myBuf[i];
     while(count > 0)
     {
       result.emplace_back(i);
       count--;
     } 
  }
  return result;
}

int main()
{
  vector<int> input = {0,2,1,2,0};
  vector<int> result = sortArrayOfOs1s2s(input);
  cout << "size, " << result.size() << endl;
  for(int i = 0; i<result.size();i++){
  cout << result[i] << ",";
  }
  cout << endl;
}
