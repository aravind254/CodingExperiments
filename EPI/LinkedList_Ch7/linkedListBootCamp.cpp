#include "LL.h"
using namespace std;

int main()
{
 LL<int> myList;
 myList.add(1);
 myList.add(2);
 myList.add(3);
 myList.add(4);
 myList.add(5);
 myList.insertElementAfterPos(1,7);
 myList.print();
 cout << "Element 7 " << myList.findElement(7) << endl;;
 myList.Delete(5);
}
