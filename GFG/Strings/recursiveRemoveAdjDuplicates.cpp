//https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0
//https://www.geeksforgeeks.org/recursively-remove-adjacent-duplicates-given-string/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int recRemAdjDuplicates(string &A,int i,int j);

// Time Complexity : O(n)
// Space Complexity : O(1)

void recRemAdjDuplicates(string &A)
{
   int end = recRemAdjDuplicates(A,1,1);
   A = A.substr(0,end);
}

int recRemAdjDuplicates(string &A,int i,int j)
{
  if(i == A.size())
  {
     return j;
  }
  
  if((A[i] != A[i-1]) && (A[i] != A[i+1]))
  {
     if(A[i] != A[j-1])
     {
        A[j] = A[i];
        j++;
     }
     else
     {
       j--;
     }
  }
  i++;

  return recRemAdjDuplicates(A,i,j);
}

int main()
{
  string input1 = "geeksforgeeg";
  string input2  = "azxxxzy";
  string input3 = "caaabbbaac";
  string input4 = "qpaaaaadaaaaadprq";
  string input5 =  "acaaabbbacdddd";
  recRemAdjDuplicates(input1);
  recRemAdjDuplicates(input2);
  recRemAdjDuplicates(input3);
  recRemAdjDuplicates(input4);
  recRemAdjDuplicates(input5);
  cout << input1 << endl;
  cout << input2 << endl;
  cout << input3 << endl;
  cout << input4 << endl;
  cout << input5 << endl;
}
