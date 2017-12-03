#include<iostream>
#include<vector>

using namespace std;

enum Color
{
RED=0,
WHITE,
BLUE,
GREEN
};

/*
In array A RED, WHITE, BLUE colors are all mixed.
This function should group the colors together
*/

// Time Complexity : O(n)
// Space Complexity : O(1)

/*
Output would order the array in the following order,
0 g1-1 will contain g1 elements
g1 g2-1 will contain g2 elements
g2 end will contain g3 elements
*/

void DutchFlagPartition(vector<Color>& A)
{
	int end = A.size() - 1;
	int g1I = 0,g2I=0,g3I = end;
	int g1 = 0,g2 = 1,g3 = 2;

	while(g2I <= g3I)
	{
		if(A[g2I] == g1)
		{
			swap(A[g2I],A[g1I]);
			g1I++;
		        g2I++;	
		}
		else if(A[g2I] == g2)
		{
			g2I++;
		}
		else
		{
			swap(A[g2I],A[g3I]);
			g3I--;
		}
		
	}
}


void printVectorPairs(const vector<pair<int,bool>> A1)
{
	for(int i = 0;i<A1.size();i++)
	{
		if(A1[i].second == false)
		{
			cout << "F," << A1[i].first << " ";
		}
		else
		{
			cout << "T," << A1[i].first << " ";
		}
	}
	cout << endl;
}

template <class T>
void printVector(const vector<T> &A1)
{
	for(int i = 0;i<A1.size();i++)
        {
			cout << A1[i] << " ";
        }
        cout << endl;
}

// Variant
/*
Output would order the array in the following order,
0 g1-1 will contain g1 elements
g1 g2-1 will contain g2 elements
Although group 3,4 will be grouped, order of g3,g4 is not guaranteed and it depends on the input
*/
void DutchFlagPartitionWithFourGroups(vector<Color>& A)
{
        int end = A.size() - 1;
        int g1I = 0,g2I=0,g3I= end, g4I = end;
        int g1 = 0,g2 = 1,g3 = 2,g4=3;
	int i = 0;
	cout << "DutchFlagPartitionWithFourGroups" << endl;

       	while((g2I <= g3I) && (g2I <= g4I))
	{
		printVector(A);
                if(A[g2I] == g1 )
                {
                        swap(A[g2I],A[g1I]);
                        g1I++;
                        g2I++;
                }
                else if(A[g2I] == g2)
                {
                        g2I++;
                }
		else if(A[g2I] == g3)
		{
			swap(A[g2I],A[g3I]);
			g3I--;
		}
                else if(A[g2I] == g4)
                {
                        swap(A[g2I],A[g4I]);
                        g4I--;
                }
        }
}



void groupBooleanKeysWithFalseFirst(vector<bool>& A)
{
	bool g1 = false,g2 = true;
	int g1I = 0, g2I = A.size()-1;

	cout << "groupBooleanKeysWithFalseFirst" << endl;
	while(g1I <= g2I)
	{
		if(A[g1I] == g1)
		{
			g1I++;
		}
		else 
		{
			swap(A[g1I],A[g2I]);
			g2I--;
		}
	}	

}

/*
vector of pair used just for verification purpose.
The index stored in the pair is never used in the algorithm
Time Complexity  : O(n)
Space Complexity : O(1)
*/
void groupBooleanKeysWithFalseFirstRetainTrueKeyOrder(vector<pair<int,bool>>& A)
{
	bool g1 = false,g2 = true;
	int g1I = 0, g2I = 0,end = A.size()-1,g1End=0;
	int numOfFalse = 0,i = 0;
	bool dT = false;

	while(i<=end)
	{
		if(A[i].second == false)
		{
			numOfFalse++;	
		}
	i++;
	}
	g2I = numOfFalse;
	g1End = numOfFalse-1;
	
	cout << "groupBooleanKeysWithFalseFirsttRetainTrueKeyOrder numOfFalse = " << numOfFalse << endl;
	while(g1I <= g1End)
	{
		if(A[g1I].second == g1)
		{
			dT = false;
			g1I++;
		}
		else if(A[g2I].second == g2)
		{
			if(dT == false)
			{
				swap(A[g1I],A[g2I]);
				g2I++;
				dT = true;
			}
			else
			{
				swap(A[g1I],A[g2I]);
				g2I++;
			}
		}
		else  if(A[g2I].second == g1)
		{
			if(dT == false)
			{
				swap(A[g1I],A[g2I]);
                                g2I++;
			}
			else
			{
				swap(A[g1I],A[g2I]);
			}
		}
	}	

}


int main()
{
	vector<Color> A1 = { RED,WHITE,BLUE,RED,WHITE,BLUE};
	DutchFlagPartition(A1);
	printVector(A1);
	vector<Color> A2 = { RED,WHITE,RED,RED,WHITE,BLUE,BLUE,WHITE};
	DutchFlagPartition(A2);
	printVector(A2);
	vector<Color> A3 = { RED,WHITE,BLUE,GREEN,RED,WHITE,BLUE,GREEN};
	DutchFlagPartitionWithFourGroups(A3);
	printVector(A3);
	vector<Color> A4 = { RED,WHITE,RED,RED,GREEN,WHITE,BLUE,BLUE,GREEN,WHITE,GREEN};
	DutchFlagPartitionWithFourGroups(A4);
	printVector(A4);
	vector<bool> A5 = {true,false,true,false,true,false,true,false,true};
	groupBooleanKeysWithFalseFirst(A5);
	printVector(A5);
	vector<pair<int,bool>> A6 = {{0,true},{1,false},{2,true},{3,false},{4,true},{5,false},{6,true},{7,false},{8,true}};
	groupBooleanKeysWithFalseFirstRetainTrueKeyOrder(A6);
	printVectorPairs(A6);
	vector<pair<int,bool>> A7 = {{0,true},{1,true},{2,false},{3,false},{4,true},{5,false},{6,true},{7,false},{8,true}};
	groupBooleanKeysWithFalseFirstRetainTrueKeyOrder(A7);
	printVectorPairs(A7);
	return 0;
}
