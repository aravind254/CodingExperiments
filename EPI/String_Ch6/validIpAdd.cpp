#include<iostream>
#include<string>
#include "arrUtil.h"

using namespace std;


bool isValidPart(const string &part)
{
 int val = stoi(part);
 
 // 00,01 etc are not allowed, but 0 is allowed 
 if((part[0] == '0') && (part.size() > 1))
 return false;
 
 if((val<=255) && (val >= 0))
  return true;

 return false;
}

vector<string> validIpAdd(const string &mip)
{
  size_t mSize = mip.size();
  vector<string> R;
  string temp;
  int p1 = 0;

  for(int p2 = p1+1;p2<=p1+3;p2++)
    { 
     string pa1 = mip.substr(p1,p2-p1);
     cout << "pa1 = " << pa1 << endl;
     if(!isValidPart(pa1)) continue;
 
     for(int p3 = p2+1;p3<=p2+3;p3++)
     {
        string pa2 = mip.substr(p2,p3-p2);
        cout << "pa2 = " << pa2 << endl;
        if(!isValidPart(pa2)) continue;
        for(int p4 = p3+1;p4<mSize;p4++)
	{
          string pa3 = mip.substr(p3,p4-p3);
          cout << "pa3 = " << pa3 << endl;
          if(!isValidPart(pa3)) continue;
          string pa4 = mip.substr(p4,mSize-p4);
          cout << "pa4 = " << pa4 << endl;
          if(!isValidPart(pa4)) continue;

	  temp = pa1+"."+ pa2 + "." + pa3 + "." + pa4;
  	  cout << "Found Valid " << temp << endl;
          R.emplace_back(temp);
	}
     }
    }
 return R;
}

int main()
{
  string mip = "192016811";
  vector<string> R = validIpAdd(mip);
  printVector(R);
  return 0;
}
