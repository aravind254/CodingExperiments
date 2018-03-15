// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

#include<iostream>
#include<vector>

using namespace std;

int maxContigousSubArraySum(std::vector<int> input)
{
  int curSum = input[0], result = input[0];
  size_t iSize = input.size();
  for(int i = 1;i<iSize;i++)
  {
     curSum = std::max(input[i],input[i] + curSum);
     result = std::max(curSum,result);
  }
  return result;
}


int maxContigousSubArraySum2(std::vector<int> input)
{
  int s = 0, e = 0, curSum = std::numeric_limits<int>::min(),newSum = 0,result = std::numeric_limits<int>::min();
  size_t iSize = input.size();

  while(e < iSize)
  {
     cout << "e," << e << ",result," << result << endl;
     if(s == e) { newSum = input[e];}
     else {
     newSum = curSum + input[e];
     }

     cout << "newSum," << newSum << ",curSum," << curSum << endl;
     if((newSum > curSum) || (newSum > 0))
     {
        curSum = newSum;
        result = curSum > result?curSum:result;
        e++;
     }
     else
     {
        s = e;
        curSum = std::numeric_limits<int>::min();
     }  
  }

  if((input[s] < 0) && (curSum > 0))
  {
    curSum = curSum - input[s];
    result = curSum > result?curSum:result;
  }
 
  return result;
}

int main()
{
  //std::vector<int> input = {1,2,3};
  //std::vector<int> input = {-1,-2,-3};
  //std::vector<int> input = {-1,2,3};
  //std::vector<int> input = {1,2,-2,4};
  std::vector<int> input = {3,-5,10};
  int result = maxContigousSubArraySum2(input);
  cout << "result," << result << endl;
}
