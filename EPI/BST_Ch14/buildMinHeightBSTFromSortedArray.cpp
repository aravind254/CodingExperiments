#include<iostream>
#include<vector>

using namespace std;

class Node
{
  public:
  Node(int val) {data = val;}
  Node *left = nullptr;
  Node *right = nullptr;
  int data;
};

// Time Complexity : O(n)
// Space Complexity : O(n)
Node* buildMinHeightBSTFromSortedArray(vector<int> &input,int start, int end)
{
   if(start > end)
   { 
      return nullptr;
   }

   int mid = start + (end - start)/2; // is always going to ceil.
   
   Node *cur = new Node(input[mid]);
   cur->left = buildMinHeightBSTFromSortedArray(input,start,mid-1);
   cur->right = buildMinHeightBSTFromSortedArray(input,mid+1,end);
   return cur; 
}

void inOrder(Node *cur)
{
   if(nullptr == cur) return;
   inOrder(cur->left);
   cout << cur->data << ",";
   inOrder(cur->right);
}

void preOrder(Node *cur)
{
   if(nullptr == cur) return;
   cout << cur->data << ",";
   preOrder(cur->left);
   preOrder(cur->right);
}


int main()
{
  vector<int> input = {2,3,5,7,11,13,17,19,23};
  Node *root = buildMinHeightBSTFromSortedArray(input,0,input.size()-1);
  cout << "InOrder" << endl;
  inOrder(root);
  cout << endl;

  cout << "preOrder" << endl;
  preOrder(root);
  cout << endl;
}
