#include<iostream>
#include<vector>

using namespace std;

int aloneInCouple(vector<int> a)
{
  int result = 0;
  for(int i : a)
  {
    result ^= i;

  }
  return result; 
}

int main()
{
  vector<int>  a = {1,2,3,2,1};
  cout << aloneInCouple(a) << endl;
}
