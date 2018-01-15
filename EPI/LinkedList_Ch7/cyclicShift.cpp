#include "LL.h"
using namespace std;


typedef std::shared_ptr<ListNode<int>> ln;


// Time Complexity : O(n)
// Space Complexity : O(1)
bool cyclicShift(LL<int> &list,int k)
{
 cout << "cyclicShift k = " << k << endl;
 ln curNode = list.head;
 if(!curNode){
  return false;
 }

 ln tail = nullptr;
 int len = 1;

 // Find length of the list and tail Node
 while(curNode->next)
 {
   len++;
   curNode = curNode->next;
 }
 tail = curNode;
  
 int cycleParam = len - k;
 if(len == k)
 {
   cout << "Cyclic Shift will result in NOOP" << endl;
   return true;
 }

 curNode = list.head;
 cycleParam--;
 
 while(cycleParam) 
 {
   curNode = curNode->next;
   cycleParam--;
 }

 ln temp = curNode->next;
 curNode->next = nullptr;
 tail->next = list.head;
 list.head = temp;
 return true;
}

int main()
{
 LL<int> myList;
 myList.add(1);
 myList.add(2);
 myList.add(3);
 myList.add(4);
 myList.add(5);
 myList.print();
 cyclicShift(myList,5);
 myList.print();
}
