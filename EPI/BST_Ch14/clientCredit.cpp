#include<iostream>
#include<unordered_map> // HASH based
#include<map> // BST based
#include<unordered_set>
#include<vector>

using namespace std;

class clientCredits
{
 public:
 void insert(const string &client,int credit);
 bool remove(const string &client);
 int lookUp(const string& client);
 void addAll(int credit);
 string max();

 private:
 unordered_map<string,int> clientCredit;  // HASH
 map<int,unordered_set<string>> creditClient; // BST
 int creditOffset = 0;
};


// TimeComplexity : O(h)
void clientCredits::insert(const string &client,int credit)
{
   remove(client);
   clientCredit[client] = credit - creditOffset;
   creditClient[credit - creditOffset].emplace(client); 
}

// TimeComplexity : O(h)
bool clientCredits::remove(const string &client)
{
  cout << "remove " << client << endl;
  auto clientIter = clientCredit.find(client);
  if(clientIter == clientCredit.end())
  {
    cout << "client not Present" << endl;
    return false;
  }
 
  auto creditIter = creditClient.find(clientIter->second);
  if(creditIter == creditClient.end())
  {
    cout << "Unexpected credit missing in creditClient BST" << endl;
    return false;
  }
   
  creditIter->second.erase(client); // remove client from unordered_set 
  
  if(creditIter->second.empty())
  {
    cout << "No more clients with credit, " << creditIter->first << " remove from BST" << endl;
    creditClient.erase(creditIter);
  }

  clientCredit.erase(clientIter); // remove client from HASH MAP

  return true;
}

// TimeComplexity : O(1)
int clientCredits::lookUp(const string& client)
{
   auto clientIter = clientCredit.find(client);
   if(clientIter == clientCredit.end())
   {
     cout << "Client, " << client << " not found" << endl;
     return -1;
   }
   return clientIter->second + creditOffset;
}

// TimeComplexity : O(1)
void clientCredits::addAll(int credit)
{
  cout << "addAll credit," << credit << endl;
  creditOffset += credit; 
}

// TimeComplexity : O(1)
string clientCredits::max()
{
  if(creditClient.empty() || creditClient.crbegin()->second.empty())
  {
    return " ";
  }
  auto maxClientIter = creditClient.crbegin()->second.cbegin();
  return *maxClientIter;
}

int main()
{
 clientCredits cObj;
 cObj.insert("A",7);
 cObj.insert("B",5);
 cObj.insert("C",1);
 cObj.insert("D",10);
 cObj.insert("E",12);
 cObj.insert("F",15);

 cout << "maxClient," <<  cObj.max() << endl;
 cout << "client A credit," << cObj.lookUp("A") << endl;
 cout << "client B credit," << cObj.lookUp("B") << endl;
 cout << "client C credit," << cObj.lookUp("C") << endl;
 cout << "client D credit," << cObj.lookUp("D") << endl;
 cout << "client E credit," << cObj.lookUp("E") << endl;
 cout << "client F credit," << cObj.lookUp("F") << endl;
 cout << "maxClient," <<  cObj.max() << endl;
 cObj.addAll(5);
 cObj.insert("G",2);
 cout << "client A credit," << cObj.lookUp("A") << endl;
 cout << "client B credit," << cObj.lookUp("B") << endl;
 cout << "client C credit," << cObj.lookUp("C") << endl;
 cout << "client D credit," << cObj.lookUp("D") << endl;
 cout << "client E credit," << cObj.lookUp("E") << endl;
 cout << "client F credit," << cObj.lookUp("F") << endl;
 cout << "client G credit," << cObj.lookUp("G") << endl;
 cObj.remove("F");
 cout << "maxClient," <<  cObj.max() << endl;

} 
