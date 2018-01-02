#include<iostream>
#include<string>

using namespace std;

// Time Complexity : O(n*2^n)
string lookAndSay(int n)
{
  string result,temp;
  char tempChar;
  int count = 0;
  result = "1";

  for(int i = 2;i<=n;i++)
  {
     count = 0; 
     temp = "";
     tempChar = '\0';

     for(int j = 0; j < result.size();j++)
     {
	if(result[j] == tempChar){
        count++;
        }
	else if(count == 0){
        count++;
        tempChar = result[j];
        }
	else{
        temp.push_back(count + '0');// ortemp += to_string(count);
        temp.push_back(tempChar);
        tempChar = result[j];
        count = 1;
        }
     }
     temp.push_back(count + '0');
     temp.push_back(tempChar);
     result = temp;
  }
  return result;
}

int main()
{
 int n = 6;
 string result = lookAndSay(n);
 cout << "n = " << n << endl;
 cout << "result = " << result << endl;
}
