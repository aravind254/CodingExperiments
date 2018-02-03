#include<iostream>
#include<vector>
#include<string>
#include<queue>


using namespace std;

bool compareSize(string a,string b)
{
  return (a.size() > b.size());
}

void kLargestStrings(const vector<string> &stringStream,int k)
{
   vector<string> result;
   priority_queue<string,vector<string>,function<bool(string,string)>> minHeap(compareSize);
   int index = 0;
   string temp;
   while(index < stringStream.size())
   {
      temp = stringStream[index];

     if(minHeap.size() < k)
     {
         cout << "Insert " << temp << endl; 
         minHeap.emplace(temp);
     }
     else if(minHeap.top().size() < temp.size())
     {
        cout << "Remove " << minHeap.top() << " to replace with " << temp << endl; 
        minHeap.pop();
        minHeap.emplace(temp);
     }
     else
     {
        cout << "Dont add " << temp << " to heap" << endl;
     }
     index++;
   }


   while(!minHeap.empty())
   {
       cout << minHeap.top() << "," << minHeap.top().size() <<  endl;
       minHeap.pop();
   }

}

int main()
{
  vector<string> myStream = {{"Apple"},{"Orange"},{"Bananna"},{"Pomegranate"},{"Pear"},{"Grapes"}};
  kLargestStrings(myStream,3);
}
