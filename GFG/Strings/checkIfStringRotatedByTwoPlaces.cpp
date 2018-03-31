//https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0
//https://www.geeksforgeeks.org/check-string-can-obtained-rotating-another-string-2-places/

#include<iostream>
#include<string>
#include<vector>


using namespace std;

int k = 2;



bool checkUtil(string A,string B, int s)
{
  size_t aSize = A.size();
  size_t bSize = B.size();
  int j = 0,i = 0;

  if(aSize != bSize) return false;

  i = s;
  while((i<aSize) && (j<bSize))
  {
      if(A[i] == B[j]){
      j++;
      i++;
      }
      else{
        return false;
      }
    }

  i = 0;

  while((i<s) && (j<bSize))
  {
      if(A[i] == B[j]){
      j++;
      i++;
      }
      else{
        return false;
      }
  }
  return true;
}


// TimeComplexity : O(n)
// SpaceComplexity : O(1)
bool checkIfStringRotatedByTwoPlaces(string A, string B)
{
  int s = 0;

  // clockWiseStart
  s = A.size() - k;
  if(checkUtil(A,B,s)){
   cout << "clockwise check success" << endl;
   return true; 
  }

  // antiClockWiseStart
  s = k; 
  if(checkUtil(A,B,s)){
   cout << "antiClockwise check success" << endl;
   return true; 
  }

  return false;   
}

int main()
{
  string A = "amazon";
  string B = "azonam";
  string C = "onamaz";
  checkIfStringRotatedByTwoPlaces(A,B); 
  checkIfStringRotatedByTwoPlaces(A,C); 
}
