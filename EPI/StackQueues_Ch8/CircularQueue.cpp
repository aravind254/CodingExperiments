#include<iostream>
#include<vector>

using namespace std;

class CQueue
{ 
 public:
 CQueue(int n)
 {
   mSize = n;
   data.reserve(mSize);
   cout << "Capacity of Queue is " << data.capacity() << endl;
   cout << "Size of Queue is " << data.size() << endl;
 }


 // If reached max capacity of Queue, increase QueueSize
 void pushSpecial(int val)
 {
   if(curSize == data.capacity()){
   cout << "Reached Queue capacity.Resize Queue" << endl;
   rotate(data.begin(),data.begin()+head,data.end());
   head = 0;
   tail = mSize;
   data.resize(mSize * kScaleFactor);
   }
   cout << "Push val,"<< val <<",at " << tail << endl;   
   data[tail] = val;
   tail=(tail+1)%(data.capacity());; 
   curSize++;
 }
 
 void push(int val)
 {
   if(curSize == mSize){
   throw length_error("Queue is full");
   }
   cout << "Push val,"<< val <<",at " << tail << endl;   
   data[tail] = val;
   tail=(tail+1)%(data.capacity()); 
   curSize++;
 }
 
 void pop()
 {
    if(!curSize){
    throw length_error("Queue is empty");
    }
    cout << "Pop val,"<< data[head] <<",from " << head << endl;   
    head=(head+1)%(data.capacity());
    curSize--;
 }

 int front()
 {
    if(!curSize){
    throw length_error("Queue is empty");
    }
    return data[head];
 }

 bool empty()
 {
    return (curSize==0);
 }


 private:
 vector<int> data;
 int curSize = 0;
 int mSize = 0;
 int head = 0,tail = 0;
 const int kScaleFactor = 2;
};

int main()
{
   CQueue myQueue(5);
   myQueue.pushSpecial(10);
   myQueue.pushSpecial(9);
   myQueue.pushSpecial(8);
   myQueue.pushSpecial(7);
   myQueue.pushSpecial(6);
   myQueue.pushSpecial(5);
   myQueue.pushSpecial(4);
   myQueue.pushSpecial(3);
   myQueue.pushSpecial(2);
   myQueue.pushSpecial(1);
   myQueue.pop();
   myQueue.pop();
   myQueue.pop();
}


