#include<iostream>
using namespace std;

class AFriend;
class A
{
public:
int a =10;
friend class AFriend; // This line can be under public/private/protected access
friend void AFriendMethod(A&); // This line can be under public/private/protected access

protected:
int b = 11; 

private:
int c = 12; 
};

class AFriend
{
  public:
  void testA(A& obj)
  { 
    cout << "AFriend::testA b," << obj.b << ",c," << obj.c << ",a," << obj.a << endl;
  };
};


void AFriendMethod(A& obj)
{
    cout << "AFriendMethod b," << obj.b << ",c," << obj.c << ",a," << obj.a << endl;
} 

int main()
{
  A aObj;
  AFriend aFriendObj;
  aFriendObj.testA(aObj);
  AFriendMethod(aObj);
}
