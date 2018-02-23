#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


bool testCollatzConjecture(int n)
{
  unordered_set<int> verifiedSet; // contains only odd numbers.
  int largestVerifiedNumber = 2;
  if((n == 1) || (n == 2)) return true;

  verifiedSet.emplace(1);

  for(int i = 3; i<=n;i+=2)
  {  
    unordered_set<int> tempSet;
    long temp = i;
    
    while(!verifiedSet.count(temp) && (temp > largestVerifiedNumber))
    {
            if(tempSet.count(temp)) // same number found again in the tempSet, will lead to infinite loop exit
            {
               return false;  
            }

            tempSet.emplace(temp);

	    if(temp%2) // odd
	    {
	       temp = temp*3 + 1;
               if(temp < i) //
               {
                  throw overflow_error("OverFlow detected for " + to_string(i)); 
               } 
	    }
	    else
	    {
               temp = temp/2;
	    }
    }
    verifiedSet.emplace(i); 
  }

  cout << "verifiedSet" << endl;
  for(auto val : verifiedSet)
  {
   cout << val << ",";
  }
  cout << endl;

  return true;
}

int main()
{
 int val = 32000767;
 bool result = testCollatzConjecture(val);
 cout << "result for " << val << "," << result << endl;
 return 0;
}
