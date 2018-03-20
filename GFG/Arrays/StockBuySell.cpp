//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
//https://www.geeksforgeeks.org/stock-buy-sell/

#include<iostream>
#include<vector>

using namespace std;

struct Interval
{
  int buy=-1;
  int sell=-1;
};


// Buy, Sell allowed only once
Interval maximizeProfitOnce(const vector<int> &input)
{
 Interval result;
 int curProfit = 0;
 int maxProfitSoFar = 0;
 int iSize = input.size();
 int b = 0;

 for(int s = 1;s<iSize;s++)
 {
   int tempP = input[s] - input[b];
   if(tempP > curProfit)
   {
       curProfit = tempP;
       if((s == iSize-1) && (curProfit>0))
       {
           if(curProfit > maxProfitSoFar)
	   {  
		 maxProfitSoFar = curProfit;
		 result.buy = b;
		 result.sell = s;
	   }
       }
   }
   else if(input[s] < input[b])
   {
      if(curProfit > maxProfitSoFar)
      {
         maxProfitSoFar = curProfit;
         result.buy = b;
         result.sell = s-1; 
       }
       b = s;
       curProfit = 0;
   } 
 }
 return result;
}


// Buy, Sell can be done as many times as needed
vector<Interval> maximizeProfit(const vector<int> &input)
{
  vector<Interval> result;
  int curProfit = 0;
  int iSize = input.size();
  int b = 0;
  
  for(int s = 1;s<iSize;s++)
  {
     int tempP = input[s] - input[b];
     if(tempP > curProfit)
     {
        curProfit = tempP;
        if((s == iSize-1) && (curProfit>0))  
        {
            Interval temp;
	    temp.buy = b;
            temp.sell = s;
            result.emplace_back(temp);
        }
     }
     else if(input[s] < input[b])
     {
       cout << "ins s," << s << endl;
       if(curProfit > 0){
       Interval temp;
       temp.buy = b;
       temp.sell = s-1;
       result.emplace_back(temp);
       }
       b = s;
       curProfit = 0; 
     } 
  }
  return result;
}
 
void printInterval(vector<Interval> &input)
{
  for(auto s: input)
  {
    cout << "("<< s.buy << "," << s.sell << ")" << ",";
  }
  cout << endl;
}

int main()
{
  vector<int> input1 = {100, 180, 260, 310, 40, 535, 695};
  vector<int> input2 = {23,13,25,29,33,19,34,45,65,67};
  vector<Interval> result1 = maximizeProfit(input1);
  vector<Interval> result2 = maximizeProfit(input2);
  printInterval(result1);
  printInterval(result2);
  Interval result3 = maximizeProfitOnce(input1);
  Interval result4 = maximizeProfitOnce(input2);
  cout << "("<< result3.buy << "," << result3.sell << ")" << "," << endl;
  cout << "("<< result4.buy << "," << result4.sell << ")" << "," << endl;
}
