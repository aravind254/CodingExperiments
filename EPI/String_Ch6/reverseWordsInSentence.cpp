#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//"Hello Good Morning" should be transformed to "Morning Good Hello"
// Time Complexity : O(n)
// Space Compexity : O(n)
void reverseWordsInSentence(const string &sentence)
{
  string newSentence;
  string tmpWord;
  int count = 0;
  cout << "reverseWordsInSentence" << endl;

  for(int i = sentence.size();i>=0;i--)
  {
    if(sentence[i] != ' ')
    {
     tmpWord.push_back(sentence[i]);
     continue;
    }
    reverse(tmpWord.begin(),tmpWord.end());
    newSentence.append(tmpWord);
    newSentence.push_back(' ');
    tmpWord.erase();
  }
  reverse(tmpWord.begin(),tmpWord.end());
  newSentence.append(tmpWord);

  cout << "sentence = " << sentence << endl;
  cout << "newSentence = " << newSentence << endl;
}

// InPlace
// Time Complexity : O(n)
// Space Compexity : O(1)
void reverseWordsInSentenceInPlace(string &sentence)
{
 int sI=0,eI=sentence.size()-1;
 int sSize = sentence.size(),ind = 0,sInd=0;
 cout << "reverseWordsInSentenceInPlace" << endl;
 
 reverse(sentence.begin(),sentence.end());
 
 while(ind < sentence.size())
 {
   if(sentence[ind] != ' ')
   {
        ind++;
	continue;
   }
   reverse(sentence.begin()+sInd,sentence.begin()+ind);
   sInd = ind + 1;
   ind++;
 }
 reverse(sentence.begin()+sInd,sentence.begin()+ind);

  cout << "sentence = " << sentence << endl;
}




int main()
{
 string sentence = "Hello Good Morning";
 reverseWordsInSentence(sentence);
 reverseWordsInSentenceInPlace(sentence);
}
