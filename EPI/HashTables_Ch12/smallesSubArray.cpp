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
subArray findSmallestSubarray(const vector<string> &input, const vector<string> &searchSet)
{
  unordered_map<string,list<int>::iterator> sMap;
  list<int> iList;
  subArray result = {-1,-1};
  int minDistance = std::numeric_limits<int>::max();
  int searchSetSize = searchSet.size();
 
  for(auto s:searchSet)
  {
    sMap[s] = iList.end(); 
  }
 
  for(int i = 0;i<input.size();i++)
  {
       if(sMap.find(input[i]) != sMap.end()) // Is the input string present in the search set
       {
            if(sMap[input[i]] != iList.end()) // Was this string encountered already in the input
            {
                iList.erase(sMap[input[i]]);
            }

            iList.emplace_back(i);
            sMap[input[i]] = --iList.end();

            if(iList.size() == searchSetSize)
            {
		int tempDistance = iList.back() - iList.front();
		if(minDistance > tempDistance)
		{
			minDistance = tempDistance; 
		}
            }
       }
  }
  cout << "minDistance," << minDistance << endl;
  cout << "front,"<< iList.front() << ",back," <<  iList.back() << endl;
 
  if(minDistance < std::numeric_limits<int>::max())
  {
	result.start = iList.front();
	result.end   = iList.back();
  }
  return result;
}

int main()
{
  vector<string> input = {"apple","banana","apple","apple","dog","cat","apple","dog","banana","apple","cat","dog"};
  vector<string> searchSet = {"banana","cat","dog"};
  subArray result = findSmallestSubarray(input,searchSet);
  cout << "start,"<< result.start << ",end,"<< result.end << endl; 
}
