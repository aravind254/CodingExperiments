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

Node* constructBSTFromPreOrderTravDataHelper(vector<int> &input,int lower_bound,int upper_bound,int &index);

// INORDER traversal of BST has more than one way to construct  a BST. So we cannot construct the correct BST just from Inorder Traversal data.
// POST/PRE ORDER traversal of BST can be used to construct the correct BST from just the traversal data.
Node* constructBSTFromPreOrderTravData(vector<int> &input)
{
  cout << "constructBSTFromPreOrderTravData " << endl;
  int index = 0;
  return constructBSTFromPreOrderTravDataHelper(input,std::numeric_limits<int>::min(),std::numeric_limits<int>::max(),index);
}

Node* constructBSTFromPreOrderTravDataHelper(vector<int> &input,int lower_bound,int upper_bound,int &index)
{
    int cur = input[index];
    if(index >= input.size())
    {
       return nullptr;
    }
  
    if((cur < lower_bound) || (cur > upper_bound))
    {
       return nullptr;
    }

    index++;
 
    Node* curNode    = new Node(cur);
    curNode->left   = constructBSTFromPreOrderTravDataHelper(input,lower_bound,cur,index);  
    curNode->right  = constructBSTFromPreOrderTravDataHelper(input,cur,upper_bound,index);
    return curNode;
}

void preOrder(Node* curNode)
{
    if(nullptr == curNode)
    {
      return;
    }
    cout << curNode->data << ",";
    preOrder(curNode->left);
    preOrder(curNode->right); 
}

Node* constructBSTFromPostOrderTravDataHelper(vector<int> &input,int lower_bound,int upper_bound,int &index);

Node* constructBSTFromPostOrderTravData(vector<int> &input)
{
  cout << "constructBSTFromPostOrderTravData" << endl;
  int index = input.size()-1;
  return constructBSTFromPostOrderTravDataHelper(input,std::numeric_limits<int>::min(),std::numeric_limits<int>::max(),index);
}

Node* constructBSTFromPostOrderTravDataHelper(vector<int> &input,int lower_bound,int upper_bound,int &index)
{
    int cur = input[index];
    if(index < 0)
    {
       return nullptr;
    }

    if((cur < lower_bound) || (cur > upper_bound))
    {
       return nullptr;
    }

    index--;


    Node* curNode    = new Node(cur);
    curNode->right  = constructBSTFromPostOrderTravDataHelper(input,cur,upper_bound,index);
    curNode->left   = constructBSTFromPostOrderTravDataHelper(input,lower_bound,cur,index);
    return curNode;
}

void postOrder(Node* curNode)
{
    if(nullptr == curNode)
    {
      return;
    }
    postOrder(curNode->left);
    postOrder(curNode->right);
    cout << curNode->data << ",";
}


int main()
{
 vector<int> preOrderInput = {10,8,6,9,15,12,20};
 vector<int> postOrderInput = {6,9,8,12,20,15,10};
 Node* root1 = constructBSTFromPreOrderTravData(preOrderInput);
 preOrder(root1);
 cout << endl;
 Node* root2 = constructBSTFromPostOrderTravData(postOrderInput);
 postOrder(root2);
 cout << endl;
 preOrder(root2);
}
 
