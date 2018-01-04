#include<iostream>
#include<vector>
using namespace std;

template <class T>
void printVector(const vector<T> &A1)
{
        for(int i = 0;i<A1.size();i++)
        {
                        cout << A1[i] << " ";
        }
        cout << endl;
}

template <class T>
void printMatrix(const vector<vector<T>> &A1)
{
	int n = A1.size();
        cout << "printMatrix" << endl;
        for(int i = 0;i<n;i++)
        {
	  int m = A1[i].size();	
         for(int j = 0;j<m;j++)
         {
           cout << A1[i][j] << " ";
         }
         cout << endl;
        }
        cout << endl;
}


