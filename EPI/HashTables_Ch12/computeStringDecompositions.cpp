#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;


// N being sentence length
// n is number of words in words vector
// m is the length of each word in the words vector
// TimeComplexity O(Nnm) 
// SpaceComplexity O(nm)

vector<string> computeStringDecompositions(const vector<string> &words, const string &sentence)
{
  unordered_map<string,int> wordMap;
  vector<string> result;

  int wlength = words[0].size();
  for(string s: words)
  {
    wordMap[s]++;
  }

  for(int i = 0;i<sentence.size();i++)
  {
     unordered_map<string,int> tempMap = wordMap;
     int temp = i;
     bool exit = false;
     do
     {
     string curStr = sentence.substr(temp,wlength);
     auto curIter = tempMap.find(curStr);
     if(curIter != tempMap.end()) 
     {
        curIter->second--;
        if(!curIter->second)
        {
            tempMap.erase(curStr);
        }
        temp += 3;
     }
     else
     {
        exit = true;
     }
    }while(!exit && !tempMap.empty());
  
    if(tempMap.empty())
    {
       string tempStr = sentence.substr(i,temp-i);
       result.emplace_back(tempStr);
    }   
  }
  return result; 
}

int main()
{
 string sentence = "abcdefghijkldefjklghijklghidef";
 vector<string> words = {"def","ghi","jkl"};
 vector<string> result = computeStringDecompositions(words,sentence); 
 cout << "RESULT" << endl;
 for(string s : result)
 {
   cout << s << endl;
 }
 return 0;
}
