#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Result
{
 vector<int> result;
 bool found = false;
};

Result findSumPresentInAGivenListOfNumbersOptimized(std::vector<int> input,int sum)
{
  int start = 0, end = input.size()-1;
  int targetSum = sum;
  std::sort(input.begin(),input.end());
  
}

// TimeComplexity : O(n^2)
Result findSumPresentInAGivenListOfNumbers(std::vector<int> input,int sum)
{
 Result output;
 int curIndex = input.size() - 1;
 int start = input.size() - 1;
 int partialSum = sum;
 while(start >=0)
 {
   curIndex = start;
   partialSum = sum;
   output.result = {};
   while((curIndex>=0) && (partialSum)) 
   {
     if(input[curIndex] > partialSum){ curIndex--;}
     else if(input[curIndex] <= partialSum)  {
	 partialSum -= input[curIndex];
         output.result.emplace_back(input[curIndex]);
	 curIndex--;
      }
   }

   if(partialSum == 0){
      output.found = true;
      break;
   }
   start--;
 }
 return output;
}

int main()
{
 vector<int> input = {1,3,5,8,10};

 for(int sum = 1;sum<30;sum++)
 {
	 cout << "#ITER sum, " << sum << endl; 
	 Result output = findSumPresentInAGivenListOfNumbers(input,sum);
	 if(output.found)
	 { 
	   cout << "Found sum " << sum << endl;
	   for(auto s: output.result){ cout << s << ",";}
	   cout << endl;
	 }
	 else
	 { 
	   cout << "Could not find sum, " << sum << endl;
	 }
	 cout << "****************" << endl; 
 }
}
