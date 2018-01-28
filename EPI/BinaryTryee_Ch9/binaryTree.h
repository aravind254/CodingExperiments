#include<iostream>
#include<memory>

template <typename T>
struct TreeNode
{
  T data;
  std::unique_ptr<TreeNode<T>> left=nullpt,right=nullptr;
};

template <typename T>
class Tree
{
public:
void add(T);
void delete(T);
int height();
int depthOfNode(T);
bool isBalanced();
bool isPerfectBinaryTree();
void inOrder(TreeNode<T> *); 
void preOrder(TreeNode<T> *); 
void postOrder(TreeNode<T> *); 
bool isSymmetric();

std::unique_ptr<TreeNode<T>> root=nullptr; // For the sake of simplicity making this info public
};


Tree<int>;
