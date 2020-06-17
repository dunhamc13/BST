/* Notes About File
 * @File: Bst.cpp
 * @Name: Christian Dunham
 * @Date: 19Feb2020
 * @Program Name:  Not Applicable - Class for Reuse
 *
 * Program Purpose:
 *    This purpose of this program is to build a robust Binary Search Tree Class
 *    for reuse.  This class depends on a comparable class to be implemented as 
 *    the data structure held in the tree.
 *******************************************************************************
 * Product Back Log :
 *                  : Flush out comments
 *******************************************************************************
 *
 *                        Included Libraries
 *
 *******************************************************************************
 *******************************************************************************
*/
#include "Bst.h"     //Declarations for the class
#include <iostream>  //for standard in out streams
using namespace std;

/** DefaultConstructor BstNode
  *  @Description: Creates an empty tree
  *  @Pre: None
  *  @Post: Bst root is null and number of nodes is 0.
 */
Bst::Bst() : numNodes(0), root(nullptr) 
{}//end constructor for tree

/**  Copy Constructor BstNode
  *  @Description: Uses private helper, copyTree to 
  *  create a dynamic deep copy of tree on the right.
  *  @Pre: None
  *  @Post: LHS is deep copy of RHS.
 */
Bst::Bst(const Bst& aTree)
{
   BstNode *rootPtr = aTree.root;
   root = copyTree(rootPtr);
}//end copy constructor

/*assignment operator
*/
Bst& Bst::operator=(const Bst& aTree)
{
   //make sure not the same
   if (this != &aTree)
   {
      //make sure empty
      if (root != nullptr)
         makeEmpty(root);
      
      //then copy
      BstNode *rootPtr = aTree.root;
      root = copyTree(rootPtr);
   }//end if not the same
   return *this;
}//end copy constructor

/*copies a tree recursively
*/
Bst::BstNode* Bst::copyTree(const BstNode *oldTreePtr)
{
   BstNode *nodePtr;
   //special case
   if (oldTreePtr == nullptr)
      return nullptr;
   else
   {
      nodePtr = new BstNode();
      nodePtr->data = oldTreePtr->data;//////////////////fix this for inheritance issues
      nodePtr->left = copyTree(oldTreePtr->left);
      nodePtr->right = copyTree(oldTreePtr->right);
      increaseNumNodes();
   }
   return nodePtr;
   
}//end copyTree

/*insert into tree
*/
bool Bst::insert(Comparable* datum)
{
   //if root is null insert here
   if (root == nullptr)
   {
      //cout << "insert at root " << datum << endl;
      //create new node and add data member
      BstNode *node = new BstNode();
      node->data = datum;
      node->right = nullptr;
      node->left = nullptr;
      root = node;
      increaseNumNodes();
      return true;
   }//end create new node

   else
      return insert(root, datum);
}//end insert

/*insert into tree
*/
bool Bst::insert(BstNode *root, Comparable* datum)
{
   //cout << "inserting root, node " << datum << endl;
   
   //value is greater go right
   if (*root->data < *datum)
   {
      //cout << "going right " << datum << endl;
      //is not empty on right keep going
      if (root->right != nullptr)
         return insert(root->right, datum);

      else 
      {
         //cout << "insert right "  << datum << endl;
         //create new node on right and add data member
         root->right = new BstNode();
         root->right->data = datum;
         root->right->right = nullptr;
         root->right->left = nullptr;
         increaseNumNodes();
         return true;
      }//end if exists
   }//end if greater go right
   
   /*value is less than go left
   */
   if (*root->data > *datum)
   { 
      //cout << "going left " << datum << endl;
      //is not empty on the left keep going
      if (root->left != nullptr)
      {
         return insert(root->left, datum);
      }//end keep going left

      //cout << "insert left "  << datum << endl;
      //create new node and add data member
      root->left = new BstNode();
      root->left->data = datum;
      root->left->right = nullptr;
      root->left->left = nullptr;
      increaseNumNodes();
      return true;
   }//end go left
   return false;
}//end insert

/*Remove a value from a tree
*/
bool Bst::remove(Comparable* datum)
{
   return remove(*&root, datum);
}//end remove first iteration

/*Remove a value from a tree
*/
bool Bst::remove(BstNode *&root, Comparable* datum)
{
   if (root == nullptr)
   {
      return false;
   }
   
   else if (*root->data == *datum)
   {
      int curr = root->data->getQty();
      if (curr > 1)
      {
         curr = curr -1;
         root->data->setQty(curr);
         //
         //cout <<"testing setting curr qty " << root->data->getQty() << endl;
        return true; 
      }//end if
      else
      {
         deleteRoot(*&root);
         return true;
      }
   }

   //recursive call to delete
   else if (*datum < *root->data)
      return remove(root->left, datum);

   else 
      return remove(root->right, datum);
}//end remove first iteration

/*deletes node
*/
void Bst::deleteRoot(BstNode *&root)
{
   //if node is leaf return memory
   if (root->left == nullptr && root->right == nullptr)
   {
      //cout << "leaf remove " << root->data << endl;
      delete root->data;
      delete root;
      root = nullptr;
      decreaseNumNodes();
   }
   
   //if one child
   else if (root->left == nullptr || root->right == nullptr)
   {
      BstNode *tmp = root;
      root = root->left == nullptr ? root->right : root->left;
      //return memory
      delete tmp->data;
      delete tmp;
      decreaseNumNodes();
   }//end remove one child on left
   
   //what if two child?
   else 
   {
      root->data = successor(*&root->right);
   }//end if two children
}//end remove

/*returns successor node
*/
Comparable* Bst::successor(BstNode* &root)
{
   if (root->left == nullptr)
   {
      Comparable* item = root->data;
      BstNode* junk = root;
      root = root->right;
      delete junk->data;
      delete junk;
      return item;
   }//end return item
   else
      return successor(root->left);
}                                  

/*Searches a tree for a value and returns it
*/
Comparable* Bst::search(Comparable* datum)
{
   //special case head is null
   if (root != nullptr)
      return search(root,datum);

   //use search helper
   else
      return nullptr;
}//end search

/*Searches a tree for a value true if found
*/
bool Bst::exists(Comparable* datum)
{
   //special case head is null
   if (root == nullptr)
      return false;

   //use search helper
   else
   {
      BstNode* rootPtr = Bst::getRoot();
      return exists(rootPtr, datum);
   }//end else
}//end exists

/*Searches a tree for a value and returns it
*/
Comparable* Bst::search(BstNode *nodePtr, Comparable* datum)
{
   if (nodePtr == nullptr)
   {
      return nullptr;
   }// end if nullptr
   
   //value found
   else if (*nodePtr->data == *datum)
   {
      return nodePtr->data;
   }//end target
   
   //if value greater go right
   else if (*datum > *nodePtr->data)
   {
      if (nodePtr->right == nullptr)
         return nullptr;
      else
         return search(nodePtr->right, datum);
   }// else go rigth
   
   //else it must be to the left
   else if (*datum < *nodePtr->data)
   {
      if (nodePtr->left == nullptr)
         return nullptr;
      else
         return search(nodePtr->left, datum);
   }//end go leftw

   //all others
   return nullptr;
}//end search

/*Searches a tree for a value and returns true if found
*/
bool Bst::exists(BstNode *nodePtr, Comparable* datum)
{
   //value found
   if (nodePtr == nullptr)
   {
      return false;
   }
   //value found
   else if (*nodePtr->data == *datum)
      return true;

   //if value greater go right
   else if (*datum > *nodePtr->data)
   {
      if (nodePtr->right == nullptr)
         return false;
      else
         return exists(nodePtr->right, datum);
   }//end else if go right
   
   //else it must be to the left
   else if (*datum < *nodePtr->data)
   {
      if (nodePtr->left == nullptr)
         return false;
      else
         return exists(nodePtr->left, datum);
   }//end else if go left
   
   return false;
}//end exists

/*Traversal preorder
*/
void Bst::preorder(BstNode *nodePtr) const
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

/*Traversal preorder helper
*/
void Bst::preorder() const
{
   preorder(root);
}//end helper preorder

/*Traversal inorder
*/
void Bst::inorder(BstNode *nodePtr) const
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

/*Traversal inorder helper
*/
void Bst::inorder() const
{
   inorder(root);
}//end helper preorder

/*Traversal postorder
*/
void Bst::postorder(BstNode *nodePtr) const
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

/*Traversal postorder helper
*/
void Bst::postorder() const
{
   postorder(root);
}//end helper preorder

/*get height
*/
int Bst::getHeight()
{
   int height = getHeight(root);
   return height;
}//end getHeight

/*helper to get height
*/
int Bst::getHeight(BstNode *nodePtr) const
{
   //if node is emtpy
   if (nodePtr == nullptr)
      return 0;
   
   //recursive call to get height
   return 1 + max(getHeight(nodePtr->left),getHeight(nodePtr->right));
}//end getHeight

/*get numNodes
*/
int Bst::getNumNodes() const
{
   return numNodes;
}//end getNumNodes

/*add a node count to numNodes
*/
void Bst::increaseNumNodes()
{
   numNodes += 1;
}//end numNodes

/*remove a node count to numNodes
*/
void Bst::decreaseNumNodes()
{
   numNodes -= 1;
}//end numNodes

/*get root
*/
Bst::BstNode* Bst::getRoot() const
{
   return root;
}//end get root

/*Traversal postorder to delete
*/
void Bst::makeEmpty(BstNode*& rootPtr)
{
   //special case not empty
   if (rootPtr != nullptr)
   {
      //recursive call left and right
      makeEmpty(rootPtr->left);
      makeEmpty(rootPtr->right);
      
      //free memory
      //cout << rootPtr->data << endl;
      delete rootPtr->data;
      delete rootPtr;
      rootPtr = nullptr;
   }//end if not empty
}//end postorder

/*destructor
*/
Bst::~Bst()
{
   makeEmpty(root);
}//end destructor
