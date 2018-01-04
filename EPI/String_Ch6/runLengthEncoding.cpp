#include<iostream>
#include<string>

using namespace std;

string rleEncode(string s)
{
 size_t sSize = s.size();
 int count = 1;
 string r;
 for(int i = 0;i<sSize;i++)
 {
   if(s[i] == s[i+1]){
   count++;
   }
   else {
   r += to_string(count);
   r += s[i];
   count = 1;
   }
 }
 return r;
}

string rleDecode(string s)
{
 size_t sSize = s.size();
 int count = 0;
 string r;
 for(int i = 0;i<sSize;i++)
 {
   if(isdigit(s[i]))
   {
     count = count*10 + (s[i] - '0');
   }
   else if(isalpha(s[i])) {
   for(int j=0;j<count;j++)
   {
     r += s[i];
   } 
   count = 0;
   }
 }
 return r;
}

int main()
{
  string s1 = "aaaabcccddd";
  cout << rleEncode(s1) << endl;
  string s2 = "10a1b3c3d";
  cout << rleDecode(s2) << endl;
}
