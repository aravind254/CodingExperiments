//https://practice.geeksforgeeks.org/problems/minimum-platforms/0
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct schedule 
{
 int arrivalTime;
 int depTime;
};

struct endPoint
{
  bool isArrival=false;
  int time;
};

// Time Complexity : O(nlogn)
// Space Comlexity : O(n)
int minNumberOfPlatforms(const vector<schedule> &input)
{
  vector<endPoint> points;
  int result = 0;
  int curPlatforms = 0;
  for(auto s: input)
  {
    endPoint temp = {true,s.arrivalTime};
    points.emplace_back(temp);
    temp = {false,s.depTime};
    points.emplace_back(temp);
  }
  
  sort(points.begin(),points.end(),[](const endPoint &a, const endPoint &b){
   				 return (a.time < b.time); 
				});

  for(auto s: points)
  {
     if(s.isArrival) 
     {
       curPlatforms++;
       result = max(result,curPlatforms);
     }
     else
     {
       curPlatforms--;
     }
  }

 return result; 
}

int main()
{
   vector<schedule> input = {{900,910},{1100,1130},{940,1200},{950,1120},{1500,1900},{1800,2000}};
   int minPlatforms = minNumberOfPlatforms(input);
   cout << "minPlatforms, " << minPlatforms << endl;
}

