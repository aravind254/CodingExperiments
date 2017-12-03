#include<iostream>
#include<vector>

using namespace std;

void printVector(const vector<unsigned int> &A)
{
 for(int i = 0;i<A.size();i++)
 {
	cout << A[i] << " " ;
 }
 cout << endl;
}


// Variant
std::string addArbPrecIntegers(const std::string &A,const std::string &B)
{

}

void incrementArbPrecInteger(std::vector<unsigned int> &A)
{
 int carry = 0;
 int end =  A.size()-1;
 bool first = false;

 if((A[end] + 1) == 10)
 {
	A[end] = 0;
	carry = 1;
 }
 else
 {
	A[end]++;
	return;
 }

 for(int i = end-1;i>=0;i--)
 {
	if((A[i] + carry ) == 10)
	{
		carry = 1;
		A[i] = 0;
	}
	else
	{
		A[i]++;
		carry = 0;
		break;
	}
 }

 if(carry == 1)
 {
	A.insert(A.begin()+0,1); // Or Append 0 to end of the array and add 1 to the beginning of the array
 }

}

int main()
{
	vector<unsigned int> A = {9,9,9};
	incrementArbPrecInteger(A);
	printVector(A);
}
