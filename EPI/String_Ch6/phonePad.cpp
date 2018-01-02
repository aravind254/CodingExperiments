#include<iostream>
#include<string>
#include<vector>
#include "arrUtil.h"

using namespace std;


vector<string> phonePad = {"0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void numberToWord(const string &num,vector<string> &result,int curIndex)
{
     cout << "numberToWord curIndex= " << curIndex << endl;
     if(curIndex < 0)
     {
	cout << "Base condition return" << endl;
	return;
     }

     numberToWord(num,result,curIndex-1);
     int charIndex = num[curIndex]-'0';
  
     string cur = phonePad[charIndex];
     size_t curSize = cur.size();
     size_t resSize = result.size();

     cout << "numberToWord curIndex= " << curIndex << endl;
     cout << "numberToWord curSize= " << curSize << endl;
     cout << "numberToWord resSize= " << resSize << endl;
     cout << "numberToWord cur= " << cur << endl;
     cout << "numberToWord charIndex= " << charIndex << endl;

     for(int j = 0;j<curSize;j++)
     {
         if(!resSize)
         {
		string temp(1,cur[j]);
		result.push_back(temp);
         }
	 else
         {
		// Copy existing result
		for(int k = j*resSize;k<((j+1)*resSize) && j<(curSize-1);k++)
		{
		   result.push_back(result[k]);
		}
		
		for(int i = j*resSize;i<((j+1)*resSize);i++)
		{
		  result[i].push_back(cur[j]);
		}
	 }
     }
}


int main()
{
  string num = "2276696";
  vector<string> result;
  numberToWord(num,result,num.size()-1);
  printVector(result);
  cout << "Result Size = " << result.size() << endl;
}
