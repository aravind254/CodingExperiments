#include<iostream>
#include<unordered_map>
#include<set>

using namespace std;

struct pType
{
  int key;
  int value;
};


struct myCompare
{
  bool operator()(const pType &a,const pType &b)
  {
     return a.value < b.value;
  }
};


typedef set<pType,myCompare>::iterator setIter;
typedef unordered_map<int,setIter>::iterator mapIter;

class Test
{
 public:
 int  getMin();
 void updateVal(int key, int value); 

 private:
 set<pType,myCompare> mySet; // MinHeap based on value in pType
 unordered_map<int,setIter> myMap; // Hash look up of  MinHeap based on key.
};

void Test::updateVal(int key, int value)
{
  mapIter iter1 = myMap.find(key);
  pType temp;
  temp.key = key; 
  temp.value = value;

  if(iter1 != myMap.end())
  {
      mySet.erase(iter1->second);
  }
  auto val  = mySet.emplace(temp); // returns  pair<iterator,bool>
  myMap[key] = val.first; 
}

int Test::getMin()
{
 return (mySet.begin())->value;
} 

int main()
{
 Test obj;
 obj.updateVal(1,10);   
 obj.updateVal(2,20);   
 obj.updateVal(3,5);   
 obj.updateVal(4,7);   
 obj.updateVal(5,8);   
 cout << obj.getMin() << endl;
 obj.updateVal(3,30);   
 cout << obj.getMin() << endl;
 obj.updateVal(4,25);   
 cout << obj.getMin() << endl;
 return 0;
}
