#include<iostream>
#include<vector>

/*

// Row sorted and Column Sorted Matrix

1 4 7   7   8
4 5 9  10  11
6 7 9  11  12
18 19  20  21 22 
*/
using namespace std;


// TimeComplexity : O(n + m), n rows, m columns
// SpaceComplexity : O(1)

bool findElementInMatrix(const vector<vector<int>> &M,int elem)
{
 int maxRow = M.size()-1;
 int maxCol = M[0].size()-1; 
 int i = 0, j = maxCol;
 cout << "maxRow," <<  maxRow << ",maxCol," << maxCol << endl;
 while((i <= maxRow) && (j >= 0))
 {
   if(M[i][j] < elem) // eliminate the current row 
   {
     cout << "Eliminate row i = " << i  << endl;
     i++;
   }
   else if(M[i][j] == elem)
   {
     cout << "Found elem at i," << i << ",j," << j << endl;
     return true;
   } 
   else // elimiate the current column
   {
     cout << "Eliminate column j = " << j  << endl;
     j--;
   }
 } 
 return false;
}

int main()
{

vector<vector<int>> M = {{1,4,7,7,8},
			 {4,5,9,10,11},
			 {6,7,9,11,12},
			 {18,19,20,21,22},
    			};

int elem  = 6;

if(findElementInMatrix(M,elem))
{
  cout << "elem " << elem << " found" << endl;
}
}
