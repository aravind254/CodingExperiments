#include<iostream>

using namespace std;

class Dog 
{
 public:
 void test() { cout << "Dog" << endl;}
 virtual void test1() { cout << "test1" << endl;} // If this function is not defined, dynamic_cast will not work as the Class Dog is not polymorphic
};

class YellowDog:public Dog
{
 public:
 void test() { cout << "YellowDog" << endl;}
};

class PurpleDog:public Dog
{
 public:
 void test() { cout << "PurpleDog" << endl;}
};

int main()
{
  Dog dogObj;
  YellowDog yellowDogObj;
  PurpleDog purpleDogObj; 
  
  Dog* yDPtr = &yellowDogObj;
  Dog* pDPtr = &purpleDogObj;

  // Static cast
  Dog dogObj1       = static_cast<Dog>(yellowDogObj); // YellowDog is a Dog,  Object Slicing
  //YellowDog dogObj2 = static_cast<YellowDog>(dogObj); // Dog may or may not be YellowDog, so compilation fails
  Dog* temp = static_cast<YellowDog*>(pDPtr);   // Doesn't fail compilation, but can cause unexpected behavior
  if(temp) {cout << "temp is not null when using static_cast" << endl;}
 
  // Dynamic cast
  //Dog dogObj2       = dynamic_cast<Dog>(yellowDogObj); //Compiler Error, Dog is not a reference or Pointer
  Dog *dogObj2 =  dynamic_cast<Dog*>(&yellowDogObj); // Object Slicing
  dogObj2->test();
  YellowDog *dogObj3 = dynamic_cast<YellowDog*>(&dogObj); // Dog may or may not be YellowDog, so compilation fails
  if(!dogObj3)
  {
   cout << "dogObj3 is null" << endl;
  }
  Dog* temp1 = dynamic_cast<YellowDog*>(pDPtr);   // Doesn't fail compilation, but can cause unexpected behavior
  if(!temp1) {cout << "temp1 is null when using dynamic_cast" << endl;}

  // reinterpreset cast
  // YellowDog dogObj20 = reinterpret_cast<YellowDog>(dogObj);  //Compiler Error: reinterpret_cast from 'Dog' to 'YellowDog' is not allowed.// non-pointers are not allowed.
  YellowDog *yDogPtr = reinterpret_cast<YellowDog*>(pDPtr); //  reinterpret_cast doesn't do type check
  if(yDogPtr) { cout << "yDogPtr is not null when using reinterpret_cast" << endl;}

 // const cast
 // const_cast is used to remove the const-ness from references and pointers that ultimately refer to something that is not const
 // You are not allowed to const_cast variables that are actually const 
 int i = 0;
 const int& ref = i;
 const int* ptr = &i;
 //ref = 4; // Compiler Error: cannot assign to variable 'ref' with const-qualified type 'const int &'

 const_cast<int&>(ref) = 3;
 *const_cast<int*>(ptr) = 3;

 const int i1 = 0;
 const int& ref1 = i1;
 const int* ptr1 = &i1;
 //ref1 = 4; // Compiler Error: cannot assign to variable 'ref' with const-qualified type 'const int &'

 // The below code will compile but behavior is undefined.
 const_cast<int&>(ref1) = 3;
 *const_cast<int*>(ptr1) = 3;
 
}  
  

