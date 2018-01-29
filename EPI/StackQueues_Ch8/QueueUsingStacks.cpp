#include<iostream>
#include<stack>


using namespace std;

class Queue
{
public:
void enqueue(int val)
{
  cout << "enqueue val,"<<val<< endl;
  s1.push(val);
}

void dequeue()
{
  if(!s2.empty()){
  cout << "s2 not empty. dequeue " << s2.top() << endl;
  s2.pop();
  return;
  }
  
  if(s1.empty())
  {
    cout << "Queue is empty" << endl;
    return;
  }

  while(!s1.empty()){
  s2.push(s1.top());
  s1.pop(); 
  }
  cout << "dequeue " << s2.top() << endl;
  s2.pop();
}


bool empty()
{
   return (s1.empty() && s2.empty());
}

private:
stack<int> s1,s2;
};

int main()
{
 Queue myQueue;
 myQueue.enqueue(5);
 myQueue.enqueue(4);
 myQueue.enqueue(3);
 myQueue.enqueue(2);
 myQueue.enqueue(1);
 myQueue.dequeue();
 myQueue.dequeue();
 myQueue.enqueue(6);
 myQueue.enqueue(7);
 myQueue.enqueue(8);
 while(!myQueue.empty())
 {
   myQueue.dequeue();
 }
 
}


