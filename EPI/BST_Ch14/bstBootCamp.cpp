#include<iostream>
#include<map> // Uses BST
#include<set> // Uses BST

using namespace std;

struct myCompare
{
 bool operator()(int a,int b) { return a > b;}
};

int main()
{
  set<int> mySet; // Set that sorts in ascending order
  auto compare = [](int a, int b){return a>b;};
  //set<int,decltype(compare)> descSet(compare); // Set that sorts in descending order
  //auto compare = [](int a, int b){return a>b;};
  set<int,myCompare> descSet; // Set that sorts in descending order
  map<int,int> myMap;

  auto iter1 = mySet.emplace(5); // returns a pair<iterator,bool>
  auto iter2 = mySet.emplace(1);
  auto iter3 = mySet.emplace(3);
  auto iter4 = mySet.emplace(6);
  auto iter5 = mySet.emplace(6);

  for(int a : mySet)
  {
    cout << a << ",";
  }
  cout << endl;

  cout << "Min is " << *(mySet.begin()) << endl;
  cout << "Max is " << *(mySet.rbegin()) << endl;

  cout << "lower_bound for 1 " << *(mySet.lower_bound(1)) << endl;
  cout << "upper bound for 1 " << *(mySet.upper_bound(1)) << endl;
 
  pair<set<int>::iterator,set<int>::iterator> val = mySet.equal_range(1);
  cout << "lower_bound for 1 " << *val.first << endl;
  cout << "upper bound for 1 " << *val.second << endl;


  mySet.erase(iter4.first);
  cout << "Erase " << *(iter4.first) << endl;
  cout << "Min is " << *(mySet.begin()) << endl;
  cout << "Max is " << *(mySet.rbegin()) << endl;

  mySet.erase(1);
  cout << "Erase 1" << endl;
  cout << "Min is " << *(mySet.begin()) << endl;
  cout << "Max is " << *(mySet.rbegin()) << endl;



  auto iter6 = descSet.emplace(5); // returns a pair<iterator,bool>
  auto iter7 = descSet.emplace(1);
  auto iter8 = descSet.emplace(3);
  auto iter9 = descSet.emplace(6);
  auto iter10 = descSet.emplace(6);

  for(int a : descSet)
  {
    cout << a << ",";
  }
  cout << endl;

  cout << "Min is " << *(descSet.rbegin()) << endl;
  cout << "Max is " << *(descSet.begin()) << endl;

  descSet.erase(iter9.first);
  cout << "Erase " << *(iter9.first) << endl;
  cout << "Min is " << *(descSet.rbegin()) << endl;
  cout << "Max is " << *(descSet.begin()) << endl;

  descSet.erase(1);
  cout << "Erase 1" << endl;
  cout << "Min is " << *(descSet.rbegin()) << endl;
  cout << "Max is " << *(descSet.begin()) << endl;

  // myMap is sorted in ascending order by default based on keys
  myMap[15] = 1;
  myMap[10] = 2;
  myMap[20] = 3;
  myMap[30] = 4;
  myMap[60] = 5;

 for (std::map<int,int>::iterator it=myMap.begin(); it!=myMap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  cout << "Min is " << myMap.begin()->first << endl;
  cout << "Max is " << myMap.rbegin()->first << endl;

  cout << "lower_bound for 10 is " << myMap.lower_bound(10)->first << endl;
  cout << "upper bound for 10 is " << myMap.upper_bound(10)->first << endl;
  
  pair<map<int,int>::iterator,map<int,int>::iterator> valBound = myMap.equal_range(10);
  cout << "lower_bound for 10 is " << (valBound.first)->first << endl;
  cout << "upper bound for 10 is " << (valBound.second)->first << endl;
}
