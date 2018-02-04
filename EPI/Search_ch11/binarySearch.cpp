#include<iostream>
#include<vector>

using namespace std;

int binarySearch(int k, const vector<int>& A)
{
  int l = 0, u = A.size() -1,m=0;
  while(l<=u)
  { 
     m = l + (u - l)/2; // don't do (l+u)/2 for middle element, as l + u can overflow integer
     if(k < A[m])
     {
	u = m - 1;
     }
     else if(k == A[m])
     {
	return m;
     }
     else
     {
	l = m+1;
     } 
  }

  return -1;

}


int main()
{
 vector<int> a = {3,4,5,6,7};
 int elem = 1;
 int i = binarySearch(elem,a);
 if(i >= 0) { cout << "found " << elem << " at " << i << endl;} 
 else {cout << elem << " not found" << endl;}
 return 0;
}
