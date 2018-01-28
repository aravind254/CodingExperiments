#include<iostream>
#include<condition_variable>
#include<mutex>
#include<queue>
#include<thread>

/*
Producer consumer problem using Queue
*/

using namespace std;

#define mSize 5

queue<int> buffer;
condition_variable cVar;
mutex mx;

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
   if(buffer.size() == mSize){
    cout << "*****Buffer is full.Wait*****" << endl;
    return false;
  }
  return true;
  });
  int num = rand(); 
  cout << "produced num,"<< num<< endl;
  buffer.emplace(num);
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
   if(buffer.empty()){
    cout << "*****Buffer is empty.Wait*****" << endl;
    return false;
  }
  return true;
  });
  cout << "Consume num,"<< buffer.front() << endl;
  buffer.pop();
  cVar.notify_all();
 }
}

int main()
{
  thread p1(producer);
  thread c1(consumer);
  p1.join();
  c1.join();
}
