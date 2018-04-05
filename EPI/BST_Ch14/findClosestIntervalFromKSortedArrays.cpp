#include<iostream>
#include<vector>
#include<map> 

using namespace std;

int findMin(int a, int b, int c)
{
  int result = std::min(a,b);
  return std::min(result,c);
}

int findMax(int a, int b, int c)
{
  int result = std::max(a,b);
  return std::max(result,c);
}

vector<int> findClosestInteralFrom3SortedArrays(vector<vector<int>> sortedArrays)
{
  vector<int> result;
  int maxDiff = std::numeric_limits<int>::max();
  
  int i = 0, j = 0, k = 0;
  int iSize = sortedArrays[0].size();
  int jSize = sortedArrays[1].size();
  int kSize = sortedArrays[2].size();
  
  while((i<iSize) && (j<jSize) && (k<kSize))
  {
    int min = findMin(sortedArrays[0][i],sortedArrays[1][j],sortedArrays[2][k]);
    int max = findMax(sortedArrays[0][i],sortedArrays[1][j],sortedArrays[2][k]);
    
    if((max-min) < maxDiff)
    {
      maxDiff = max - min;
      cout << "Found " << maxDiff << endl;
      result.erase(result.begin(),result.end());
      result.emplace_back(sortedArrays[0][i]);
      result.emplace_back(sortedArrays[1][j]);
      result.emplace_back(sortedArrays[2][k]);
    } 

    if(min == sortedArrays[0][i])
    {
      i++;
    }
    else if(min == sortedArrays[1][j])
    {
      j++;
    }
    else
    {
      k++;
    }
  }
  return result;
}

// TimeComplexity : O(nlogk),
// n is the number of elemens in the 2D vector, k is the number of rows in the 2D vector
// logk comes from the time taken to insert/delete element from the multimap
int findClosestInteralFromKSortedArrays(vector<vector<int>> sortedArrays)
{
  int minDiff = std::numeric_limits<int>::max();

  struct startEnd
  {
    int vIndex;
    int sIndex;
    size_t eIndex;
  };

  multimap<int,startEnd> myMap;
  int vectorIndex = 0;
  cout << "build multimap" << endl; 
  for(auto &s : sortedArrays)
  {
      startEnd temp = {vectorIndex,0,s.size()};
      cout << "start key " << s[0] << endl; 
      myMap.emplace(s[0],temp);
      vectorIndex++;
  }

  while(true)
  {
    int next_min = myMap.cbegin()->first;
    int next_max = myMap.crbegin()->first;
    cout << "next_min, " << next_min << endl;
    cout << "next_max, " << next_max << endl;
    
    minDiff = min(minDiff, (next_max-next_min));
    int nMinIndex = myMap.cbegin()->second.sIndex + 1;

    if(nMinIndex ==  myMap.cbegin()->second.eIndex)
    {
       return minDiff;
    }
    int vIndex = myMap.cbegin()->second.vIndex;
    size_t eIndex = myMap.cbegin()->second.eIndex;
    startEnd temp = {vIndex,nMinIndex,eIndex};
    myMap.erase(myMap.cbegin());
    myMap.emplace(sortedArrays[vIndex][nMinIndex],temp);
  }
}

int main()
{
  vector<vector<int>> sortedArrays = {{5,10,15},{3,6,9,12,15},{8,16,24}};
  vector<int> result = findClosestInteralFrom3SortedArrays(sortedArrays);
  for(int s : result)
  {
    cout << s << ",";
  }
  cout << endl;

  int closesInterval = findClosestInteralFromKSortedArrays(sortedArrays);
  cout << "closesInterval, " << closesInterval << endl;
}
