#include<iostream>
#include<list> // Doubly linked list
#include<unordered_map>

using namespace std;

struct pageInfo
{ 
  int pageNum;
  int data;
};
struct resultType 
{
  bool found = false;
  pageInfo info;
};


typedef list<pageInfo>::iterator lIterator;

class LRUCache
{
 public:
 LRUCache(int size):cacheSize(size){}
 resultType lookUp(int);
 void add(int,pageInfo);
 void printLL();

 private:
 int cacheSize = 0;
 list<pageInfo> myList;
 unordered_map<int,lIterator> myCache; 
};

void LRUCache::printLL()
{
  cout << "printLL" << endl;
  for(auto s : myList)
  {
    cout << s.pageNum << ","; 
  }
  cout << endl;

  cout << "print Cache" << endl;
  for(auto s: myCache)
  { 
    cout << (s.first) << ",";
  }
  cout << endl;
}

resultType LRUCache::lookUp(int pageNum)
{
  cout << "lookUp, pageNum, " << pageNum << endl;
  resultType result; 
  auto pResult  = myCache.find(pageNum);
  if(pResult == myCache.end())
  {
    cout << "page, " << pageNum << " not found" << endl;
    return result;
  }

  cout << "found pageNum," << pResult->first << endl;
  result.info = *(pResult->second);
  result.found = true;
  myList.erase(pResult->second);
  myList.emplace_front(result.info);
  myCache[pageNum] = myList.begin();
  printLL();
  return result;
}

void LRUCache::add(int pageNum,pageInfo pInfo)
{
   cout << "add pageNum,"<< pageNum << ",current cache size," << myCache.size()<<  endl;
   if(myCache.size() == cacheSize)
   {
      cout << "Cache is full, remore lru page" << myList.rbegin()->pageNum <<  endl;
      // Delete the least recently Used
      myCache.erase(myList.rbegin()->pageNum);
      myList.pop_back();
       
      // Add new Page
      myList.emplace_front(pInfo);
      myCache[pageNum] = myList.begin();
   }
   else
   {
      myList.emplace_front(pInfo);
      myCache[pageNum] = myList.begin();
   }
   printLL();
}

int main()
{
  LRUCache lruCache(4);
  pageInfo pInfo = {0,10};
  lruCache.add(0,pInfo);
  pInfo = {1,20};
  lruCache.add(1,pInfo);
  pInfo = {2,30};
  lruCache.add(2,pInfo);
  pInfo = {3,40};
  lruCache.add(3,pInfo);
  pInfo = {4,50};
  lruCache.lookUp(0);
  lruCache.add(4,pInfo);
  pInfo = {5,60};
  lruCache.add(5,pInfo);
  lruCache.lookUp(3);
  pInfo = {6,70};
  lruCache.add(6,pInfo);
  pInfo = {7,80};
  lruCache.add(7,pInfo);
}
