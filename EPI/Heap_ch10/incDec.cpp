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

vector<vector<int>> SortKIncreasingDecreasingArray(const vector<int>& A) {
  // Decomposes A into a set of sorted arrays.
  vector<vector<int>> sorted_subarrays;
  typedef enum { INCREASING, DECREASING } SubarrayType;
  SubarrayType subarray_type = INCREASING;
  int start_idx = 0;
  for (int i = 1; i <= A.size(); ++i) {
    cout << "i," << i << ",val," << A[i] << endl;
    if (i == A.size() ||  // A is ended. Adds the last subarray.
        (A[i - 1] < A[i] && subarray_type == DECREASING) ||
        (A[i - 1] >= A[i] && subarray_type == INCREASING)) {
      if (subarray_type == INCREASING) {
        cout << "INCREASING start_idx," << start_idx << ",i," << i << endl;
        sorted_subarrays.emplace_back(A.cbegin() + start_idx, A.cbegin() + i);
      } else {
        cout << "DECREASING start_idx," << start_idx << ",i," << i << endl;
        sorted_subarrays.emplace_back(A.crbegin() + A.size() - i,
                                      A.crbegin() + A.size() - start_idx);
      }
      start_idx = i;
      subarray_type = (subarray_type == INCREASING ? DECREASING : INCREASING);
    }
  }
  return sorted_subarrays;
}

vector<int> incDec(const vector<int>& input)
{
   vector<vector<int>> seq;
   seq = SortKIncreasingDecreasingArray(input);
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
