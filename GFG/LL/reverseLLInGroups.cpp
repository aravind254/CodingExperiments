#include<iostream>
#include<vector>

using namespace std;

struct Node
{
 Node(int val){
 data = val; 
 next = nullptr; 
 };
 int data;
 Node* next;
};

struct LLInfo
{
  Node* head;
  Node* tail;
};

class LL
{
 public:
 void add(int);
 void reverseLLInGroups(int);
 void printLL();
 
 private:
 LLInfo* reverseLL(Node*);
 Node* head = nullptr;
 Node* tail = nullptr;
};

void LL::printLL()
{
  Node* cur = head;
  while(cur != nullptr)
  {
    cout << cur->data << ",";
    cur = cur->next;
  }
  cout << endl;
}

void LL::add(int data)
{
  if(nullptr == head)
  {
     head = new Node(data);
     tail = head;
     return;
  }

  if(tail)
  {
    tail->next = new Node(data);
    tail = tail->next;
  } 
}



LLInfo* LL::reverseLL(Node* cur)
{
  Node* prev = nullptr;
  Node* temp = nullptr;
  LLInfo* llInfo = new LLInfo();
  llInfo->head = nullptr;
  llInfo->tail = cur;
  cout << "reverseLL " << endl;

  while(cur != nullptr)
  {
     cout << cur->data  << endl;
     temp = cur->next;
     cur->next = prev;
     prev = cur;
     cur = temp;
  }
  cout << "local head," << prev->data  << endl;
  cout << "local tail," << llInfo->tail->data  << endl;
  llInfo->head = prev;
  cout << "reverseLL done" << endl;
  return llInfo;
}


// Recursive solution can be found here: https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
void LL::reverseLLInGroups(int k)
{
  cout << "reverseLLInGroups, k = " << k << endl;
  Node* cur = head;
  Node* prevTail = head;
  Node* temp = nullptr;
  Node* curHead = head;
  int c = 0;
  bool firstOp = true;
  LLInfo *llInfo;
  
  while(cur != nullptr)
  {
     c++;
     if(c == k)
     {
       cout << "count reached" << endl;
       c = 0;
       temp = cur->next;
       cur->next = nullptr;
       if(firstOp)
       {
          firstOp = false;
	  llInfo = reverseLL(head);
          head = llInfo->head;
          printLL();
          prevTail = llInfo->tail;
       }
       else
       {
         llInfo = reverseLL(curHead);
         prevTail->next = llInfo->head;
         prevTail = llInfo->tail;
       }
       cur = temp;
       curHead = cur;
     }
     else
     {
        cur = cur->next;
     }
  }
 
  llInfo = reverseLL(curHead);
  prevTail->next = llInfo->head;
  tail = llInfo->tail;
}

int main()
{
  LL llObj;
  int k = 3;
  llObj.add(1);
  llObj.add(2);
  llObj.add(3);
  llObj.add(4);
  llObj.add(5);
  llObj.add(6);
  llObj.add(7);
  llObj.add(8);
  llObj.printLL();
  llObj.reverseLLInGroups(3);
  llObj.printLL();
}
