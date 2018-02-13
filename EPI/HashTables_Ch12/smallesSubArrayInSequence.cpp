#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<string>

using namespace std;

struct subArray
{
  int start;
  int end;
};
 

// Assuming input size is n, searchSet size is k
// TimeComplexity : O(n+k)
// SpaceComplexity : O(k) 
subArray findSmallestSubarrayInSequence(const vector<string> &input, const vector<string> &searchSet)
{
  unordered_map<string,int> sMap;
  subArray result = {-1,-1};
  int minDistance = std::numeric_limits<int>::max();
  int searchSetSize = searchSet.size();
  vector<int> latestOccurence(searchSetSize,-1); // Tracks the latest index of the searchSet 
  vector<int> subArrayLength(searchSetSize,std::numeric_limits<int>::max());// Tracks the distance of the sub array
  
  int curIndex = 0;  // index that tracks the sequence of strings in the searchSet

  // Map the search set to the index  
  for(int i = 0;i<searchSet.size();i++)
  {
    sMap[searchSet[i]] = i; 
  }
 
  for(int i = 0;i<input.size();i++)
  {
       if(sMap.count(input[i])) // Is the input string present in the search set
       {
	  int curIndex = sMap[input[i]];
	  if(curIndex == 0) // This is start of the search set sequence
	  {
		subArrayLength[0] = 1;
          }
	  else if(subArrayLength[curIndex-1] != std::numeric_limits<int>::max())
	  {
		subArrayLength[curIndex] = subArrayLength[curIndex-1] + (i - latestOccurence[curIndex-1]); 
	  }

          latestOccurence[curIndex] = i;

	  // Is this the last word in the searchSet
	  if(curIndex == searchSetSize-1)
          {
		if(subArrayLength[curIndex] < minDistance)
     		{
			minDistance  = subArrayLength[curIndex];
   			result.start = latestOccurence[0];
			result.end   = latestOccurence[curIndex]; 
		}
          }
       }
  }

  cout << "minDistance," << minDistance << endl;

  return result;
}

int main()
{
  vector<string> input = {"apple","banana","apple","apple","dog","cat","apple","dog","banana","dog","cat","apple"};
  vector<string> searchSet = {"banana","cat","dog"};
  subArray result = findSmallestSubarrayInSequence(input,searchSet);
  cout << "start,"<< result.start << ",end,"<< result.end << endl; 
}
