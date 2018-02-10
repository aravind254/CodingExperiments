#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

class customHash
{
  public:
  size_t operator()(string input) const
  {
  size_t val = 0;
  int mult = 999;
  for(int i = 0;i<input.size();i++)
  {
     val = val * mult + input[i];
  }
  cout << "input," << input << ",val," << val << endl;
  return val;
  }
};

int main()
{

  cout << "**MAP**" << endl;
  unordered_map<string,int> myMap;
  myMap.insert({"James",0});
  myMap["Wade"] = 1;
  myMap.insert({"Krover",2});
  myMap.insert({"Tristan",3});

  for(auto it = myMap.begin();it!=myMap.end();it++)
  {
     cout << it->first << " " << it->second << endl;
  }

  cout << "**CUSTOM MAP HASH**" << endl;
  unordered_map<string,int,customHash> myMap2;
  myMap2.insert({"James",0});
  myMap2["Wade"] = 1;
  myMap2.insert({"Krover",2});
  myMap2.insert({"Tristan",3});

  for(auto it = myMap.begin();it!=myMap.end();it++)
  {
     cout << it->first << " " << it->second << endl;
  }


  cout << "**SET**" << endl;
  unordered_set<string> mySet;
  mySet.insert("James"); 
  mySet.insert("Wade"); 
  mySet.insert("Wade"); // Duplicates not allowed in the unordered_set, so this is dropped. 
  mySet.insert("Krover"); 
  mySet.insert("Krover");// Duplicates not allowed in the unordered_set, so this is dropped. 
  mySet.insert("Tristan"); 

  for(auto it = mySet.begin();it!=mySet.end();it++)
  {
     cout << *it << endl;
  }

  cout << "**SET WITH CUSTOM HASH FUNCTION**" << endl;
  unordered_set<string,customHash> mySet2;
  mySet2.insert("James"); 
  mySet2.insert("Wade"); 
  mySet2.insert("adeW"); 
  mySet2.insert("Wade"); // Duplicates not allowed in the unordered_set, so this is dropped. 
  mySet2.insert("Krover"); 
  mySet2.insert("Krover");// Duplicates not allowed in the unordered_set, so this is dropped. 
  mySet2.insert("Tristan"); 

  for(auto it = mySet2.begin();it!=mySet2.end();it++)
  {
     cout << *it << endl;
  }

  // C++ offers hash functions for standard types
  size_t val = hash<string>()("James");
  cout << "Hash for James is " << val << endl;
}
