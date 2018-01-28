#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>

using namespace std;

class Semaphore
{
 public:
 Semaphore(int n)
 {
  max_resource = n;
 }

 ~Semaphore()
 {
   cout << "Destructor of Semaphore" << endl;
 }

 void Acquire()
 {
   unique_lock<mutex> lock(m_rCount);
   if(resCounter == max_resource)
   {
	cVar.wait(lock);
   }
   resCounter++;
 }
  
 void Release()
 {
   lock_guard<mutex> lock(m_rCount);
   if(resCounter > 0) { resCounter-- ; cVar.notify_all();}
 }

 private:
 int resCounter = 0;
 int max_resource = 0;
 condition_variable cVar;
 mutex m_rCount;
};

void tFunc(std::shared_ptr<Semaphore> semPtr)
{
  semPtr->Acquire();
  cout << "tFunc id"<< this_thread::get_id() << endl;
  cout << "Got Resource" << endl;
  semPtr->Release();
  cout << "Resource Released" << endl;
}

int main()
{
  std::shared_ptr<Semaphore> semPtr = make_shared<Semaphore>(2);
  thread t1(tFunc,semPtr);
  thread t2(tFunc,semPtr);
  thread t3(tFunc,semPtr);
  t1.join();
  cout << "thread 1 complete" << endl;
  t2.join();
  cout << "thread 2 complete" << endl;
  t3.join();
  cout << "thread 3 complete" << endl;
  cout << "Exit Main" << endl;
}
