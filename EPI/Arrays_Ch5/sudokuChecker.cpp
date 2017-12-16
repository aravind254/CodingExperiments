#include "arrUtil.cpp"


// TimeComplexity : O(n^2) + O(n^2) + O(n^2) = O(n^2)
// SpaceComplexity: O(n) i.e size of temp vector

void checkIfSudokuIsValid(const vector<vector<int>> &A)
{
	vector<int> temp(10); // used to track duplicates
	int k = 0;
	int n = A.size(); // Number of rows
	int m = A[0].size(); // Number of columns
	if(!((n == 9) && (m == 9)))
	{
		cout << "Invalid Sudoku row," << n << " column," << m << endl;
		return;
	}

	cout << "checkIfSudokuIsValid n = " << n << " m = " << m << endl;
	// Check Row
	for(int i = 0;i<n;i++)
	{
	  temp.assign(10,0); // reset temp
	  for(int j = 0;j<m;j++)
	  {
	    if(A[i][j] != 0)
	    {
		k = A[i][j];
		if(temp[k] != 0)
		{
			cout << "Invalid Sudoku failed(Row check) at i," << i << " j," << j << endl;
		        return;	
		}
		temp[k]++;
	    }
	  }
	}
	cout << "Row check Complete" << endl;
	
	// Check Column
	for(int j = 0;j<m;j++)
        { 
          temp.assign(10,0); // reset temp
          for(int i = 0;i<n;i++)
          { 
            if(A[i][j] != 0)
            {   
                k = A[i][j];
                if(temp[k] != 0)
                {       
                        cout << "Invalid Sudoku failed(Column check) at i," << i << " j," << j << endl;
                        return;
                }
                temp[k]++;
            }   
          }
        }

	cout << "Column check Complete" << endl;

	// Check Sub Matrices
	vector<vector<int>> subIs = {{0,0},{0,3},{0,6},
			        {3,0},{3,3},{3,6},
				{6,0},{6,3},{6,6}};
	int sI = 0,sJ = 0;

	for(int m = 0;m<subIs.size();m++)
	{
	 sI = subIs[m][0];
         sJ = subIs[m][1];
	 temp.assign(10,0);
	 for(int i = sI;i<(sI+3);i++)
	 {
	  for(int j = sJ;j<(sJ+3);j++)
	  {
	   if(A[i][j] != 0)
	   {
	    k = A[i][j];
	    if(temp[k] != 0)
	    {
	       cout << "Invalid Sudoku.Matrix Check failed at i," << i << " j," << j << endl;
	       return;
	    }
	    temp[k]++;
	  }
	 }
	}
       }

	cout << "SubMatrix check Complete" << endl;
	cout << "Sudoku is Valid" << endl;

}


int main()
{
  vector<vector<int>> A = {{5,3,0,0,7,0,0,0,0},
			   {6,0,1,9,5,0,0,0,0},
			   {9,8,0,0,0,6,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0},
			   {0,0,0,0,0,0,0,0,0}
		};
  checkIfSudokuIsValid(A);
}

