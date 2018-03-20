//https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


// Time Complexity : O(n^2)
// Space Complexity : O(n). Its possible to reduce this to O(1),refer to algo in GFG
bool isPythagoreanTripletPresent(const vector<int> &input)
{
   unordered_set<int> mySet;
   int n  = input.size();
   bool result = false;
   for(int s : input)
   {
     mySet.emplace(s*s);
   }
   
   for(int i = 0;i<n;i++)
   {
     int a = input[i]*input[i];
     for(int j = 0; j<n;j++)
     {
        if(i == j) continue;
        int b =  input[j] * input[j];
        if(mySet.count(a+b))
        {
          result = true;
        }
     } 
   }
   return result;
}

int main()
{
   vector<int> input1 = {3,2,4,6,5};
   vector<int> input2 = {10,4,6,12,5};
   bool result = isPythagoreanTripletPresent(input2);
   cout << "result," << result << endl;
}
