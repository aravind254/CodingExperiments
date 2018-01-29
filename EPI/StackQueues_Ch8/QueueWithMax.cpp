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

     if(Q.top() == dq.back())
     {
        dq.pop_back(); 
     }
     Q.pop(); 
  }

  bool empty()
  {
     return Q.empty();
  }

  int max() 
  {
     dq.front();
  }

 private:
 queue<int> Q;
 deque<int> dq;
}


int main()
{
  
   
}
