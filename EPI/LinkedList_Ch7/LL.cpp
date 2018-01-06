#include "LL.h"

using namespace std;

template <typename T>
bool LL<T>::add(T elem)
{
 if(!head) {
   shared_ptr<ListNode<T>> newNode = make_shared<ListNode<T>>(elem);
   newNode->next = nullptr;
   head = newNode;
   return true;
  }
 
 shared_ptr<ListNode<T>> currNode = head;
 while(currNode->next != nullptr)
 {
   currNode = currNode->next;
 }

 shared_ptr<ListNode<T>> newNode = make_shared<ListNode<T>>(elem);
 currNode->next = newNode;
 newNode->next = nullptr;
  
 return true;
}

template <typename T>
bool LL<T>::findElement(T elem)
{
 if(!head) { return false;}

 shared_ptr<ListNode<T>> currNode = head;
 while(currNode)
 {
   if(currNode->data == elem){
   return true;
   }
   currNode = currNode->next;
 }

 return false;
}

template <typename T>
bool LL<T>::Delete(T elem)
{
 if(!head) { return false;}

 if(head->data == elem){
 head = head->next;
 return true;
 }

 shared_ptr<ListNode<T>> currNode = head;
 shared_ptr<ListNode<T>> prevNode = nullptr;
 
 while(currNode)
 { 
   if(currNode->data == elem)
   {
     prevNode->next = currNode->next; // Node to be deleted will be deleted automatically since there are no more references to it. // Assuming no cyclicity
     return true;
   }

  prevNode = currNode;
  currNode = currNode->next;
 }
 return false;
}

template <typename T>
bool LL<T>::insertElementAfterPos(int pos,T elem)
{
 if(!head) { return false;}
 shared_ptr<ListNode<T>> currNode = head;
 int posCount = 0;
 while(currNode)
 {
   if(pos == posCount){
   shared_ptr<ListNode<T>> newNode = make_shared<ListNode<T>>(elem);
   newNode->next = currNode->next;
   currNode->next = newNode;
   return true;
   }
   currNode = currNode->next;
   posCount++;
 }
 return false; 
}

template <typename T>
void LL<T>::print()
{
  if(!head) { return;}
  shared_ptr<ListNode<T>> currNode = head;
  
   while(currNode)
   {
      cout << currNode->data << " ";
      currNode = currNode->next;
   }
   cout << endl;
}
