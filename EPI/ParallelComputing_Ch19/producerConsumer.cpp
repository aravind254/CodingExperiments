#include<iostream>
#include<condition_variable>
#include<mutex>
#include<queue>
#include<array>
#include<thread>

/*
Producer consumer problem with a bounded buffer, using arrays.
The issue here is that until all the elements are consumed, the producer cannot produce. 
This can be resolved by using i) a ring buffer ii) using a queue
*/

using namespace std;

#define mSize 5

array<int,mSize> buffer={-1};
condition_variable cVar;
mutex mx;
int pIndex=-1;// last produced index
int cIndex=-1;// last consumed index

void producer()
{

 /* 
 // To test how consumer handles spurious notifications
 while(1)
 {
   cVar.notify_all();
 }
 */
 
 while(1)
 {
  unique_lock<mutex> plock(mx);

  // If buffer is full wait
  cVar.wait(plock,[]{
   if(pIndex == (mSize-1)){
    cout << "Buffer is full.Wait" << endl;
  }
  return (pIndex == (mSize-1))?false:true;
  });
  int num = rand(); 
  pIndex++;
  cout << "pIndex," << pIndex << endl;
  buffer[pIndex] = num;
  cout << "notify all" << endl;
  cVar.notify_all();
 }
}

void consumer()
{

 /*  
 // To test how producer handles spurious notifications
 while(1)
 {
   cVar.notify_all();
 }
 */
 
 while(1)
 {
  unique_lock<mutex> clock(mx);
  
  // If buffer is empty wait
  cVar.wait(clock,[]{
   if(pIndex == -1){
    cout << "Buffer is full.Wait" << endl;
  }
  return (pIndex == -1)?false:true;
  });

  cIndex++;
  cout << "cIndex," << cIndex << endl;
  if(cIndex==pIndex){
  cIndex = -1; pIndex = -1;
  cout << "Consumed all" << endl;
  cVar.notify_all();
  }
 }
}

int main()
{
  thread p1(producer);
  thread c1(consumer);
  p1.join();
  c1.join();
}
