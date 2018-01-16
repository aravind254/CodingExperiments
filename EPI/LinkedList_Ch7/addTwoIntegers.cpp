#include "LL.h"
#include<cmath>
using namespace std;


typedef std::shared_ptr<ListNode<int>> ln;
void addIntegers(const LL<int> &l1,const LL<int> &l2,LL<int> &r)
{
 int carry = 0;
 ln iter1 = l1.head,iter2=l2.head,iter3 = r.head;
 while(iter1 || iter2 || carry)
 {
    int temp = iter1?iter1->data:0;
    temp += iter2?iter2->data:0;
    temp += carry;

    carry = ceil(temp/10);
    temp = temp%10; 

    r.add(temp);
    iter1 = iter1?iter1->next:nullptr;
    iter2 = iter2?iter2->next:nullptr;
 }
}


int main()
{
 LL<int> myList1;
 myList1.add(1);
 myList1.add(2);
 myList1.print();
 LL<int> myList2;
 myList2.add(9);
 myList2.add(9);
 myList2.add(9);
 myList2.print();
 LL<int> result;
 addIntegers(myList1,myList2,result);
 result.print();
}
