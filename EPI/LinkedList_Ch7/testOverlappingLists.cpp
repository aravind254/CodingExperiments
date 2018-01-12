#include "LL.h"
using namespace std;

typedef std::shared_ptr<ListNode<int>> ln;


// Time Complexity : O(n + m), n size of l1, m size of l2
// Space Complexity : O(1)
bool testOverlappingLists(LL<int>& l1, const LL<int>& l2)
{
  ln iter1 = l1.head,iter2 = l2.head;
  // Find tail for both lists. If the tails are same then they should be overlapping.
  while(iter1 && (iter1->next))
  {
   iter1= iter1->next; 
  }

  while(iter2 && (iter2->next))
  {
   iter2= iter2->next; 
  }

  return (iter1==iter2);
}

// Time Complexity : O(n + m), n size of l1, m size of l2
// Space Complexity : O(1)
ln findOverlappingNode(LL<int>& l1, const LL<int>& l2)
{
  ln iter1 = l1.head,iter2 = l2.head;
  int s1 = 0, s2 = 0;
  while(iter1)
  {
   s1++;
   iter1= iter1->next; 
  }

  while(iter2)
  {
   s2++;
   iter2= iter2->next; 
  }

  iter1 = s1>s2?l1.head:l2.head; 
  iter2 = s1>s2?l2.head:l1.head;
  int travlength = abs(s1-s2);
  
  while(travlength)
  {
    iter1=iter1->next;
    travlength--;
  }
 
  while(iter1 != iter2)
  {
     iter1 = iter1->next;
     iter2 = iter2->next;
  }

  if(iter1 && (iter1 == iter2))
  {
    return iter1;
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

 LL<int> myList2;
 myList2.add(6);
 myList2.add(7);
 myList2.add(8);


 // Make the lists overlap
 ln temp = myList2.head;
 while(temp->next)
 {
   temp = temp->next;
 }
 temp->next = (myList.head)->next->next;

 // Print the lists
 myList.print();
 myList2.print();

 // Check if lists overlap
 if(testOverlappingLists(myList,myList2))
 {
   cout << "Lists overlap" << endl;
 }
 else
 {
   cout << "Lists do not overlap" << endl;
 }

 ln oNode = findOverlappingNode(myList,myList2);
 if(oNode)
 {
   cout << "Lists overlap at node=" << oNode->data << endl;
 }
 else
 {
   cout << "Lists do not overlap" << endl;
 }
}
