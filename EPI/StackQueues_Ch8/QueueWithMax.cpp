#include<iostream>
#include<deque>
#include<queue>

using namespace std;

class Queue
{
 public:

  void enqueue(int val)
  {
    cout << "enqueue " << val << endl;
    Q.push(val);

    while(!dq.empty() && (val > dq.back()))
    {
       dq.pop_back();
    }
    dq.emplace_back(val); 
   
  }

  void dequeue()
  {
     if(Q.empty())
     {
        cout << "Q is empty" << endl;
        return;
     }

     if(Q.front() == dq.front())
     {
        dq.pop_front(); 
     }
     cout << "Q pop," << Q.front() << endl;
     Q.pop(); 
  }

  bool empty()
  {
     return Q.empty();
  }

  int max() 
  {
     return dq.front();
  }

 private:
 queue<int> Q;
 deque<int> dq;
};


int main()
{
  Queue myQ;
  myQ.enqueue(10);
  myQ.enqueue(9);
  myQ.enqueue(8);
  myQ.enqueue(7);
  myQ.enqueue(11);
  myQ.enqueue(5);
  myQ.enqueue(4);
  myQ.enqueue(3);
  myQ.enqueue(2);
  myQ.enqueue(1);
  cout << "max," <<myQ.max() << endl;
  myQ.dequeue();
  myQ.dequeue();
  myQ.dequeue();
  myQ.dequeue();
  myQ.dequeue();
  cout << "max," <<myQ.max() << endl;
}
