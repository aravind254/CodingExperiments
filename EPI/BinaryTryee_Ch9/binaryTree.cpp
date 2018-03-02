#include<iostream>
#include<memory>
#include<queue>
#include<stack>

using namespace std;

/*
Depth of a Node n : Is the number of nodes from root to  node n, not included node n.
Height of a Binary Tree : Is the maximum depth of any node in that tree
Height balanced Binary Tree: A tree is height balanced if the differnence in height between the left and right subtree is atmost 1.
Complete Binary Tree: Is a tree where every level except the last is completely filled and the nodes are populated from left to right.
Perfect Binary Tree: Is a tree where all the parents have atleast 2 children and all the leaves are at same level.
Full Binary Tree: Is a tree where every node has 2 children ( excluding the leaves)
*/

template <typename T>
struct TreeNode
{
  T data;
  std::unique_ptr<TreeNode<T>> left=nullptr,right=nullptr;
};

template <typename T>
struct Status
{
 int numNodes;
 TreeNode<T>* ancestor;
};

struct bStatus
{
 int depth;
 bool balanced;
};

template <typename T>
class Tree
{
public:
void add(T val);
void addToLeft(T val);
void addToright(T val);
void remove(T val);
int height();
int depthOfNode(T val);
bool isheightBalanced();
bool isPerfectBinaryTree();
void inOrder();
void preOrder();
void postOrder();
void inOrderIterative();
void preOrderIterative();
void postOrderIterative();
bool isSymmetric();
bool isSumPresentFromRootToLeaf(int targetSum);
TreeNode<T>* LCA(T data1, T data2);
vector<vector<T>> levelOrderTraversal();
int sumRootToLeafBinary(); // Only applicable if the nodes of a tree are 0 or 1 and root is the MSB 

std::unique_ptr<TreeNode<T>> root=nullptr; // For the sake of simplicity making this info public

private:
int  heightHelper(const std::unique_ptr<TreeNode<T>>&,int);
void inOrderHelper(const std::unique_ptr<TreeNode<T>>&);
void preOrderHelper(const std::unique_ptr<TreeNode<T>>&);
void postOrderHelper(const std::unique_ptr<TreeNode<T>>&);
bool isSymmetricHelper(TreeNode<T>* subTree0, TreeNode<T> *subTree1);
Status<T> LCAHelper(const std::unique_ptr<TreeNode<T>> &root, T data1, T data2);
bStatus isheightBalancedHelper(const std::unique_ptr<TreeNode<T>> &curNode,int depth);
int sumRootToLeafBinaryHelper(const std::unique_ptr<TreeNode<T>> &curNode, int sum);
bool isSumPresentFromRootToLeafHelper(const std::unique_ptr<TreeNode<T>> &curNode, int targetSum, int prevSum);
};

template <typename T>
bool Tree<T>::isSumPresentFromRootToLeaf(int targetSum)
{
  return isSumPresentFromRootToLeafHelper(root,targetSum,0);
}

template <typename T>
bool Tree<T>::isSumPresentFromRootToLeafHelper(const std::unique_ptr<TreeNode<T>> &curNode, int targetSum, int prevSum)
{
  if(curNode == nullptr) { return false; }
  
  int tempSum = prevSum + curNode->data;
 
  // Leaf Node
  if((curNode->left == nullptr) && (curNode->right == nullptr))
  {
      return (tempSum == targetSum);
  }

  if(isSumPresentFromRootToLeafHelper(curNode->left,targetSum,tempSum))
  {
  return true; 
  }
 
  if(isSumPresentFromRootToLeafHelper(curNode->right,targetSum,tempSum))
  {
  return true;
  }

  return false;
}

template <typename T>
int Tree<T>::sumRootToLeafBinary()
{
  return sumRootToLeafBinaryHelper(root,0);
}

template <typename T>
int Tree<T>::sumRootToLeafBinaryHelper(const std::unique_ptr<TreeNode<T>> &curNode, int sum)
{
  int tempSum = 0;
  if(!curNode) return 0;

  tempSum = sum*2 + curNode->data;
 
  if(!curNode->left && !curNode->right) // Leaf Node
  {
     return tempSum;
  }
 
  int leftSum = sumRootToLeafBinaryHelper(curNode->left,tempSum);  
  int rightSum = sumRootToLeafBinaryHelper(curNode->right,tempSum);  
  return (leftSum + rightSum);
}

// Similar to Post Order Traversal
// Time Complexity : O(n)
// Space Complexity : O(h), height of the tree

template <typename T>
TreeNode<T>* Tree<T>::LCA(T data1, T data2)
{
 Status<T> result = LCAHelper(root,data1,data2);
 return result.ancestor;
}


// LCA is similar to Post Order Traversal
template <typename T>
Status<T> Tree<T>::LCAHelper(const std::unique_ptr<TreeNode<T>> &root, T data1, T data2)
{
  Status<T> curStatus;
  curStatus.numNodes = 0;
  curStatus.ancestor = nullptr;

  if(!root) { return curStatus;}
  
  
  Status<T> leftStatus = LCAHelper(root->left, data1, data2);
  if(leftStatus.numNodes == 2)
  {
    return leftStatus;
  }

  Status<T> rightStatus = LCAHelper(root->right, data1, data2);
  if(rightStatus.numNodes == 2)
  {
    return rightStatus;
  }

  if((root->data == data1) || (root->data == data2))
  {
     curStatus.numNodes++;
  }

  curStatus.numNodes += leftStatus.numNodes + rightStatus.numNodes;
  if(curStatus.numNodes == 2)
  {
    cout << "***FOUND LCA***" << endl;
    curStatus.ancestor = root.get();
  }
  
  return curStatus;
}

template <typename T>
vector<vector<T>> Tree<T>::levelOrderTraversal()
{
 cout << "levelOrderTraversal" << endl;
 vector<vector<T>> result;
 queue<TreeNode<T>*> myQ;
 myQ.emplace(root.get());
 myQ.emplace(nullptr);
 int levels = -1;
 result.emplace_back(); // insert a dummy row to start
 
 while(!myQ.empty())
 { 
   if(!myQ.front())
   {
     if(myQ.size() != 1){
     myQ.emplace(nullptr);
     result.emplace_back();
     }
     levels++;
     cout << "Change level to  " << levels << endl;
     myQ.pop();
   }
   else
   {
      TreeNode<T> *temp = myQ.front();
      cout << "insert " << temp->data << " to result array " << endl;
      result.back().emplace_back(temp->data);   
      if(temp->left.get()){
      myQ.emplace(temp->left.get());
      }
      if(temp->right.get()){
      myQ.emplace(temp->right.get());
      } 
      myQ.pop();
   } 
 }
 cout << "levels, " << levels << endl;
 return result;
}

template <typename T>
void addToLeft(T val)
{
}

template <typename T>
void addToright(T val)
{
}


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

// Similar to Post Order Traversal
// Time Complexity : O(n)
// Space Complexity : O(h), height of the tree
template <typename T>
bool Tree<T>::isheightBalanced()
{
  bStatus status =  isheightBalancedHelper(root,-1);
  cout << "height, " <<  status.depth;
  return status.balanced;
  
}

template <typename T>
bStatus Tree<T>::isheightBalancedHelper(const std::unique_ptr<TreeNode<T>> &curNode,int depth)
{
  bStatus curStatus;
  curStatus.balanced = true;
  curStatus.depth = depth;
 
  if(!curNode)
  {
      return curStatus;
  }

  depth++;
 
  bStatus leftStatus  = isheightBalancedHelper(curNode->left, depth);
  if(!leftStatus.balanced){
   return leftStatus;
  }
  bStatus rightStatus = isheightBalancedHelper(curNode->right, depth);

  if(!rightStatus.balanced){
   return rightStatus;
  }
  
  curStatus.balanced = (abs(leftStatus.depth - rightStatus.depth) > 1)? false:true; 
  curStatus.depth = (leftStatus.depth>rightStatus.depth)?leftStatus.depth:rightStatus.depth;

  return curStatus;
}



template <typename T>
bool Tree<T>::isPerfectBinaryTree()
{

}

template <typename T>
bool Tree<T>::isSymmetric()
{
  if(!root) return false; 
  return isSymmetricHelper(root->left.get(),root->right.get());
}

template <typename T>
bool Tree<T>::isSymmetricHelper(TreeNode<T>* subTree0, TreeNode<T> *subTree1)
{

  if((subTree0 == nullptr) && (subTree1 == nullptr))
  {
    return true; 
  }
  else if((subTree0 != nullptr) && (subTree1 != nullptr))
  {
   if(subTree0->data == subTree1->data)
   {
     return ((isSymmetricHelper(subTree0->left.get(),subTree1->right.get())) && (isSymmetricHelper(subTree0->right.get(),subTree1->left.get())));
   }
  }

  return false;
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
 Tree<int> symmetricTree;
 symmetricTree.add(1);
 symmetricTree.add(2);
 symmetricTree.add(2);
 symmetricTree.add(4);
 symmetricTree.add(5);
 symmetricTree.add(5);
 symmetricTree.add(4);
 myTree.inOrder();
 myTree.inOrderIterative();
 myTree.preOrder();
 myTree.preOrderIterative();
 myTree.postOrder();
 cout << "Is Sum 15 present result, " << myTree.isSumPresentFromRootToLeaf(15) << endl;;
 myTree.height();
 if(myTree.isheightBalanced())
 {
  cout << "Tree is height balanced" << endl;
 }
 else
 {
  cout << "Tree is not height balanced" << endl;
 } 
 
 if(symmetricTree.isSymmetric())
 {
  cout << "Tree is symmetric" << endl;
 }else{
  cout << "Tree is not symmetric" << endl;
 }
 vector<vector<int>> result = myTree.levelOrderTraversal();
 cout << "LEVEL ORDER TRAVERSAL RESULT" << endl;
 for(int i = 0;i<result.size();i++)
 {
  for(int j = 0;j<result[i].size();j++)
  {
	cout << result[i][j] << "," ;
  }
  cout << endl;
 }
  cout << "FIND LCA " << endl;
  TreeNode<int>* lca = myTree.LCA(6,7); 
  cout << "LCA Is " << endl;
  cout << "LCA node is " << lca->data << endl;
  Tree<int> binarySumTree;
  binarySumTree.add(1);
  binarySumTree.add(0);
  binarySumTree.add(0);
  binarySumTree.add(0);
  binarySumTree.add(1);
  binarySumTree.add(0);
  binarySumTree.add(1);
  cout << "Binary SUM, " << binarySumTree.sumRootToLeafBinary();
}
