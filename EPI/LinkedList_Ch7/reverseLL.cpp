#include "LL.h"
using namespace std;

typedef std::shared_ptr<ListNode<int>> ln;

void reverseLL(LL<int> &list,int s, int f)
{
  cout << "reverseLL s," << s << ",f," << f << endl;
  ln curNode = list.head;
  ln nodeS = nullptr, tail = list.head;
  int nSCounter = 1;
  if(s>=f){
  cout << "s should be < f" << endl;
  return;
  }

  // Find nodeS
  while((nSCounter < s) && (curNode != nullptr)) // List starts with index 1
  {
     nodeS = curNode;
     curNode=curNode->next;
     nSCounter++;	
  }

  if(nodeS){
  cout << "nSCounter," << nSCounter << endl;
  cout << "nodeS data" << nodeS->data << endl;
  }

  // Cases where StartNode is at the end or outside the list
  if(curNode == nullptr){
   if((nSCounter -1) == s){
   cout<< "start Node is at end of list. NOOP" << endl;
   return;
   }
   else{
   cout<< "start Node outide the list. NOOP" << endl;
   return;
   } 
  }

  // tail of the result list
  if(nodeS){
  tail = nodeS->next;
  }

  int curCounter = nSCounter; 
  ln temp=nullptr,prev=nullptr,nextN = nullptr;

  while((curCounter <= f) && (curNode))
  {
    temp = curNode->next;
    curNode->next = prev;
    prev = curNode;
    curNode = temp;
    curCounter++;
  }

  tail->next  = curNode;


  if(nodeS){
  nodeS->next = prev;
  list.head = nodeS;
  }
  else{
  list.head = prev;
  }
  
}

int main()
{
 LL<int> myList;
 myList.add(1);
 myList.add(2);
 myList.add(3);
 myList.add(4);
 myList.add(5);
 reverseLL(myList,3,1);
 myList.print();
}
