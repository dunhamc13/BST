#include BST.h
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
      increaseNumNodes();
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
      increaseNumNodes();
      return true;
      
   }//end create new node

   //value is greater go right
   else if (node->data < value)
      node = insert(node->right, value);

   //value is less than go left
   else
      node = inert(node->left, value);
   return false;
}//end insert

//Remove a value from a tree
bool BST::remove(int value)
{
   //see if value exists
   BST_Node* exists = search(value);
   if (exists == nullptr)
      return false;
   
   //recursive call to delete
   else
      return remove(root, value);
}//end remove first iteration

bool BST::remove(BST_Node *root, value)
{
   //see if value exists
   BST_Node* exists = search(root, value);
   if (exists == nullptr)
      return false;

   //if node is leaf return memory
   else if (exists->left == nullptr && exists->right == nullptr)
   {
      delete exists;
      decreaseNumNodes();
      return true;
   }
   
   //if one child
   else if (exists->left != nullptr && exists->right == nullptr)
   {
      //make a temp node with single child
      BST_Node *tmp = exists->left;
      
      //return memory
      delete exists;
      
      //fix broken link in tree
      exists = tmp;
      decreaseNumNodes();
      return true;
   }//end remove one child on left
   
   else if (exists->left != nullptr && exists->right == nullptr)
   {
      //make a temp node with single child
      BST_Node *tmp = exists->right;
      
      //return memory
      delete exists;
      
      //fix broken link in tree
      exists = tmp;
      decreaseNumNodes();
      return true;
   }// end one child on right
   
   //if two children
   else
   {
      //get successor node
      BST_Node *successor = successor(exists->right);
      
      //copy data
      exists->data = successor->data;
      
      //recursive call to delete successor node
      return remove(exists->right, value);
   }//end if two children
   return false;
}//end remove

//returns successor node
BST_Node* BST::successor(BST_Node *nodeToDeletesRighChild)
{
   BST_Node *currPtr = nodeToDeletesRightChild;
   
   while (currPtr != nullptr && currPtr->left != nullptr)
      currPtr = currPtr->left;
   return currPtr;
}                                  

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

//get height
int BST::getHeight()
{
   getHeight(root);
}//end getHeight

//helper to get height
int BST::getHeight(BST_Node *nodePtr) const
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
   numNode += 1;
}//end numNodes

//remove a node count to numNodes
void BST::decreaseNumNodes()
{
   numNode -= 1;
}//end numNodes

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

//destructor
BST::~BST()
{
   makeEmpty(root);
}//end destructor
