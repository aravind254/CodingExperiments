#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;
enum class Turn
{
 ODD = 0,
 EVEN = 1
};

Turn turn = Turn::ODD;
mutex mx;
condition_variable cVar;
 
void oddThreadFunc()
{
   for(int i = 1;i<100;i+=2)
   {
      unique_lock<mutex> lock(mx);
      cout << "oddThreadFunc,i," << i << endl;
      cVar.wait(lock,[]{return (turn == Turn::ODD);});
      cout << "Odd Got Lock" << endl;
      cout << i << endl;
      turn = Turn::EVEN;
      lock.unlock();
      cout << "Odd Releases the lock" << endl;
      cVar.notify_one();
   }
}

void evenThreadFunc()
{
   for(int i = 2;i<=100;i+=2)
   {
      unique_lock<mutex> lock(mx);
      cout << "evenThreadFunc,i," << i << endl;
      cVar.wait(lock,[]{return (turn == Turn::EVEN);});
      cout << "Even Got Lock" << endl;
      cout << i << endl;
      turn = Turn::ODD;
      lock.unlock();
      cout << "Even Releases the lock" << endl;
      cVar.notify_one();
   }
} 


int main()
{
   thread t1(oddThreadFunc);
   thread t2(evenThreadFunc);
   t1.join();
   t2.join();
   cout << "exit main" << endl; 
}
