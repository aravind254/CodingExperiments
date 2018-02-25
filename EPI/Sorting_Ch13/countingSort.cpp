#include<iostream>
#include<vector>

using namespace std;

// Time Complexity : O(n + k) , n is the number of elements in the input vector and k is the range i.e 255
// Space Complexity : O(n + k)

// Assuming input element range ( 0 to 255)
vector<int> countingSort(const vector<int> &input)
{
 vector<int> output(input.size()+1,0);
 vector<int> countBuffer(256,0); // Initialize a vector of size 256
 int curIndex = 0;
 bool zeroPresent=false;
 
 for(int val: input)
 {
   countBuffer[val]++;
 }
  
 for(int i = 1;i<256;i++) 
 { 
   countBuffer[i] += countBuffer[i-1];  
 }

 for(int val: input)
 {
   cout << "val," << val << ",index," << countBuffer[val] << endl;
   output[countBuffer[val]] = val;
   countBuffer[val]--;
 }
 
 return {output.begin()+1,output.end()};
}

int main()
{
 vector<int> input = {4,5,3,5,1,1,2,10};
 vector<int> output = countingSort(input);
 for(int i : output)
 {
   cout << i << ",";
 } 
 cout << endl;
}
