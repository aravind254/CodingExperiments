#include<iostream>
#include<condition_variable>
#include<mutex>
#include<queue>
#include<array>
#include<thread>

/*
Producer consumer problem with a bounded ring buffer, using arrays.
*/

using namespace std;

#define mSize 5

array<int,mSize> buffer={-1};
condition_variable cVar;
mutex mx;
int pIndex=0;// next produce index
int cIndex=0;// next consume index

void producer()
{


 /*
 // To test how consumer handles spurious wakeups
 while(1)
 {
   cVar.notify_all();
 }
 */ 
  
 while(1)
 {
  unique_lock<mutex> plock(mx);

  // If buffer is full wait. 
  // Wait with predicate is critical here. If there are spurious notify for conditional variable, we should block until the predicate returns true.
  cVar.wait(plock,[]{
  if((pIndex+1)%mSize == cIndex){ cout << "Buffer is Full" << endl;}
   return ((pIndex+1)%mSize == cIndex)?false:true;
   });
  int num = rand(); 
  cout << "pIndex," << pIndex << endl;
  buffer[pIndex] = num;
  pIndex = (pIndex+1)%mSize;
  cout << "notify all" << endl;
  cVar.notify_all();
 }
}

void consumer()
{

 /* 
 // To test how producer handles spurious wakeups
 while(1)
 { 
   cVar.notify_all();
 }*/

 while(1)
 {
  unique_lock<mutex> clock(mx);
  
  // If buffer is empty wait
  cVar.wait(clock,[]{
  if(pIndex == cIndex){ cout << "Buffer is empty" << endl;}
  return ((pIndex == cIndex)? false:true);
  });
  cout << "cIndex," << cIndex << endl;
  cIndex = (cIndex+1)%mSize;
  cVar.notify_all();
 }
}

int main()
{
  thread p1(producer);
  thread c1(consumer);
  thread c2(consumer);
  p1.join();
  c1.join();
  c2.join();
}
