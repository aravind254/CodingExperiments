#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
 int val;
 TreeNode *left=nullptr;
 TreeNode *right=nullptr;
 int height=0;
 TreeNode(int cVal):val(cVal){}
};

int height(TreeNode *cur)
{
  if(cur == nullptr)
  {
    return -1;
  }
  return cur->height;
}

TreeNode* rotateRight(TreeNode *cur)
{
   cout << "rotateRight" << endl;
   TreeNode* newRoot = cur->left;
   TreeNode* cachedRight = newRoot->right;
   newRoot->right = cur;
   cur->left = cachedRight;

   newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
   cur->height = max(height(cur->left), height(cur->right)) + 1;

   return newRoot;
}

TreeNode* rotateLeft(TreeNode *cur)
{
   cout << "rotateLeft" << endl;
   TreeNode* newRoot = cur->right;
   TreeNode* cachedLeft = newRoot->left;
   newRoot->left = cur;
   cur->right = cachedLeft;

   newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
   cur->height = max(height(cur->left), height(cur->right)) + 1;

   return newRoot;
}


TreeNode* insert(TreeNode *cur, int val)
{
   if(cur == nullptr)
   { 
     cout << "Create node for val," << val << endl;
     TreeNode* temp = new TreeNode(val);
     return temp;
   }
   cout << "insert val," << val << endl;  

  if(val <= cur->val)
  {
     cur->left = insert(cur->left,val);
     cur->height = max(height(cur->left), height(cur->right)) + 1;
  }
  else
  {
     cur->right = insert(cur->right,val);
     cur->height = max(height(cur->left), height(cur->right)) + 1;
  }


  int balance =  height(cur->left) - height(cur->right);

  if(balance > 1) // left
  {
     if(height(cur->left->right) > height(cur->left->left))
     {
	 cur->left = rotateLeft(cur->left); // LR Case
     }
     
     cur = rotateRight(cur); // LL case 
 
  }
  else if(balance < -1) // right
  {
      if(height(cur->right->left) > height(cur->right->right))
      {
          cur->right =  rotateRight(cur->right); // RL case
      }
      cur = rotateLeft(cur); // RR case
  }

  cur->height = max(height(cur->left),height(cur->right)) + 1;

  return cur;
}

void preOrder(TreeNode *cur)
{
  if(cur == nullptr) { return;}
  cout << cur->val << ","; 
  preOrder(cur->left);
  preOrder(cur->right);
}

int main()
{
   TreeNode *root = nullptr;
   root = insert(root,10);
   root = insert(root,20);
   root = insert(root,30);
   root = insert(root,40);
   root = insert(root,50);
   root = insert(root,25);
   
   preOrder(root);

}
