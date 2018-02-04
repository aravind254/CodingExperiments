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


vector<int> incDec(const vector<int>& input)
{
   vector<vector<int>> seq;
   int curIndex=-1;
   int curSubIndex=-1;
   enum class dir {unknown,increasing,decreasing};
   dir dot = dir::unknown;
   
   // Decompose the increasing decreasing array into a 2D vector of increasing arrays.
   for(int i = 0;i<input.size();i++)
   {
       if(input[i+1] > input[i]) // increasing
       {
        if(dot == dir::increasing){
        seq.back().emplace_back(input[i]);
        }
	else{ // increasing start
        dot = dir::increasing; 
        seq.emplace_back();
        seq.back().emplace_back(input[i]);
        }
       }
       else // decreasing // TBD: How to efficiently insert elements to front of vector ( probably reverse iterators?)
	// TBD  : Using Deque might be better here
       {
	if(dot == dir::decreasing){
        seq.back().emplace_back(input[i]);
        }
        else{ // decreasing start
        dot = dir::decreasing;
        seq.emplace_back();
        seq.back().emplace_back(input[i]);
        }
       } 
   }
   
   for(int i = 0;i<seq.size();i++)
   {
	for(int j = 0; j < seq[i].size(); j++)
	{
		cout << seq[i][j] << " ";
	}
	cout << endl;
   }


   return mergeSortedSequence(seq);
}

int main()
{
  vector<int> seq = {1,2,3,4,5,4,3,2,1,2,3,4,5,4,3,2,1};
  vector<int> result = incDec(seq);
  for(int i = 0;i<result.size();i++)
  {
     cout << result[i] << " ";
  }
  cout << endl;
}
