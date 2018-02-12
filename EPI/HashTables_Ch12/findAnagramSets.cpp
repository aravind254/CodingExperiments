#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;


/*
TBD: Inspite of different anagrams generating same hash key, they are stored in different places of the hashMap
*/
class Key
{
  public:
  string val;
  bool operator==(const Key& temp) const
  {
     //cout << "==" << endl; 
     return (temp.val == val);
  }
};

class customHash
{
  public:
  size_t operator()(const Key &input) const
  {
 	size_t result=0;
        int mult = 999;
        for(char c : input.val)
        {
             result += c*mult; // Hash function for a case where order of alphabets in the string doesn't matter
        }
        cout << "customHash input," << input.val << ",result," << result << endl;
        return result;  
  }
};

vector<vector<string>> FindAnagramSets(const vector<string>& input)
{
   unordered_map<Key,vector<string>,customHash> myMap;
   unordered_map<Key,vector<string>,customHash>::hasher fn = myMap.hash_function();
   Key temp;
   temp.val = "mal";
   Key temp1;
   temp1.val = "lam";

   cout << fn(temp) << "," << fn(temp1) << endl;
   for(int i = 0;i<input.size();i++)
   {
       //cout << input[i] << endl;
       temp.val = input[i];
       if(myMap.find(temp) != myMap.end())
       {
          cout << input[i] << " already present" << endl;
       }
       //cout << "before emplace_back" << endl;
       myMap[temp].emplace_back(input[i]);
   }

   cout << "Bucket count " << myMap.bucket_count() << endl;
   int n =  myMap.bucket_count();

   for (unsigned i=0; i<n; ++i) {
    std::cout << "bucket #" << i << " contains: ";
    for (auto it = myMap.begin(i); it!=myMap.end(i); ++it)
      {
      std::cout << "[" << it->first.val << "]" << "**" ;
      for(int j = 0;i < it->second.size();j++)
      {
         cout << it->second[j] << "," ;

      }
       
       }
     cout << endl;

  }


   // Print MyMap
   for(auto it = myMap.begin();it!=myMap.end();it++)
   {
      cout << it->first.val << "," << "bucket," << myMap.bucket(it->first) << "***";
      for(int i = 0;i < it->second.size();i++)
      {
         cout << it->second[i] << "," ;

      }
      cout << endl;
   }
   
   vector<vector<string>> result;
   
   for(auto it = myMap.begin();it!=myMap.end();it++)
   {
       //cout << "first " << it->first.val << endl;
       if(it->second.size() > 1)
       {
           cout << "Found " << endl;
           result.emplace_back(it->second); // inserting an entire vector here
       }
   }
   return result;
}

int main()
{
   vector<string> input = {"debitcard","elvis","silent","badcredit","lives","freedom","listen","levis","money"};
   vector<vector<string>> result = FindAnagramSets(input);
   cout << "result size," << result.size() << endl;
   for(auto v1: result)
   {
    cout << "***SET***" << " ";
    for (auto st : v1)
    {
        cout << st << " " ;
    }
    cout << "endl";
   }
}
