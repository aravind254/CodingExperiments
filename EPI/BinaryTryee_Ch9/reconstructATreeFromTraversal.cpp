#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

template<typename T>
struct TreeNode
{
  T data;
  std::unique_ptr<TreeNode<T>> left=nullptr,right=nullptr;
};

typedef  std::unordered_map<int,int> inOrderMapType;

template<typename T>
class TreeReconstruction
{
 public:
 void reconstructTreeFromMarkedTraversalData(vector<T> &preOrder)
 {
    int curIndex = 0;
    root = reconstructTreeFromMarkedTraversalDataHelper(preOrder,&curIndex);     
 }
 
 void reconstructTreeFromTraversalData(vector<T> &inOrder,vector<T> &preOrder)
 {
  inOrderTraversal = inOrder;
  preOrderTraversal = preOrder;
  inOrderMapType inOrderIndexMap;
  for(int i = 0;i<inOrder.size();i++)
  {
   inOrderIndexMap[inOrder[i]] = i;
  }
  root =  reconstructTreeFromTraversalDataHelper(inOrderIndexMap,0,inOrder.size()-1,0,preOrder.size()-1);
 }

 void inOrder()
 {
	 cout << "inOrder" << endl;
	 inOrderHelper(root);
	 cout << endl;
 }

 void preOrder()
 {
  cout << "preOrder" << endl;
  preOrderHelper(root);
  cout << endl;
 }

 private:
 std::unique_ptr<TreeNode<T>> root = nullptr;
 vector<T> inOrderTraversal;
 vector<T> preOrderTraversal;
 void preOrderHelper(const unique_ptr<TreeNode<T>>& curNode)
 {
    if(!curNode) {return;}

    cout << curNode->data << " ";
    preOrderHelper(curNode->left);
    preOrderHelper(curNode->right);
 }
 void inOrderHelper(const unique_ptr<TreeNode<T>>& curNode)
 {
    if(!curNode) {return;}

    inOrderHelper(curNode->left);
    cout << curNode->data << " ";
    inOrderHelper(curNode->right);
 }
 std::unique_ptr<TreeNode<T>> reconstructTreeFromTraversalDataHelper(inOrderMapType inOrderIndexMap,int inorder_start, int inorder_end, int preorder_start,int preorder_end)
 {
    // Base Case
   if((inorder_start > inorder_end) || (preorder_start > preorder_end))
   {
      return nullptr;
   }  

   int data = preOrderTraversal[preorder_start];
   int inOrderIdx = inOrderIndexMap[data];
   int leftSubTreeSize = inOrderIdx - inorder_start;
   std::unique_ptr<TreeNode<T>> leftST  = reconstructTreeFromTraversalDataHelper(inOrderIndexMap,inorder_start,inOrderIdx-1,preorder_start+1,preorder_start+leftSubTreeSize);
   std::unique_ptr<TreeNode<T>> rightST =  reconstructTreeFromTraversalDataHelper(inOrderIndexMap,inOrderIdx+1,inorder_end,preorder_start+leftSubTreeSize+1,preorder_end);
   std::unique_ptr<TreeNode<T>> curNode = make_unique<TreeNode<T>>();
   curNode->data = data;
   curNode->left = std::move(leftST);
   curNode->right = std::move(rightST);
    
   return std::move(curNode);
 }
 std::unique_ptr<TreeNode<T>> reconstructTreeFromMarkedTraversalDataHelper(vector<T> &preOrder, int* curIndex)
 {
      if(preOrder[*curIndex] == std::numeric_limits<int>::min())
      {
          (*curIndex)++;
          return nullptr;
      }

      std::unique_ptr<TreeNode<T>> newNode   = make_unique<TreeNode<T>>();
      newNode->data  = preOrder[*curIndex]; (*curIndex)++;
      newNode->left  = reconstructTreeFromMarkedTraversalDataHelper(preOrder,curIndex);
      newNode->right = reconstructTreeFromMarkedTraversalDataHelper(preOrder,curIndex);
      return std::move(newNode); 
 }
};


int main()
{

// Reconstruct a tree given InOrder Traversal & PreOrder Traversal
vector<int> inOrderTraversal  = {8,2,4,1,5,6,3,7};
vector<int> preOrderTraversal = {5,4,2,8,1,3,6,7};
TreeReconstruction<int> reconstObj;
reconstObj.reconstructTreeFromTraversalData(inOrderTraversal,preOrderTraversal);
reconstObj.inOrder();
reconstObj.preOrder(); 

cout << "Marked Traversal Data Tree Construction" << endl;
int d = std::numeric_limits<int>::min();
vector<int> markedPreOrderTraversal = {5,4,2,8,d,d,d,1,d,d,3,6,d,d,7,d,d};
reconstObj.reconstructTreeFromMarkedTraversalData(markedPreOrderTraversal);
reconstObj.inOrder();
reconstObj.preOrder(); 
}
