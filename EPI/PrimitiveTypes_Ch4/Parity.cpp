#include<iostream>
#include<string>

using namespace std;

//Time Complexity:  O(n) n being the number of bits in a
//Space Complexity: O(1)
int FindParityBF(unsigned int a)
{
 int result = 0;
 int counter = 0;
 while(a)
 {
   if(a & 1)
   {
	result^=1;
   }
   a = a >> 1;
 }
 cout << "FindParityBF result = " << result << endl;

 return result;
}

//Time Complexity: O(k) k being the number of set bits in a
//Space Complexity: O(1)
int FindParityOptimized(unsigned int a)
{
 int result = 0; 
 while(a)
 {
   result ^= 1;
   a = a & (a - 1);
 }
 cout << "FindParityOptimized result = " << result << endl;
 return result;
}

int main(int argc, char* argv[])
{
  if(argc > 2)
     return 1;

  std::string input(argv[1]);
  cout << "input = " << input << endl; 
  int a  = stoi(input); 
  if(a < 0)
  {
   cout << "Neg number not allowed" << endl;
   return 1; 
  }

  FindParityBF(a);
  FindParityOptimized(a);


 return 0;
}
