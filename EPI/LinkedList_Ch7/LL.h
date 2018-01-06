#include<iostream>
#include<memory> // shared_ptr

#pragma once

// Basic Linked List Node
template <typename T>
class ListNode // Keeping all elements as public for simplicity
{
   public:
   T data;
   std::shared_ptr<ListNode<T>> next; // shared_ptr is needed since 2 nodes might point to one node
   ListNode(T elem) { data = elem;} 
   ~ListNode() { std::cout << "element destructor" << data << std::endl;}
};

template <typename T>
class LL
{
  public:
  bool add(T elem);
  bool findElement(T elem);
  bool Delete(T elem);
  bool insertElementAfterPos(int pos,T elem);
  void print();

  private:
  std::shared_ptr<ListNode<T>> head;
};

#include "LL.cpp"
