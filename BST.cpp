#include <iostream>
#include "BST.h"
using namespace std;

//BST_Node Constructor
BST::BST_Node::BST_Node() : data(-1), left(nullptr), right(nullptr)
{}//end constructor for node

//Constructor for tree
BST::BST() : numNodes(0), root(nullptr) {}//end constructor for tree

//copy constructor for tree
BST::BST(const BST& aTree)
{
   BST_Node *rootPtr = aTree.root;
   root = copyTree(rootPtr);
}//end copy constructor

//assignment operator
BST& BST::operator=(const BST& aTree)
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
   return *this;
}//end copy constructor

//copies a tree recursively
BST::BST_Node* BST::copyTree(const BST_Node *oldTreePtr)
{
   BST_Node *nodePtr;
   //special case
   if (oldTreePtr == nullptr)
      return nullptr;
   else
   {
      nodePtr = new BST_Node();
      nodePtr->data = oldTreePtr->data;
      nodePtr->left = copyTree(oldTreePtr->left);
      nodePtr->right = copyTree(oldTreePtr->right);
      increaseNumNodes();
   }
   return nodePtr;
   
}//end copyTree

//insert into tree
bool BST::insert(int value)
{
   //if root is null insert here
   if (root == nullptr)
   {
      //create new node and add data member
      BST::BST_Node *node = new BST::BST_Node();
      node->data = value;
      node->right = nullptr;
      node->left = nullptr;
      root = node;
      increaseNumNodes();
      return true;
   }//end create new node

   else
      return insert(root, value);
}//end insert

//insert into tree
bool BST::insert(BST::BST_Node *node, int value)
{
   //value is greater go right
   if (node->data < value)
   {
      //is not empty on right keep going
      if (node->right != nullptr)
         return insert(node->right, value);

      else 
      {
         cout << "insert right " << value << endl;
         //create new node on right and add data member
         node->right = new BST::BST_Node();
         node->right->data = value;
         node->right->right = nullptr;
         node->right->left = nullptr;
         increaseNumNodes();
         return true;
      }//end if exists
   }//end if greater go right
   
   //value is less than go left
   if (node->data > value)
   { 
      //is not empty on the left keep going
      if (node->left != nullptr)
      {
         return insert(node->left, value);
      }//end keep going left

      cout << "insert left " << value << endl;
      //create new node and add data member
      node->left = new BST::BST_Node();
      node->left->data = value;
      node->left->right = nullptr;
      node->left->left = nullptr;
      increaseNumNodes();
      return true;
   }//end go left
   return false;
}//end insert

//Remove a value from a tree
bool BST::remove(int value)
{
   return remove(*&root, value);
}//end remove first iteration

//Remove a value from a tree
bool BST::remove(BST::BST_Node *&root, int value)
{
   if (root == nullptr)
   {
      return false;
   }
   
   else if (root->data == value)
   {
      deleteRoot(*&root);
      return true;
   }

   //recursive call to delete
   else if (value < root->data)
      return remove(root->left, value);

   else 
      return remove(root->right, value);
}//end remove first iteration

void BST::deleteRoot(BST::BST_Node *&root)
{
   //if node is leaf return memory
   if (root->left == nullptr && root->right == nullptr)
   {
      cout << "leaf remove " << root->data << endl;
      delete root;
      root = nullptr;
      decreaseNumNodes();
   }
   
   //if one child
   else if (root->left == nullptr || root->right == nullptr)
   {
      BST::BST_Node *tmp = root;
      root = root->left == nullptr ? root->right : root->left;
      //return memory
      delete tmp;
      decreaseNumNodes();
   }//end remove one child on left
   
   //what if two child?
   else 
   {
      root->data = successor(*&root->right);
   }//end if two children
}//end remove

//returns successor node
int BST::successor(BST::BST_Node* &root)
{
   if (root->left == nullptr)
   {
      int item = root->data;
      BST::BST_Node* junk = root;
      root = root->right;
      delete junk;
      return item;
   }//end return item
   else
      return successor(root->left);
}                                  

//Searches a tree for a value and returns it
BST::BST_Node* BST::search(int value)
{
   //special case head is null
   if (root != nullptr)
      return search(root,value);

   //use search helper
   else
      return nullptr;
}//end search

//Searches a tree for a value true if found
bool BST::exists(int value)
{
   //special case head is null
   if (root == nullptr)
      return false;

   //use search helper
   else
   {
      BST_Node* rootPtr = BST::getRoot();
      return exists(rootPtr, value);
   }//end else
}//end exists

//Searches a tree for a value and returns it
BST::BST_Node* BST::search(BST::BST_Node *nodePtr, int value)
{
   if (nodePtr == nullptr)
   {
      return nullptr;
   }// end if nullptr
   
   //value found
   else if (nodePtr->data == value)
   {
      return nodePtr;
   }//end target
   
   //if value greater go right
   else if (value > nodePtr->data)
   {
      if (nodePtr->right == nullptr)
         return nullptr;
      else
         return search(nodePtr->right, value);
   }// else go rigth
   
   //else it must be to the left
   else if (value < nodePtr->data)
   {
      if (nodePtr->left == nullptr)
         return nullptr;
      else
         return search(nodePtr->left, value);
   }//end go left

   //all others
   return nullptr;
}//end search

//Searches a tree for a value and returns true if found
bool BST::exists(BST::BST_Node *nodePtr, int value)
{
   cout << nodePtr->data << endl;
  cout << "exist helper" << endl; 
   //value found
   if (nodePtr == nullptr)
   {
      cout << "false?" << endl;
      return false;
   }
   //value found
   else if (nodePtr->data == value)
      return true;

   //if value greater go right
   else if (value > nodePtr->data)
   {
      if (nodePtr->right == nullptr)
         return false;
      else
         return exists(nodePtr->right, value);
   }//end else if go right
   
   //else it must be to the left
   else if (value < nodePtr->data)
   {
      if (nodePtr->left == nullptr)
         return false;
      else
         return exists(nodePtr->left, value);
   }//end else if go left
   
   return false;
}//end exists

//Traversal preorder
void BST::preorder(BST_Node *nodePtr) const
{
   //special case not empty
  if (nodePtr != nullptr)
  {
      //visit root
      cout << nodePtr->data << endl;

      //recursive call left and right
      preorder(nodePtr->left);
      preorder(nodePtr->right);
  }//end if not empty
}//end preorder

//Traversal preorder helper
void BST::preorder() const
{
   preorder(root);
}//end helper preorder

//Traversal inorder
void BST::inorder(BST_Node *nodePtr) const
{

   //special case not empty
   if (nodePtr != nullptr)
   {

      //recursive call left
      inorder(nodePtr->left);
      
      //visit root
      cout << nodePtr->data << endl;
      
      //recursive call right
      inorder(nodePtr->right);
   }//end if not empty
}//end preorder

//Traversal inorder helper
void BST::inorder() const
{
   inorder(root);
}//end helper preorder

//Traversal postorder
void BST::postorder(BST_Node *nodePtr) const
{
   //special case not empty
   if (nodePtr != nullptr)
   {

      //recursive call left and right
      postorder(nodePtr->left);
      postorder(nodePtr->right);
      
      //visit root
      cout << nodePtr->data << endl;
   }//end if not empty
}//end preorder

//Traversal postorder helper
void BST::postorder() const
{
   postorder(root);
}//end helper preorder

//get height
int BST::getHeight()
{
   int height = getHeight(root);
   return height;
}//end getHeight

//helper to get height
int BST::getHeight(BST::BST_Node *nodePtr) const
{
   //if node is emtpy
   if (nodePtr == nullptr)
      return 0;
   
   //recursive call to get height
   return 1 + max(getHeight(nodePtr->left),getHeight(nodePtr->right));
}//end getHeight

//add a node count to numNodes
void BST::increaseNumNodes()
{
   numNodes += 1;
}//end numNodes

//remove a node count to numNodes
void BST::decreaseNumNodes()
{
   numNodes -= 1;
}//end numNodes

//get root
BST::BST_Node* BST::getRoot() const
{
   return root;
}//end get root

//Traversal postorder to delete
void BST::makeEmpty(BST::BST_Node* rootPtr)
{
   //special case not empty
   if (rootPtr != nullptr)
   {
      //recursive call left and right
      makeEmpty(rootPtr->left);
      makeEmpty(rootPtr->right);
      
      //free memory
      delete rootPtr;
      rootPtr = nullptr;
   }//end if not empty
}//end postorder

//destructor
BST::~BST()
{
   makeEmpty(root);
}//end destructor
