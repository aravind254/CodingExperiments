#include<iostream>
#include<vector>
#include "arrUtil.h"

using namespace std;

vector<vector<int>> buildPascalTriangle(int n)
{ 
  vector<vector<int>> M;
  for(int i = 0;i<n;i++)
  {
	vector<int> currRow;
	for(int j=0;j<=i;j++)
	{
		if((j==0) || (j==i))
		{
		        currRow.emplace_back(1);	
			continue;
		}
		if(i > 1 )
                {
		  currRow.emplace_back(M[i-1][j] + M[i-1][j-1]);
		}
		
	}
	M.emplace_back(currRow);
  }
  return M;
}

int main()
{
  vector<vector<int>> M = buildPascalTriangle(5);
  printMatrix(M);
}

