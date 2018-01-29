#include<iostream>
#include<list>

using namespace std;

class Queue
{
public:
void push(int val)
{
  data.push_back(val);
}

void pop()
{
 if(data.empty()){
 throw length_error("Queue is empty");
 }

 data.pop_front();
}

int front()
{
 if(data.empty()){
 throw length_error("Queue is empty");
 }

 return data.front();
}

bool empty()
{
  return data.empty();
}

private:
list<int> data;

};


int main()
{
  Queue myQueue;
  myQueue.push(5);
  myQueue.push(4);
  myQueue.push(3);
  myQueue.push(2);
  myQueue.push(1);
  while(!myQueue.empty())
  {
    cout << myQueue.front() << endl;
    myQueue.pop();
  }
}

