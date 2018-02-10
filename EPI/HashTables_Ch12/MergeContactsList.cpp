#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

// Define equal for the ContactsList
class ContactsList
{
public:
   bool operator==(const ContactsList& temp) const
   {
     return (unordered_set<string>(contacts.begin(),contacts.end()) == unordered_set<string>(temp.contacts.begin(),temp.contacts.end()));  
   };
   vector<string> contacts; // may contain duplicates
};

class HashContactsList
{
public:
  size_t operator()(const ContactsList& temp) const
  {
      unordered_set<string> uniqueSet(temp.contacts.begin(),temp.contacts.end());
      size_t hashResult = 0;
      for(auto it = uniqueSet.begin(); it != uniqueSet.end(); it++)
      { 
      	hashResult ^= hash<string>()(*it);
      }
      return hashResult;
  }
};

vector<ContactsList> MergeContactsList(const vector<ContactsList> &a)
{
  vector<ContactsList> result;
  unordered_set<ContactsList,HashContactsList>  uniqueContacts(a.begin(),a.end());
  result = {uniqueContacts.begin(),uniqueContacts.end()};
  return result;
}

int main()
{
  ContactsList a,b,c,d;
  a.contacts.emplace_back("James");
  a.contacts.emplace_back("Wade");
  a.contacts.emplace_back("Tristan");
  b.contacts.emplace_back("Krover");
  c.contacts.emplace_back("James");
  c.contacts.emplace_back("Wade");
  c.contacts.emplace_back("Tristan");
  d.contacts.emplace_back("James");
  d.contacts.emplace_back("Wade");
  d.contacts.emplace_back("Smith");
  vector<ContactsList> cList;
  cList.emplace_back(a);
  cList.emplace_back(b);
  cList.emplace_back(c);
  cList.emplace_back(d);

  for(int i = 0;i<cList.size();i++)
  {
    cout << "ContactsList #i,"<<i<<endl;
    for(int j = 0;j<cList[i].contacts.size();j++)
    {
       cout << cList[i].contacts[j] << ",";
    }
    cout << endl;
  }

  vector<ContactsList>  result = MergeContactsList(cList); 

  cout << "*****AFTER MERGE*****" << endl;

  for(int i = 0;i<result.size();i++)
  {
    cout << "ContactsList #i,"<<i<<endl;
    for(int j = 0;j<result[i].contacts.size();j++)
    {
       cout << result[i].contacts[j] << ",";
    }
    cout << endl;
  }

  

}
