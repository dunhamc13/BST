#include <string>
#pragma once

class BST
{
   public:
      //struct BST_Node;
      //friend struct BST_Node;
      
      //The Nodes for the tree
      struct BST_Node
      {
         int data;//data
         struct BST_Node* left;//left child
         struct BST_Node* right;//right child

         //default constructor
         BST_Node();
      };//

      //BST Tree members

      //Default constructor
      BST();

      //Copy constructor
      BST(const BST& aTree);

      //assignment operator
      BST& operator=(const BST& aTree);

      //insert a value
      bool insert(int value);
      
      //insert helper
      bool insert(BST_Node *node, int value);

      //removes a value from tree
      bool remove(int value);
      
      //removes a value from tree
      bool remove(BST_Node *&root, int value);

      //removes a value from tree
      void deleteRoot(BST_Node *&root);

      //removes a value from tree
      bool exists(int value);
      
      //removes a value from tree
      bool exists(BST_Node* root, int value);

      //removes a value from tree
      int successor(BST_Node *&root);
      
      //returns the node if a value exists
      BST_Node* search(int value);

      //helps search for nodes with value
      BST_Node* search(BST_Node *nodePtr, int value);
      
      //Traversal preorder
      void preorder() const;

      //Traversal inorder
      void inorder() const;

      //Traversal postorder
      void postorder() const;

      //add node to numNode
      void increaseNumNodes();

      //remove node to numNode
      void decreaseNumNodes();
   
      //get root of tree
      BST_Node* getRoot() const;
      
      //get height of tree
      int getHeight();
   
      //destructor
      virtual ~BST();
   
   private:
      int numNodes;//holds number of nodes.
      BST_Node *root;// start of tree

      //copies tree
      BST_Node* copyTree(const BST_Node *oldTreePtr);
      
      //Traversal preorder
      void preorder(BST_Node* nodePtr) const;

      //Traversal inorder
      void inorder(BST_Node* nodePtr) const;

      //Traversal postorder
      void postorder(BST_Node* nodePtr) const;
      
      //get height of tree
      int getHeight(BST_Node* nodePtr) const;

      //clears the tree
      void makeEmpty(BST_Node* rootPtr);
};// end BST 
