//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0
//https://www.geeksforgeeks.org/chocolate-distribution-problem/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int choclateDistribution(vector<int> &input,int m)
{
  int n = input.size();
  if(m > n) return -1;
  int s = 0, e = m -1;
  int result  = std::numeric_limits<int>::max();
  sort(input.begin(),input.end());
  while(e<n)
  {
     int diff = input[e]-input[s];
     result = diff<result?diff:result;
     s++;e++;
  } 
 return result; 
}

int main()
{
  vector<int> input1 = {7, 3, 2, 4, 9, 12, 56};
  int m1 = 3;
  vector<int> input2 = {3, 4, 1, 9, 56, 7, 9, 12};
  int m2 = 5;
  vector<int> input3 = {12, 4, 7, 9, 2, 23, 25, 41,30, 40, 28, 42, 30, 44, 48, 43, 50};
  int m3 = 7;

  int result1 = choclateDistribution(input1,m1);
  int result2 = choclateDistribution(input2,m2);
  int result3 = choclateDistribution(input3,m3);
  cout << "result1,"<< result1 << ",result2,"<< result2 << ",result3," << result3 << endl;
}
