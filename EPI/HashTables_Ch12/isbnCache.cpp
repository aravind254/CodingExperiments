#include<iostream>
#include<string>
#include<list>
#include<unordered_map>

using namespace std;

class ISBNCache
{
public:
void insert(const string&);
bool lookup(const string&);
void remove(const string&);
string mru();
string lru();

private:
unordered_map<string,list<string>::iterator> stringMap;
list<string> lruList;
};

void ISBNCache::insert(const string& input)
{
   auto iter = stringMap.find(input);
   if(iter != stringMap.end())
   {
       lruList.erase(iter->second);
   }
   lruList.emplace_back(input);
   stringMap[input] = --lruList.end(); 
}

bool ISBNCache::lookup(const string& input)
{
   auto iter = stringMap.find(input);
   bool result = false;
   if(iter != stringMap.end())
   {
       result = true;   
       lruList.erase(iter->second);
       lruList.emplace_back(input);
       stringMap[input] = --lruList.end(); 
   }  
   return result;
}

void ISBNCache::remove(const string& input)
{
   auto iter = stringMap.find(input);
   if(iter != stringMap.end())
   { 
       lruList.erase(iter->second);
       stringMap.erase(iter);
   }  
}

string ISBNCache::mru()
{
   return lruList.back();
}

string ISBNCache::lru()
{
   return lruList.front();
} 



int main()
{
    ISBNCache myCache;
    myCache.insert("ISBN1");
    myCache.insert("ISBN2");
    myCache.insert("ISBN3");
    myCache.insert("ISBN4");
    myCache.lookup("ISBN2");
    myCache.remove("ISBN2");
    myCache.remove("ISBN4");
    myCache.lookup("ISBN1");
    if(!myCache.lookup("ISBN4"))
      cout << "cannot find ISBN4" << endl;
    cout << "mru," << myCache.mru() << endl;
    cout << "lru," << myCache.lru() << endl;
    
}
