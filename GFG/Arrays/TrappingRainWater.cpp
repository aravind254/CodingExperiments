//https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// Its possible to solve this with O(1) Space Complexity & O(n) time complexity.

// TimeComplexity : O(n)
// SpaceComplexity : O(n)
int calculateVolume(const vector<int> &input, int start,int end)
{
   cout << "calculateVolume start," << start << ",end," << end << endl;
   int waterVolume = -1;
   int intervalLength = end-start-1;
   int maxHeightWater = min(input[start],input[end]);
   // Calculating maxVolume assuming height of all the blocks in the interval is 0
   int maxVolume = intervalLength * maxHeightWater;
   waterVolume = maxVolume; 
   // Remove volumes of blocks with height > 0 from maxVolume to get the actual volume of water stored
   for(int i = start+1;i<end;i++)
   {
      if(input[i] > 0)
      {
         if(input[i] >= maxHeightWater)
         {
           waterVolume -= maxHeightWater;
         }
         else
         {
           waterVolume -= input[i];     
         }
      }
   }
   cout << "waterVolume," << waterVolume << endl;
   return waterVolume;
}

int findLevelOfWaterTrapped(const vector<int> &input)
{
   vector<int> ltoRIndex;int ltoRVolume = 0;
   vector<int> RtolIndex;int RotlVolume = 0;
   int result = -1;
   int curMax = 0;
   

   for(int i = 0;i<input.size();i++)
   {
      if(curMax < input[i]){ 
      curMax = input[i];
      cout << "insert i,"<< i << endl;
      ltoRIndex.emplace_back(i); 
      }
   }

   curMax = 0;
   int endIndex = ltoRIndex.back();
   cout << "endIndex, " << endIndex << endl;
   for(int i = input.size()-1;i>=endIndex;i--)
   {
      if(curMax < input[i]){ 
      curMax = input[i];
      RtolIndex.emplace_back(i); 
      }
   }

  cout << "ltoRIndex size," << ltoRIndex.size() << endl; 
   if(ltoRIndex.size() >= 2)
   {
       for(int i = 1;i<ltoRIndex.size();i++)
       {
         cout << "LeftVolume" << endl;
         ltoRVolume += calculateVolume(input,ltoRIndex[i-1],ltoRIndex[i]);          
       }
   }
 
   if(RtolIndex.size() >= 2)
   {
       for(int i = 1;i<RtolIndex.size();i++)
       {
         cout << "RightVolume" << endl;
         RotlVolume += calculateVolume(input,RtolIndex[i],RtolIndex[i-1]);          
       }
   }
  
   cout << "ltoRVolume," << ltoRVolume << endl;
   cout << "RotlVolume," << RotlVolume << endl;

   result = ltoRVolume + RotlVolume; 

   return result;
}

int main()
{
  vector<int> input1 = {3,0,0,2,0,4}; // expected result = 10
  vector<int> input2 = {2,0,2}; // expected result = 2
  vector<int> input3 = {0,3,2,1,0,1,2,3,0,0}; // expected result = 9
  vector<int> input4 = {2,1,6,8,5};// expected result = 1
  vector<int> input5 = {0,1,0,2,1,0,1,3,2,1,2,1}; // expected result = 6
  int waterVolume = findLevelOfWaterTrapped(input5); 
  cout << "waterVolume,"<< waterVolume << endl;
}
