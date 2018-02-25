#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;


int main()
{
  vector<int> A = {3,4,5,2,1};
  list<int> B  = {5,4,3,2,1};
  sort(A.begin(),A.end()); // no sort function available as part of vector class, have to use std::sort
  for(int a : A) { cout << a << "," ;}
  cout << endl;
  sort(A.begin(),A.end(),[](int a, int b){ return a > b;}); // no sort function available as part of vector class, have to use std::sort
  for(int a : A) { cout << a << "," ;}
  cout << endl;
  B.sort(); // sort function available as part of list class 
  //sort(B.begin(),B.end()); // Cannot use std::sort with list, have to use inbuilt sort provided by list class
  cout << "B"  << endl;
  for(int b : B)
  {
    cout << b << "," ;
  }
  cout << endl;
}
