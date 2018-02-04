#include<iostream>
#include<vector>

using namespace std;


// if compare returns true the binary search will search the 2nd half. Choose compare function accordingly.
// So for increasing order sorted search it should be a < b and for decreasing sorted search it should be a > b
bool compare(int a, int b) {
 cout << "a = " << a << ",b = " << b << endl;
 return (a < b);
}

int main()
{
  vector<int> a = {5,6,10,12,20,40};
  int val=30;
  if(binary_search(a.begin(),a.end(),val))
  {
     cout << "found " << val << endl;
  }

  if(binary_search(a.begin(),a.end(),val,compare))
  {
     cout << "found " << val << endl;
  }

  vector<int>::iterator up  = upper_bound(a.begin(),a.end(),20); // first value greater than 20
  vector<int>::iterator lo  = lower_bound(a.begin(),a.end(),20); // first value which is >= 20
  cout << "up " << *up << endl;
  cout << "lo " << *lo << endl;
}
