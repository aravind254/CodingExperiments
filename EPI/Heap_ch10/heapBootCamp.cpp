#include<iostream>
#include<queue> // priority_queue
#include<functional> // greater

using namespace std;

bool compare(int a,int b)
{
  return (a > b);
}

int main()
{
  vector<int> a = {4,1,5,10,20};
  int myInts[] = {4,1,5,10,20};

  // Default internal container object used by priority Q is vector.
  // So the following 2 definitions would be the same. 
  priority_queue<int> Q1(a[0],a[4]);// not sure why the last element is getting included here. It should be [first,last)
  priority_queue<int,vector<int>> Q2(a[0],a[4]);// not sure why the last element is getting included here. It should be [first,last)
  priority_queue<int> Q3(myInts,myInts+4); // the last element is not included in this range.

  // When giving compare function, like greater here, we need to specify the container
  priority_queue<int,vector<int>,greater<int>> Q4(myInts,myInts+5); // Use greater if min heap is needed, by defaults it uses less ( will be max heap)

  // When giving compare function, like compare here, we need to specify the container
  priority_queue<int,vector<int>,function<bool(int,int)>> Q5(myInts,myInts+5,compare); 

  cout << Q1.top() << endl;
  cout << "Q1 size="<< Q1.size() << endl;
  cout << Q2.top() << endl;
  cout << "Q2 size="<< Q2.size() << endl;
  cout << Q3.top() << endl;
  cout << "Q3 size="<< Q3.size() << endl;
  cout << Q4.top() << endl;
  cout << "Q4 size="<< Q4.size() << endl;
  cout << Q5.top() << endl;
  cout << "Q5 size="<< Q5.size() << endl;

  priority_queue<int> Q6;
  Q6.push(1);
  cout << "Q6 size="<< Q6.size() << endl;
}
