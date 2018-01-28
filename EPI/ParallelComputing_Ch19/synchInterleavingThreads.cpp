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
      if(turn == Turn::EVEN){
       cVar.wait(lock);
      }
      else
      {
          cout << i << endl;
          turn = Turn::EVEN;
          cVar.notify_one();
      }
   }
}

void evenThreadFunc()
{
   for(int i = 2;i<=100;i+=2)
   {
      unique_lock<mutex> lock(mx);
      if(turn == Turn::ODD){
       cVar.wait(lock);
      }
      else
      {
          cout << i << endl;
          turn = Turn::ODD;
          cVar.notify_one();
      }
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
