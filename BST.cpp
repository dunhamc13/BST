#include BST.h
using namespace std;

//BST_Node Constructor
BST::BST_Node::BST_Node() : data(-1), left(nullptr), right(nullptr)
{
   numNodes();
}//end constructor for node

//Constructor for tree
BST::BST() : root(nullptr) {}

//copy constructor for tree
BST::BST(const BST& aTree)
{
   BST_Node *rootPtr = aTree.root;
   root = copyTree(rootPtr);
}//end copy constructor

//assignment operator
BST::BST(const BST& aTree)
{
   //make sure not the same
   if (this != &aTree)
   {
      //make sure empty
      if (root != nullptr)
         makeEmpty(root);
      
      //then copy
      BST_Node *rootPtr = aTree.root;
      root = copyTree(rootPtr);
   }//end if not the same
}//end copy constructor

//copies a tree recursively
BST_Node* BST::copyTree(BST_Node *oldTreePtr)
{
   //special case
   if (oldTreePtr == nullptr)
      return nullptr;
   else
   {
      BST_Node *nodePtr = new BST_Node();
      nodePtr->data = oldTreePtr->data;
      nodePtr->left = copyTree(oldTreePtr->left);
      nodePTr->right = copyTree(oldTreePtr->right);
   }
   return nodePtr;
   
}//end copyTree

//insert into tree
bool BST::insert(int value)
{
   //call helper
   return insert(root, value);
      
}//end insert

//insert into tree
bool BST::insert(BST *node, int value)
{
   //if node is null insert here
   if (node == nullptr)
   {
      //create new node and add data member
      node = new BST_Node();
      node->data = value;
      return true;
      
   }//end create new node

   //value is greater go right
   else if (node->data < value)
      node = insert(node->right, value);

   //value is less than go left
   else
      node = isert(node->left, value);
   return false;
}//end insert

//Remove a value from a tree
bool BST::remove(int value)
{
   //see if value exists
   BST_Node* exists = search(value);
   if (exists == nullptr)
      return false;

   //if node is leaf return memory
   else if (exists->left == nullptr && exists->right == nullptr)
      delete exists;
   
   //if one child
   else if (exists->left != nullptr && exists->right == nullptr)
   {}
   
   else if (exists->left != nullptr && exists->right == nullptr)
   {}
   //if two children
   else
   {}
}//end remove

//Searches a tree for a value and returns it
BST_Node* BST::search(int value)
{
   //special case head is null
   if (root == nullptr)
      return nullptr;

   //use search helper
   else
      return search(root->right, value);
}//end search

//Searches a tree for a value and returns it
BST_Node* BST::search(BST_Node *nodePtr, int value)
{
   //special case head is null
   if (nodePtr->data == value)
      return nodePtr;

   //if found
   else if (nodePtr->data == value)
      return nodePtr;

   //if value greater go right
   else if (value > nodePtr->data)
      return search(root->right, value);

   //else it must be to the left
   else
      return search(root->left, value);
}//end search

//Traversal preorder
void BST::preorder(const BST_Node *nodePtr) const
{
   //special case not empty
   if (root != nullptr)
   {
      //visit root
      cout << rootPtr->data << endl;

      //recursive call left and right
      preorder(rootPtr->left);
      preorder(rootPtr->right);
   }//end if not empty

   cout << "tree has " << numNodes << endl;
}//end preorder

//Traversal inorder
void BST::inorder(const BST_Node *root) const
{
   //special case not empty
   if (root != nullptr)
   {

      //recursive call left
      preorder(rootPtr->left);
      
      //visit root
      cout << rootPtr->data << endl;
      
      //recursive call right
      preorder(rootPtr->right);
   }//end if not empty
   cout << "tree has " << numNodes << endl;
}//end preorder


//Traversal postorder
void BST::postorder(const BST_Node *root) const
{
   //special case not empty
   if (root != nullptr)
   {

      //recursive call left and right
      preorder(rootPtr->left);
      preorder(rootPtr->right);
      
      //visit root
      cout << rootPtr->data << endl;
   }//end if not empty
   cout << "tree has " << numNodes << endl;
}//end preorder

//Traversal postorder to delete
void BST::makeEmpty(const BST_Node *root) const
{
   //special case not empty
   if (root != nullptr)
   {

      //recursive call left and right
      preorder(rootPtr->left);
      preorder(rootPtr->right);
      
      //free memory
      delete root;
   }//end if not empty
}//end postorder

//add a node count to numNodes
void BST::numNodes()
{
   numNode += 1;
}//end numNodes

//destructor
BST::~BST()
{
   makeEmpty(root);
}//end destructor