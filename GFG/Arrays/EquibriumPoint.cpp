//https://practice.geeksforgeeks.org/problems/equilibrium-point/0

#include<iostream>
#include<vector>
using namespace std;

int equilibriumPoint(const vector<int> &input)
{
 int s = 0 , e = input.size();
 int sum1 = 0, sum2 = 0;
 int ePt = -1;
 bool incSum1 = true;

 if(input.size() == 1)
 return 0; 

 while(s<e)
 {
   if(incSum1)
   {
      sum1 += input[s];
   }
   else
   {
      sum2 += input[e];
   }

   if(sum1 > sum2)
   {
     incSum1 = false;
     e--;
   }
   else if(sum1 < sum2)
   {
     incSum1 = true;
     s++;
   }
   else
   { 
     if((s+1) != e){
     ePt = s+1;
     }
     break;
   } 
 }
 
 return ePt;
}

int main()
{
  //vector<int> input = {1,3,5,2,2};
  vector<int> input = {3,3};
  cout << "Equilibrium Point " << equilibriumPoint(input) << endl;
}
