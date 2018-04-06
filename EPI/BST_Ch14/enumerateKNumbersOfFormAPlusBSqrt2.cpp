#include<iostream>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

struct AplusBSqrt2
{
  int a, b;
  double val;

  AplusBSqrt2(int a1, int b1):a(a1),b(b1){
  val = a + b * sqrt(2);
  }

  bool operator<(const AplusBSqrt2& cur) const {return (val < cur.val);}
  
};


// TimeComplexity : O(klogk)
// SpaceComplexity : O(k)

vector<double> enumerateKSmallessOfFormAplusBSqrt2(int k)
{
  set<AplusBSqrt2> mySet;
  vector<double> result;
  int a = 0, b  = 0;

  mySet.emplace(0,0);

  while(result.size()<k)
  { 
     auto nextSmallest = mySet.begin();
     result.emplace_back(nextSmallest->val); 
     mySet.emplace(nextSmallest->a+1,nextSmallest->b);
     mySet.emplace(nextSmallest->a,nextSmallest->b+1);
     mySet.erase(nextSmallest); 
  }
  return result;
}


int main()
{
  int k = 10;
  vector<double> result = enumerateKSmallessOfFormAplusBSqrt2(k);
  for(double s: result)
  {
    cout << s << ",";
  }
  cout << endl;
}
