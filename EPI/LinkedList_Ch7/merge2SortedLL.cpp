#include "LL.h"
#include<memory>
using namespace std;

// Time Complexity : O(n + m), n is size of l1, m is size of l2
// Space Compelxity : O(1), no additional space is taken to create new list

std::unique_ptr<LL<int>> merge2SortedLL(LL<int> &l1,LL<int> &l2)
{
  std::unique_ptr<LL<int>> r= std::make_unique<LL<int>>();
  std::shared_ptr<ListNode<int>> curl1 = l1.head;
  std::shared_ptr<ListNode<int>> curl2 = l2.head;
  std::shared_ptr<ListNode<int>> temp;
  while(curl1 && curl2)
  {
    if(curl1->data <= curl2->data){
     temp = curl1;
     l1.head = curl1->next;  
     curl1=curl1->next;
     temp->next = nullptr;
     r->add(temp);
    }
    else{
     temp = curl2;
     l2.head = curl2->next;  
     curl2=curl2->next;
     temp->next = nullptr;
     r->add(temp);
    } 
  }
  
 if(curl1) {
  r->add(curl1);
  l1.head = nullptr;
 }
 else if(curl2){
  r->add(curl2);
  l2.head = nullptr;
 }

 return r;
}


int main()
{
 LL<int> myList;
 myList.add(1);
 myList.add(3);
 myList.add(5);
 myList.add(7);
 myList.add(8);
 myList.add(9);
 myList.print();

 LL<int> myList2;
 myList2.add(2);
 myList2.add(4);
 myList2.add(6);
 myList2.print();

 std::unique_ptr<LL<int>> myList3 = merge2SortedLL(myList,myList2); 
 myList3->print();
 myList.print();
 myList2.print();
}
