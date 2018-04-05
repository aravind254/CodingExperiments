#include<iostream>
#include<queue>

using namespace std;


class Node
{
  public:
  Node(int val) {data = val;}
  Node *left = nullptr;
  Node *right = nullptr;
  int data;
};

class BST
{
 public:
 void add(int);
 bool find(int);
 void inOrder();
 void deleteNode(int);
 bool isValid();
 bool isValidUsingBFS();
 int firstKeyGreaterThanValue(int);
 vector<int> findKLargestElements(int);
 Node* LCA(int,int);
 Node* LCAIterative(int k, int j);

 private:
 Node *root = nullptr;
 Node* addHelper(Node*,int);
 void inOrderHelper(Node*);
 Node* deleteHelper(Node*,int);
 Node* minValueNode(Node*);
 bool isValidHelper(Node*,int,int);
 bool isValidUsingBFSHelper(Node*,int,int);
 int firstKeyGreaterThanValueHelper(Node*,int);
 void findKLargestElementsHelper(Node*,int,vector<int>&);
 Node* LCAHelper(Node*,int,int);
 Node* LCAIterativeHelper(Node*,int,int);
};

// Time Complexity : O(h)
// Space Complexity : O(1)
// Assumption: Both k & j are present in the BST 
Node* BST::LCAIterative(int k, int j)
{
   return LCAIterativeHelper(root,k,j);
}

Node* BST::LCAIterativeHelper(Node *cur,int k, int j)
{
  while(cur != nullptr)
  {
	  if((k < cur->data) &&  (j < cur->data))
	  {
	    cur = cur->left;
	  } 
	  else if((k > cur->data) && (j > cur->data))
	  {  
	    cur = cur->right;
	  }
          else
          {
             break;
          }
  }
  return cur;
}

// Time Complexity : O(h)
// Space Complexity : O(h)
// Assumption: Both k & j are present in the BST 
Node* BST::LCA(int k, int j)
{
  return LCAHelper(root,k,j);
}

// TimeComplexity : O(h)
// SpaceCompleixity : O(h)
Node* BST::LCAHelper(Node* cur, int k, int j)
{
  if(nullptr == cur)
  {
    return nullptr;
  }

  if((k < cur->data) &&  (j < cur->data))
  {
    return LCAHelper(cur->left,k,j);
  } 
  else if((k > cur->data) && (j > cur->data))
  {  
    return LCAHelper(cur->right,k,j);
  }

  return cur; 
}


// Time Complexity : O(height of tree + k)
vector<int> BST::findKLargestElements(int k)
{
  vector<int> result;
  findKLargestElementsHelper(root,k,result); 
  return result;
}

void BST::findKLargestElementsHelper(Node* cur,int k,vector<int> &result)
{
    if((nullptr == cur) || (result.size() >= k) ) {
    return;
    }
    
    findKLargestElementsHelper(cur->right,k,result);
    if(result.size() < k)
    {
        result.emplace_back(cur->data);
    }
    findKLargestElementsHelper(cur->left,k,result);
}

int BST::firstKeyGreaterThanValue(int k)
{
 return firstKeyGreaterThanValueHelper(root,k);
}

int BST::firstKeyGreaterThanValueHelper(Node *cur,int k)
{
  static int greaterSoFar = -1;
  if(nullptr == cur){
  return greaterSoFar;
  }
  if(k < cur->data){
      greaterSoFar = cur->data;
      return firstKeyGreaterThanValueHelper(cur->left,k);
  }
  else
  {
     return firstKeyGreaterThanValueHelper(cur->right,k);
  }
}



bool BST::isValidHelper(Node *cur,int min,int max)
{
  if(nullptr == cur)
  {
     return true;
  }

  if((cur->data < min) || (cur->data > max))
  {
    return false;
  }

  return (isValidHelper(cur->left,min,cur->data)  && isValidHelper(cur->right,cur->data,max));
}


// TimeComplexity : O(n) 
// Another approach could be to do inOrder Traversal and verify if each newNode in the traversal is smaller than previous node.
// The downside to this approach is the complete left Subtree is visited and checked for validity before going to the right Subtree.
// Alternative could be to do a BFS check, Time Complexity is stil O(n). But helps in cases where the violation is at a low depth. But this approach 
// takes additional space complexity of O(n)
bool BST::isValid()
{
  return isValidHelper(root,std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}


// Time Complexity : O(n)
// Space Complexity : O(n)
// Helps in cases where the violation is at a low depth, compared to the other approach isValid()
bool BST::isValidUsingBFS()
{
  cout << "isValidUsingBFS" << endl;
  return isValidUsingBFSHelper(root,std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
  cout << endl;
}

struct element
{
  Node *node;
  int min;
  int max;
};

bool BST::isValidUsingBFSHelper(Node* cur, int min, int max)
{
  if(nullptr == cur) { return false;}
  queue<element> myQ;
 
  element temp = {cur,std::numeric_limits<int>::min(), std::numeric_limits<int>::max()};
  myQ.emplace(temp);
 
  while(!myQ.empty())
  {
    element temp = myQ.front();
    myQ.pop();
    if((temp.node->data < min) || (temp.node->data > max))
    {
      return false;
    }
    cout << "Check " << temp.node->data << endl;

    if(temp.node->left != nullptr)
    {
       element temp1 = {temp.node->left,min,temp.node->data};
       myQ.emplace(temp1);
    }
    
    if(temp.node->right != nullptr)
    {
      element temp1 = {temp.node->right,min,temp.node->data};
      myQ.emplace(temp1);
    }
  }
  return true;
}

Node* BST::minValueNode(Node *cur)
{
   if(nullptr == cur)
   {
     return nullptr;
   }

   while(cur->left != nullptr)
   {
      cur = cur->left;
   }

   return cur;
}

void BST::deleteNode(int val)
{
  cout << "deleteNode "<< val << endl;
  deleteHelper(root,val);
}

Node* BST::deleteHelper(Node* cur, int val)
{
   if(nullptr == cur)
   {
     return nullptr;
   }

   if(val < cur->data)
   {
      cur->left = deleteHelper(cur->left,val);
   }
   else if(val > cur->data)
   {
      cur->right = deleteHelper(cur->right,val);
   }
   else
   {
     if(cur->left == nullptr) // left child only null or left & right child is null
     {
        cout << "left child only null or left & right child is null" << endl;
        Node *temp = cur->right;
        delete cur;
        return temp;
     }
     else if(cur->right == nullptr) // right child only null
     {
        cout << "right child only null" << endl;
        Node *temp = cur->left;
        delete cur; 
        return temp;
     }
     else
     {
       cout << "Both left & right not null" << endl;
       Node* minNode = minValueNode(cur->right);
       cur->data = minNode->data; 
       cout << "Delete inOrder Successor " << minNode->data << endl;
       cur->right = deleteHelper(cur->right,minNode->data);
     }
   }

   return cur;
}

void BST::inOrder()
{
  cout << "inOrder ";
  inOrderHelper(root);
  cout << endl;
}

void BST::inOrderHelper(Node* cur)
{
  if(nullptr == cur)
  {
     return;  
  }

  inOrderHelper(cur->left);
  cout << cur->data << ",";
  inOrderHelper(cur->right);
}


// Time Complexity : O(height of Tree). 
void BST::add(int data)
{
  root = addHelper(root,data);  
}

Node* BST::addHelper(Node* cur, int data)
{
  if(nullptr == cur)
  {
     cout << "Add element data,"<< data << endl;
     cur = new Node(data);
     return cur;
  }

  if(data < cur->data)
  {
     cur->left = addHelper(cur->left,data);
  } 
  else if(data > cur->data)
  {
    cur->right = addHelper(cur->right,data);
  }
  return cur;
}

int main()
{
  BST bst;
  bst.add(10);
  bst.add(8);
  bst.add(6);
  bst.add(4);
  bst.add(2);
  bst.add(15);
  bst.add(12);
  bst.add(20);
  cout << "BST isValid, " << bst.isValid() << endl;
  cout << "BST isValidUsingBFS, " << bst.isValidUsingBFS() << endl;

  cout << "firstKeyGreaterThanValue 11, " <<  bst.firstKeyGreaterThanValue(11) << endl;
  cout << "firstKeyGreaterThanValue 3, " << bst.firstKeyGreaterThanValue(3) << endl;

  vector<int> result = bst.findKLargestElements(8);
  cout << "findKLargestElements k = 8 ";
  for(int s : result)
  {
    cout << s << ",";
  }
  cout << endl;

  Node *lca1 = bst.LCAIterative(12,20);
  Node *lca2 = bst.LCA(12,20);
  cout << "lca1 " << lca1->data<< endl;
  cout << "lca2 " << lca2->data<< endl;

  bst.inOrder();
  bst.deleteNode(2);
  bst.inOrder();
  bst.deleteNode(8);
  bst.inOrder();
  bst.deleteNode(10);
  bst.inOrder();


  
}
