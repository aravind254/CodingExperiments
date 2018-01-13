#include "LL.h"
using namespace std;

typedef std::shared_ptr<ListNode<int>> ln;


// Find start of cycle without finding lenght of the cycle
// fast & slow pointers may meet at any node in the cycle
ln testCyclicityNoLength(const LL<int> &list)
{
  ln fPtr = list.head,sPtr = list.head;
 while(fPtr)
 {
   fPtr=fPtr->next;
   if(!fPtr){
    return nullptr;
   }
   fPtr=fPtr->next;
   if(!fPtr){
    return nullptr;
   }
  sPtr = sPtr->next;
  if(fPtr == sPtr){
  cout << "Found a cycle" << endl;

  sPtr = list.head;
  while(sPtr != fPtr)
  {
    fPtr = fPtr->next;
    sPtr = sPtr->next;
  }
  cout << "start of cycle is " << fPtr->data << endl;
  return fPtr;
   }
}
  return nullptr;
}

ln testCyclicity(const LL<int> &list)
{
 ln fPtr = list.head,sPtr = list.head;
 while(fPtr)
 {
   fPtr=fPtr->next;
   if(!fPtr){
    return nullptr;
   } 
   fPtr=fPtr->next;
   if(!fPtr){
    return nullptr;
   }
  sPtr = sPtr->next;
  if(fPtr == sPtr){
  cout << "Found a cycle" << endl;

  // Cycle length
  fPtr = fPtr->next;
  int cyclen = 1;
  while(fPtr != sPtr)
  {
   fPtr = fPtr->next;
   cyclen++;
  }
  cout << "Cycle length = " << cyclen << endl;

  // Start of Cycle
  ln iter1 = list.head;
  ln iter2 = list.head;
  while(cyclen)
  {
    iter1 = iter1->next;
    --cyclen;
  }

  while(iter1 != iter2)
  {
     iter1 = iter1->next;
     iter2 = iter2->next;
  }
  
  cout << "Found Start of Cycle at node = " << iter1->data << endl;
  return iter1;
  } 
 }

 return nullptr; 
}



int main()
{
 LL<int> myList;
 myList.add(1);
 myList.add(2);
 myList.add(3);
 myList.add(4);
 myList.add(5);


 // Form a cycle
 ln curNode = myList.head;
 while(curNode->next){
 curNode = curNode->next;
 }
 curNode->next = (myList.head)->next;
 
  


 //myList.print();
 ln node = testCyclicity(myList);
 if(!node){
  cout << "Cycle not found" << endl;
 }

 testCyclicityNoLength(myList);
  
}
