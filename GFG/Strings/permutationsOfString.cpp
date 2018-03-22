//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Doesn't print the permutations in lexicographical order
// Time Complexity O(n.n!)
// Space Complexity O(n) (recursive calls take stack space)

void permute(string &input,int s, int e)
{
   if(s == e){
   cout << input << endl;
   return;
   }
  
   for(int i = s;i<=e;i++)
   {
      swap(input[s],input[i]);
      permute(input,s+1,e);
      swap(input[s],input[i]);
   }
}


// Doesn't print the permutations in lexicographical order
// Time Complexity O(n.n!)
// Space Complexity O(n) (recursive calls take stack space)

void permuteSortedHelper(vector<string> &result,string &input,int s, int e)
{
   if(s == e){
   result.emplace_back(input);
   return;
   }

   for(int i = s;i<=e;i++)
   {
      swap(input[s],input[i]);
      permuteSortedHelper(result,input,s+1,e);
      swap(input[s],input[i]);
   }
}

// Prints the result in lexicographically sorted order
// Time Complexity O(n.n!)
// Space Complexity O(n) (recursive calls take stack space)
void permuteSorted(string &input)
{
  cout << "permuteSorted" << endl;
  vector<string> result;
  permuteSortedHelper(result,input,0,input.size()-1);
  sort(result.begin(),result.end());
  for(int i = 0;i<result.size();i++)
  {
   cout << result[i] << " ";
  }    
  cout << endl;
}

int main()
{
  string input = "ABC";
  //permute(input,0,input.size()-1);
  permuteSorted(input);
}

