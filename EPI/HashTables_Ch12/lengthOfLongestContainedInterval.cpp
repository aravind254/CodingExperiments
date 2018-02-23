#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;


int longestContainedInterval(const vector<int> &input)
{
  unordered_set<int> mySet(input.begin(),input.end());
  int result = 0,length = 0;
  while(!mySet.empty())
  {
     int val = *(mySet.begin());
     mySet.erase(val);
     cout << "val," << val << endl;
     int low = val-1;
     int high = val+1;
     
     while(mySet.count(low))
     {
        mySet.erase(low);
	low--;
     }

     while(mySet.count(high))
     {
        mySet.erase(high);
	high++;
     }
     cout << "high," << high << ",low," << low << endl;
     
     length  = high-low-1; 
     result = (result < length)?length:result;
  }
  return result;
}

int main()
{
 vector<int> input = {3,-2,7,9,8,1,2,0,-1,5,8};
 int result = longestContainedInterval(input);
 cout << "result," << result << endl;
 return 0;
}
