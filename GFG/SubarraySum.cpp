#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


struct Index
{
 bool found = false;
 int start = -1;
 int end = -1;
};


/*
TARGET SUM 13:

[5 10 1 2 4 6]

s = 0, e = 0 , sum = 5 ( < 13)
s = 0, e = 1 , sum = 15 ( > 13)
s = 1, e = 1,  sum = 10 ( < 13)
s = 1, e = 2,  sum = 11 ( < 13)
s = 1, e = 3,  sum = 13 ( == 13)
return 1, 3

5 10 5 10 10 10 10 13

[15 11 13]

0

s = 0 , e = 0 , sum = 15 ( > 0)
s = 0,  e = 1, sum = 26 ( > 0)
s = 1,  e = 1, sum = 11 ( > 0)
 
https://www.geeksforgeeks.org/find-subarray-with-given-sum/
*/

// Time Complexity : O(n)
// Space Complexity : O(1)
// SubArray Sum for non negative integers
Index findSubArrayWithGivenSum(const std::vector<int> &input, int targetSum)
{
 int s = 0, e = 0, curSum = 0;
 size_t iSize = input.size();
 Index result;

 while(e <= (iSize-1))
 {
    curSum += input[e];

    while((curSum > targetSum) && ( s < e)) 
    {
       curSum -= input[s];
       s++;
    } 
    
    if(curSum == targetSum)
    {
      result.start = s;
      result.end = e;
      result.found = true;
      return result; 
    }
    e++;
 }
 return result;
}


/*
Time Complexity : O(n)
Space Complexity : O(n)

5 10 15
targetSum = 25

myMap[5] = 0;
myMap[15] = 1;
myMap[30] = 2; ( curSum - targetSum = 5, myMap[5] = 0, start = 0 + 1, end = 2)

-20,-20,10,-5,10
targetSum = -10

myMap[-20] = 0 (-20 + 10) 
myMap[-40] = 1 (-40 + 10)
myMap[-30] = 2 (-30 + 10, Found in Map myMap[-20])

https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/
*/

Index findSubArrayWithGivenSumNegative(const std::vector<int> &input, int targetSum)
{
  int curSum = 0,e = 0;
  size_t iSize = input.size();
  std::unordered_map<int,int> myMap; // contains curSum upto a index
  Index result;

  cout << "findSubArrayWithGivenSumNegative" << endl;

  while(e <= (iSize-1))
  {
     curSum += input[e];
     
     if(curSum == targetSum)
     {
       result.start = 0;
       result.end = e;
       result.found = true;
       break;
     }

     int diff = curSum-targetSum;
     if(myMap.find(diff) != myMap.end())
     {
        result.start = myMap[diff] + 1;
        result.end = e;
        result.found = true;
        break;
     }

     myMap[curSum] = e;
     e++;
  }
  return result;
}

int main()
{
  //vector<int> input = {5,10,1,2,4,6};
  //int targetSum = 13;
  //vector<int> input = {1,4,20,3,10,5};
  //int targetSum = 33;
  //vector<int> input = {1,4,0,0,3,10,5};
  //int targetSum = 7;
  vector<int> input = {1,4};
  int targetSum = 0;
  Index result = findSubArrayWithGivenSum(input,targetSum);
  if(result.found)
  {
     cout << "start," << result.start << ",end," << result.end << endl; 
  }
  else
  {
     cout << "SubArray not found for sum," << targetSum << endl;
  }

  vector<int> input2 = {-20,-20,10,-5,10};
  int targetSum2 = -10;
  //vector<int> input2 = {1,4,20,3,10,5};
  //int targetSum2 = 33;
 
  Index result2 = findSubArrayWithGivenSumNegative(input2,targetSum2);
  if(result2.found)
  {
     cout << "start," << result2.start << ",end," << result2.end << endl; 
  }
  else
  {
     cout << "SubArray not found for sum," << targetSum2 << endl;
  }
}
