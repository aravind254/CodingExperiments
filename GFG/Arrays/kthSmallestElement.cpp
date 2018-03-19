//https://practice.geeksforgeeks.org/problems/kth-smallest-element/0
#include<iostream>
#include<vector>
#include<queue>

using namespace std;


// TimeComplexity : O(nlogk)
// SpaceComplexity: O(k)

int kthSmallestElement(const vector<int> &input, int k)
{
  priority_queue<int> maxHeap;
  for(int s : input)
  {
    if(maxHeap.size() < k)
    {
       maxHeap.push(s);
    }
    else
    {
      int temp = maxHeap.top();
      if(s < temp)
      {
         maxHeap.pop();
         maxHeap.push(s);
      }
    }
  }

  return maxHeap.top();
}

int main()
{
   vector<int> input1 = {7,10,4,3,20,15};
   int k1 = 3;

   vector<int> input2 = {7,10,4,20,15};
   int k2 = 4;
   
   int result = kthSmallestElement(input2,k2);
   cout << "result," << result << endl;
}

