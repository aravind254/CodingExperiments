#include<iostream>
#include<vector>
using namespace std;

template <class T>
void printVector(const vector<T> &A1)
{
	cout << "printVector" << endl;
        for(int i = 0;i<A1.size();i++)
        {
                        cout << A1[i] << " ";
        }
        cout << endl;
}

