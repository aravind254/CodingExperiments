#include<iostream>
#include<memory>
#include<queue>
#include<stack>

using namespace std;


template <typename T>
struct TreeNode
{
  T data;
  std::unique_ptr<TreeNode<T>> left=nullptr,right=nullptr;
};

template <typename T>
class Tree
{
public:
void add(T val);
void remove(T val);
int height();
int depthOfNode(T val);
bool isBalanced();
bool isPerfectBinaryTree();
void inOrder();
void preOrder();
void postOrder();
void inOrderIterative();
void preOrderIterative();
void postOrderIterative();
bool isSymmetric();

std::unique_ptr<TreeNode<T>> root=nullptr; // For the sake of simplicity making this info public

private:
int  heightHelper(const std::unique_ptr<TreeNode<T>>&,int);
void inOrderHelper(const std::unique_ptr<TreeNode<T>>&);
void preOrderHelper(const std::unique_ptr<TreeNode<T>>&);
void postOrderHelper(const std::unique_ptr<TreeNode<T>>&);
};

// Level order traversal to find an empty place and add the element
template <typename T>
void Tree<T>::add(T val)
{
  if(!root){
  cout << "root is empty. Add val,<< val << at root" << endl ;
  root = make_unique<TreeNode<T>>();
  root->data = val ;
  return;
  }
  queue<TreeNode<T>*> myQ;
  myQ.emplace(root.get());
  TreeNode<T>* temp = nullptr;
   
  while(!myQ.empty())
  {
    temp = myQ.front();
    if(temp->left == nullptr){
     temp->left =  make_unique<TreeNode<T>>();
     temp->left->data = val;
     return;
    }
    else if(temp->right == nullptr){
     temp->right =  make_unique<TreeNode<T>>();
     temp->right->data = val;
     return;
    }
    
   myQ.emplace(temp->left.get());
   myQ.emplace(temp->right.get());
   myQ.pop();
  }
}

template <typename T>
void Tree<T>::inOrder()
{
 cout << "inOrder" << endl;
 inOrderHelper(root);
 cout << endl;
}

template <typename T>
void Tree<T>::inOrderHelper(const unique_ptr<TreeNode<T>>& curNode)
{
    if(!curNode) {return;}
     
    inOrderHelper(curNode->left);
    cout << curNode->data << " "; 
    inOrderHelper(curNode->right);
}

template <typename T>
void Tree<T>::inOrderIterative()
{
    stack<TreeNode<T>*> myStack;
    myStack.emplace(root.get());
    TreeNode<T>* temp = nullptr; 
    cout << "inOrderIterative" << endl;
    while(!myStack.empty())
    {
       temp = myStack.top(); 
       if(temp)
       {
           myStack.emplace(temp->left.get());
       }
       else
       {
           myStack.pop();
           if(myStack.empty()) { break;}
           temp = myStack.top();
           myStack.pop();
           cout << temp->data << " ";
           myStack.emplace(temp->right.get());
       } 
    }
   cout << endl;

}

template <typename T>
void Tree<T>::preOrder()
{
  cout << "preOrder" << endl;
  preOrderHelper(root);
  cout << endl;
}

template <typename T>
void Tree<T>::preOrderHelper(const unique_ptr<TreeNode<T>>& curNode)
{
    if(!curNode) {return;}
     
    cout << curNode->data << " ";
    preOrderHelper(curNode->left);
    preOrderHelper(curNode->right);
}

template <typename T>
void Tree<T>::preOrderIterative()
{   
    cout << "preOrderIterative" << endl;
    stack<TreeNode<T>*> myStack;
    myStack.emplace(root.get());
    TreeNode<T>* temp = nullptr;  
    while(!myStack.empty())
    {  
       temp = myStack.top();
       if(temp)
       {
           cout << temp->data << " ";   
           myStack.emplace(temp->left.get());
       }
       else
       {   
           myStack.pop();
           if(myStack.empty()) { break;}
           temp = myStack.top();
           myStack.pop();
           myStack.emplace(temp->right.get());
       }
    }
   cout << endl;

}

template <typename T>
void Tree<T>::postOrder()
{
  cout << "postOrder" << endl;
  postOrderHelper(root);
  cout << endl;
}

template <typename T>
void Tree<T>::postOrderHelper(const unique_ptr<TreeNode<T>>& curNode)
{
    if(!curNode) {return;}
     
    postOrderHelper(curNode->left);
    postOrderHelper(curNode->right);
    cout << curNode->data << " ";
}

template <typename T>
void Tree<T>::postOrderIterative()
{  
    cout << "postOrderIterative" << endl;

}

template <typename T>
void Tree<T>::remove(T val)
{
}

template <typename T>
int Tree<T>::height()
{
   int ht  =  heightHelper(root,-1);
   cout << "height = " << ht << endl;
   return ht;
}

template <typename T>
int Tree<T>::heightHelper(const std::unique_ptr<TreeNode<T>> &curNode,int depth)
{
 if(!curNode) { return depth;}
 depth++;
 int ld = heightHelper(curNode->left,depth);
 int rd = heightHelper(curNode->right,depth);
 return ld>rd?ld:rd;
}

template <typename T>
int Tree<T>::depthOfNode(T val)
{

}

template <typename T>
bool Tree<T>::isBalanced()
{

}

template <typename T>
bool Tree<T>::isPerfectBinaryTree()
{

}

template <typename T>
bool Tree<T>::isSymmetric()
{

}


int main()
{
 Tree<int> myTree;
 myTree.add(5);
 myTree.add(4);
 myTree.add(3);
 myTree.add(2);
 myTree.add(1);
 myTree.add(6);
 myTree.add(7);
 myTree.add(8);
 myTree.inOrder();
 myTree.inOrderIterative();
 myTree.preOrder();
 myTree.preOrderIterative();
 myTree.postOrder();
 myTree.height();
}
