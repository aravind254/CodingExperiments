#include<iostream>
#include<thread>

using namespace std;

std::mutex mu;

void thread1Func(int a)
{
 mu.lock();
 cout << "a = " << a << endl;
 mu.unlock();
 for(int i = 0;i<50;i++)
 {
  mu.lock();
  cout << "Thread i = " << i << endl;
  mu.unlock();
 }

}

int main()
{
 std::thread t1(thread1Func,5);
 for(int i = 0;i<50;i++)
 {
  mu.lock();
  cout << "Main Thread i = " << i << endl;
  mu.unlock();
 }
 t1.join();
}
