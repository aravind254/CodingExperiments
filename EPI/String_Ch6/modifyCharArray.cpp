#include<iostream>

using namespace std;


void modifyArray(int size, char A[])
{
 int hIndex = 0, i = 0;
 int wIndex = 0,aCount = 0;

 // Remove b's
 while(i<size)
 {
	if(A[i] != 'b')
	{
	        A[hIndex] = A[i];	
		hIndex++;

		if(A[i] == 'a')
		{
			aCount++;
		}
	}

	i++;
 }

 i = 0;
 cout << "hIndex = " << hIndex << endl;
 cout << "aCount = " << aCount << endl;
 while(i<hIndex)
 {
	cout << A[i] << " ";
	i++;
 }

 cout << endl;
 
 // Update a entries
 wIndex = hIndex+aCount-1;
 i = hIndex-1;

 while(i >= 0)
 {
	if(A[i] == 'a')
	{
	    A[wIndex] = 'd';wIndex--;
	    A[wIndex] = 'd';wIndex--;
	}
	else
	{
	    A[wIndex] = A[i];wIndex--;
	}
 i--;
 }  

}

int main()
{
 char A[15] = {'a','c','d','b','b','c','a'};
 modifyArray(7,A);
 for(int i = 0;i<15;i++)
 {
	cout << A[i] << " ";
 }
 cout << endl;
}
