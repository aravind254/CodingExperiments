#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>

/*
Writers get Starved in this approach
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
  unique_lock<mutex> rlock(rmx);
  rVar.wait(rlock,[]{return (rCount==0);});
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
 t1.join();
 t2.join();
 t3.join();
 w1.join();
 w2.join();
 return 0;
}
