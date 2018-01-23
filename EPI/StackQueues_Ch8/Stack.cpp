#include<iostream>
#include<vector>

// Space Complexity is O(n). Space Complexity can further be improved by using an additional Stack and storing the (maximum,count) there
// Time Complexity is O(1) for push,pop,top,empty


class Stack
{
public:
int top();
void pop();
void push(int);
int max();
bool empty();

private:

struct stackElement{
int data;
int max;
};

std::vector<stackElement> element;
};

bool Stack::empty()
{
 return element.empty();
}

void Stack::push(int a)
{
   stackElement temp;
   temp.data = a;
   
   // Find max
   if(!element.empty())
   {
      int max = element.back().max;
      temp.max = (max>temp.data)?max:temp.data;
   }
   else
   {
      temp.max = temp.data;
   }

   cout << "Push data = " << temp.data << endl;
   cout << "Push max = " << temp.max << endl;
   
   element.emplace_back(temp);
}

void Stack::pop()
{
   if(element.empty())
   {
      throw length_error("Stack is empty");
   }

   element.pop_back();
}

int Stack::top()
{
   if(element.empty())
   {  
      throw length_error("Stack is empty");
   }
   
   return element.back().data;
}

int Stack::max()
{
  if(element.empty())
   {  
      throw length_error("Stack is empty");
   }
   
   return element.back().max;
}
