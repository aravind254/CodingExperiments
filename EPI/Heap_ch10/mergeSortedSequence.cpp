#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct elem
{
  int val;
  int seqIndex;
  int subIndex;
};

bool compare(elem a,elem b)
{
   return (a.val > b.val);
}

// Time Complexity : O(nlogk), k is the number of rows in the 2D vector, n is the  total number of elements in the 2D vector
// Space Complexity: O(k)

vector<int> mergeSortedSequence(vector<vector<int>> sequence)
{
  priority_queue<elem,vector<elem>,function<bool(elem,elem)>> minHeap(compare);
  elem temp,temp1;
  int curSeqIndex=0,curSubIndex = 0;
  vector<int> result;
 
  // Initialize minHeap
  for(int i = 0;i<sequence.size();i++)
  {
     temp.val = sequence[i][0];
     temp.seqIndex = i;
     temp.subIndex = 0;
     minHeap.emplace(temp);
  }
  
  while(!minHeap.empty())
  {
      temp = minHeap.top();
      cout << "top " << temp.val << endl; 
      minHeap.pop();
      result.emplace_back(temp.val);
      curSeqIndex = temp.seqIndex;
      curSubIndex = temp.subIndex;
      if(curSubIndex < (sequence[curSeqIndex].size() - 1))
      {
        temp1.val = sequence[curSeqIndex][curSubIndex + 1];
        temp1.subIndex = curSubIndex + 1;
        temp1.seqIndex = curSeqIndex;
        minHeap.emplace(temp1);
      }
  }
  return result;  
}

int main()
{
  vector<vector<int>> seq = {{3,5,7},{0,1,10,11,13,14,15},{8,9,12}};
  vector<int> result = mergeSortedSequence(seq);
  for(int i = 0;i<result.size();i++)
  {
     cout << result[i] << " ";
  }
  cout << endl;
}
