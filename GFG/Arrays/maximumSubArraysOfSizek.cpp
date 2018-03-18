//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
#include<iostream>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

void updateDq(int val,std::deque<int> &input)
{
   while(!input.empty())
   {
      if(val > input.back())
      {
         cout << "val," << val <<  ",pop," << input.back() << endl;
         input.pop_back();
      }
      else
      {
          break;
      }
   }
   cout << "push back " << val << endl;
   input.push_back(val);
  
}

vector<int> maxOfSubArraysOfSizeK(const vector<int> &input,int k)
{
 vector<int> result;
 queue<int> q1;
 deque<int> dq;

 for(int s : input)
 {
   cout << "s, " << s << endl;
   if(q1.size() < k)
   {
       q1.push(s);
       updateDq(s,dq);   
   }
   else
   {
        result.emplace_back(dq.front());
        int temp = q1.front();
        q1.pop();
        if(dq.front() == temp)
        {
           dq.pop_front();
        }
        q1.push(s);
        updateDq(s,dq);
        cout << "update result " << dq.front() << endl;
   }
 }
 if(!dq.empty())
 {
   result.emplace_back(dq.front());
 }
 return result;
}

int main()
{
  vector<int> input1 = {1,2,3,1,4,5,2,3,6};
  int k1 = 3;
  vector<int> input2 = {8,5,10,7,9,4,15,12,90,13};
  int k2 = 4;
  vector<int> result = maxOfSubArraysOfSizeK(input2,k2);
  for(int s : result)
  {
    cout << s << ",";
  }
  cout << endl;
}
