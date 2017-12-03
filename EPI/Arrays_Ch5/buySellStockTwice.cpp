#include<iostream>
#include<vector>

using namespace std;

/*
A = [10 5 10 2 3 4 1 11 2 20]
maxProfit should return  28 ( 10 + 18)
*/
// Time  Comp : O(n)
// Space Comp : O(1)

double maxProfit(const std::vector<double> &A)
{
	double result = 0.0;
	std::pair<double,double> p1Range = {numeric_limits<double>::max(),0.0}; double p1=0.0;
	std::pair<double,double> p2Range  = {numeric_limits<double>::max(),0.0}; double p2=0.0;
	std::pair<double,double> tempRange = {numeric_limits<double>::max(),0.0}; double temp=0.0;
	int workingOn = -1;
	double temp1=0.0,temp2=0.0;
	double r1=0.0,r2=0.0;
	
	for(int i = 0;i<A.size();i++)
	{
	     // For every i there are 2 choices. Pick #1 or #2 depending on what maximizes the result
	     // #1 Extend workinOn profit
	     // #2 Get a new profit better than p1 or p2	
	   
		
	     if(A[i] < tempRange.second) // Found a  min
	     {
		tempRange.first = A[i];
		tempRange.second = 0.0;
		temp = 0.0;
	     }
	     else if(A[i] > tempRange.second) // Found a new max
	     {
		tempRange.second = A[i];
	     	temp = tempRange.second - tempRange.first;
		
		temp1 = temp + p2; 
		temp2 = temp + p1;
		if((temp1 > result) || (temp2 > result))
		{
			if(temp1 > temp2){ temp2 = 0.0;}
			else { temp1 = 0.0;}
		}
		else { temp1 = 0.0;temp2=0.0;}

		if(workingOn == 1)
		{
			if(tempRange.second > p1Range.second) // Extend p1
			{
				r1 = (tempRange.second - p1Range.first) + p2;
				r2 = 0.0;
			}
		}
		else if(workingOn == 2)
		{
			if(tempRange.second > p2Range.second) // Extend p2
			{
				 r2 = (tempRange.second - p2Range.first) + p1;
				 r1 = 0.0;
			}
		}

		if((r1 + r2) > (temp1 + temp2)) // Extend p1 or p2 
		{
			if(r1 != 0) { p1Range.second = tempRange.second;p1 = p1Range.second - p1Range.first;}  
			else { p2Range.second = tempRange.second;p2 = p2Range.second - p2Range.first;}
		}
		else // Replace p1 or p2
		{
			if(temp1 != 0)	{ p1 = temp; p1Range = tempRange; workingOn = 1; }
			else { p2 = temp; p2Range = tempRange;workingOn = 2;}
 		}
		} 
	result = p1 + p2;	
	}
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;
		 
	return result;
}

int main()
{
	std::vector<double> Prices1={10,5,10,2,3,4,1,11,2,20};
	std::vector<double> Prices2={12,11,13,9,12,8,14,13,15};
	double profit;
	profit = maxProfit(Prices1);
	cout << "profit = " << profit << endl;
	profit = maxProfit(Prices2);
	cout << "profit = " << profit << endl;
	
}



