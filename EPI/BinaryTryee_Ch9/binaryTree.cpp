#include "binaryTree.h"

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

<typename T>
void Tree::add(T val)
{
  if(!root){
  root = make_unique<TreeNode<T>>();
  root->data = val ;
  }

  


}

<typename T>
void Tree::delete(T val)
{
}

int Tree::height()
{
}

<typename T>
int Tree::depthOfNode(T val)
{

}

bool Tree::isBalanced()
{

}

bool Tree::isPerfectBinaryTree()
{

}

bool Tree::isSymmetric()
{

}


int main()
{




}




