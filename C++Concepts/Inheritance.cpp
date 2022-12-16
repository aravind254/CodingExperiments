#include<iostream>
using namespace std;

class Animal
{
 public:
 int a=10, b=13;
 void M1() { cout << "Animal::M1" << a << endl;}
 void M2() { cout << "Animal::M2" << a << endl;}
 void M3() { cout << "Animal::M3" << b << endl;}
};

class Dog: public Animal
{
 public:
 int c = 20, b = 22;
 void M1() { cout << "Dog::M1" << a << endl;} // Finds the a from the base class
 void M2() { cout << "Dog::M2" << b << endl;} // b in the local scope hides the b in the base class
 void M4() { cout << "Dog::M4" << b << endl;}
};

int main()
{
  Animal animObj;
  animObj.M1(); // Calls Animal::M1
  animObj.M2(); // Calls Animal::M2

  cout << "Method Hiding" << endl;
  Dog dogObj;
  dogObj.M1(); // Calls Dog::M1,M1 in dog class hides M1 in Animal class
  dogObj.M2(); // Calls Dog::M2,M2 in dog class hides M2 in Animal class
  dogObj.M3(); // Calls Animal::M3

  cout << "Object Slicing " << endl;
  Animal anObj = dogObj; // Object Slicing
  anObj.M1();
  anObj.M2();
  anObj.M3();
  //anObj.M4(); // compilation Error.

  //Dog dObj = static_cast<Dog>(animObj); // Doesn't satisfy isA relationship, so will throw compilation error
  //Dog dObj = animObj; // Doesn't satisfy isA relationship, so will throw compilation error
}
