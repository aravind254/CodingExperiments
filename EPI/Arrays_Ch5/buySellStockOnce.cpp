include<iostream>
#include<vector>

using namespace std;

/*
A = [10 5 10 2 3 4 1 11 2 20]
maxProfit should return 19
*/

// Time Comp  :  O(n)
// Space Comp :  O(1)

double maxProfit(const std::vector<double> &A)
{
	double result = 0.0, minP = numeric_limits<double>::max(),maxP=0.0;
	for(int i = 0;i<A.size();i++)
	{
		if(A[i] < minP)
		{
			minP = A[i];
			maxP = 0.0;
		}
		else if((A[i] > maxP) && ((A[i] - minP) > result))
		{
			maxP = A[i];
			result = maxP - minP; 
		}	
	}
	return result;
}

int main()
{
	std::vector<double> Prices={10,5,10,2,3,4,1,11,2,20};
	double profit = maxProfit(Prices);
	cout << "profit = " << profit << endl;
	
}



