#include "LL.h"
using namespace std;

typedef std::shared_ptr<ListNode<int>> ln;


ln hasCycle(const LL<int> &list, ln &endCycle)
{
   ln fPtr = list.head,sPtr = list.head;
   ln cycleStart = nullptr;
   endCycle = nullptr;

   while(fPtr && fPtr->next)
   {
     fPtr = fPtr->next->next;
     sPtr = sPtr->next;
     if(sPtr == fPtr)
     {
        cout << "Cycle detected" << endl;
        // Find start of cycle
        sPtr = list.head;
	while(sPtr != fPtr)
        {
		fPtr = fPtr->next;
		sPtr = sPtr->next;
        }
        cycleStart = fPtr;
        fPtr = list.head;

        // Find end of list 
        while(fPtr->next != cycleStart)
        {
            fPtr = fPtr->next;
        }
        endCycle = fPtr;   
        return cycleStart;
     }
   }
   return nullptr;
}


bool testOverlappingListsCycle(LL<int>& l1, const LL<int>& l2)
{
  ln ecl1 = nullptr,scl1 = nullptr, ecl2 = nullptr, scl2 = nullptr;
  scl1 = hasCycle(l1,ecl1);
  scl2 = hasCycle(l2,ecl2);
  if(!scl1 && !scl2)
  {
     cout << "Both lists don't have cycle. They may overlap" << endl;
     // need to check for overlap
  }
  else if((!scl1 && scl2) || (scl1 && !scl2))
  {
     cout << "Only one of the list has cycle. So no overlap" << endl;
  }
  else if(scl1 && scl2)
  {
     cout << "Both list has cycle. May/May not overlap" << endl;
     cout << "ecl1 = " << ecl1->data << endl;
     cout << "ecl2 = " << ecl2->data << endl;
     if(ecl1 == ecl2)
     {
        cout << "Lists Overlap" << endl;
	
	// Find overlapping node
        int len1 = 1,len2 = 1;
        ln iter = l1.head;

	while(iter != ecl1)
        {
	   iter=iter->next; 
 	   len1++;
        }
        iter = l2.head;
	while(iter != ecl2)
        {
	   iter=iter->next; 
 	   len2++;
        }
        int tlen = abs(len1 - len2);
        iter = len1 > len2 ? l1.head:l2.head;
        ln iter2 =  len1 > len2 ? l2.head:l1.head; 
        while(tlen)
        {
           iter = iter->next;
           tlen--;
        }
        
        while(iter != iter2)
	{
		iter = iter->next;
		iter2 = iter2->next;
        }
        cout << "Overlapping node is " << iter->data << endl;
        return true; 
         
     }
     else
     {
	cout << "Lists don't overlap" << endl;
     }
  } 
  
  return false; 
}


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
 
 ln temp1 = myList.head;
 while(temp1->next)
 {
   temp1 = temp1->next;
 }
 temp1->next = (myList.head);

 // Print the lists
 //myList.print();
 //myList2.print();

 // Check if lists overlap
 testOverlappingListsCycle(myList,myList2);

}
