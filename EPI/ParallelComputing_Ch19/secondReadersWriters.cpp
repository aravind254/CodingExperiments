#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>


/*
Readers can get starved in this approach
*/

using namespace std;

condition_variable rVar,wVar;
mutex rmx,wmx;
unsigned int rCount = 0;

void readerFunc()
{
 int count = 5;
 while(count)
 {
  {
   lock_guard<mutex> wlock(wmx);
  }
  {
   lock_guard<mutex> lock(rmx);
   rCount++;
   cout << "Reader Work thread_id = " << this_thread::get_id() <<  "count=" << count << endl;
  }
  
  cout << "***RW***" << endl;

  {
   lock_guard<mutex> lock(rmx);
   rCount--;
   rVar.notify_one();
   }
  count--;
 }
}

void writerFunc()
{
 int count = 5;
 while(count)
 { 
  unique_lock<mutex> wlock(wmx);
  while(1)
  {
  unique_lock<mutex> rlock(rmx);
  if(rCount){
  cout <<  "**Wcheck**Reader Count Not 0" << endl;
  rVar.wait(rlock);
  }
  else{
  cout << "Reader count reached 0" << endl;
  break;
  } 
  }

  cout << "Writer Work thread_id = " << this_thread::get_id() <<  "count = " << count << endl;
  count--;
 }  
}

int main()
{
 thread t1(readerFunc);
 thread t2(readerFunc);
 thread t3(readerFunc);
 thread w1(writerFunc);
 thread w2(writerFunc);
 thread w3(writerFunc);
 thread w4(writerFunc);
 thread w5(writerFunc);
 thread w6(writerFunc);
 thread w7(writerFunc);
 thread w8(writerFunc);
 t1.join();
 t2.join();
 t3.join();
 w1.join();
 w2.join();
 w3.join();
 w4.join();
 w5.join();
 w6.join();
 w7.join();
 w8.join();
 return 0;
}
