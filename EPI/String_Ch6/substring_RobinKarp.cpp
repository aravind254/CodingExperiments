#include<iostream>
#include<string>

using namespace std;

// Time Complexity : O(m + n)
// Robin Karp Algorithm

bool substr(string s,string sub)
{
 size_t sSize = s.size();
 size_t subSize = sub.size();
 if(sSize < subSize){
  return false;
 }
 int hS=0,hSub=0;
 int base = 10;
 int multiple = 1;

 for(int i = 0;i<subSize;i++)
 {
	hS = hS*base + s[i];
        hSub = hSub*base + sub[i];
        if(i){
        multiple *= base;
        }
 }
 cout << "hS = " << hS << endl;
 cout << "hSub = " << hSub << endl;
 cout << "multiple = " << multiple << endl;
 int j = subSize-1;
 bool found = false;
 
 while((hS != hSub) && (j<(sSize-1)))
 {
   j++;
   hS = (hS - (s[j-subSize]*multiple))*base + s[j];
   cout << "Recalculate hS = " << hS << endl;
   if(hS == hSub){ // There could be collision so we explicity compare the strings
   if(s.compare(j-(subSize-1),subSize,sub) != 0){
    continue;
   } else {
    found = true;
    break; 
   }
   } 
 }
 return found;
}

int main()
{
  //string s = "AAAGC";
  //string sub = "AGC";
  string s = "GACGCCA";
  string sub = "CGC";
  bool found = substr(s,sub);
  cout << "found = " << found << endl;
}
