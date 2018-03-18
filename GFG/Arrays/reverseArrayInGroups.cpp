//https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

void reverseSubArray(vector<int> &input, int k)
{
   int n = ceil(input.size()/k);
   int i = 0;
   for(i = 0;i<n;i++)
   {
     reverse((input.begin() + (i*k)),(input.begin() + (i+1)*k));
   }
   reverse(input.begin()+(i*k), input.end());
}

int main()
{
  vector<int> input1 = {1,2,3,4,5};
  int k1 = 3;
  vector<int> input2;
  for(int i = 1;i<43;i++) {input2.emplace_back(i);}
  int k2 = 10;
  reverseSubArray(input2,k2);
  for(int s : input2)
  { 
    cout << s  << "," ;
  }
  cout << endl;
}
