/* Notes About File
 * @File: Bst.h
 * @Name: Christian Dunham
 * @Date: 19Feb2020
 * @Program Name:  Not Applicable - Code for Reuse
 *
 * Program Purpose: NA
 *
 *   Class Purpose:
 *    This class creates a Binary Search Tree.  Each node stores a pointer to a data obj.
 *    This allows the linked list to be used with other classes later on, as
 *    long as that Bst has </>, <</>> operators. 
 *
 * Bst Private Members:
 *    root holds the firstnode of the tree.
 *
 * Dynamic Memory:
 *    The BstNodes are Dynmaically created. 
 *
 *******************************************************************************
 *
 *  Discussion of members:  -> (denotes helper member)
 *
 ***  Bst Class  *************************************************************
 *
 *    Constructors: -> Overloaded Constructor, Copy Constructor, Assighment
 *    Operator :: -> copyBst -> clearBst
 *    
 *    The copy constructor and assigment operator both utilize a private
 *    member copyBst.
 *
 *    Destructor: -> clearBst
 *    The virtual destructor uses a private member clearGraph. 
 *
 *******************************************************************************
 *
 *                        Special Cases Identified
 *
 *******************************************************************************
 *
 ***  Bst Class  *************************************************************
 *     : ???? :
 *                a) ??????
 *
 *******************************************************************************
 *
 *******************************************************************************
 *Product BackLog :
 *                 1) ???????
 *******************************************************************************
 *
 *******************************************************************************
 * Code Outline :
 *
 *                Bst Definitions       :
 *                              : public :
 *                                         Constructor
 *                                         Overloaded Constructor
 *                                         Copy Constructor
 *                                         Assignment Operator
 *                                         insert
 *                                         remove
 *                                         deleteRoot
 *                                         exists
 *                                         sucessor
 *                                         traversals
 *                                         getNumNodes / add / decrement
 *                                         getHeight
 *                                         getRoot
 *                                         Friend Operator<<
 *                                         Friend Operator>>
 *                                         ~Destructor
 *                             : private :
 *                                         copyBst
 *                                         clearBst
 *                                         helper functions
 *
 *
 *
 ******************************************************************************* 
 *
 *                        Included Libraries
 *
 *******************************************************************************
 *******************************************************************************
*/
//#include "Comparable.h"   //ensure class is implemented - allows modularity
#include <string>           //for strings
#include <algorithm>        //for math function
#pragma once                //protect compiling

class Bst
{
   private:
      struct BstNode
      {
         /**
          *  DefaultConstructor BstNode
          *  @pre None
          *  @post BstNode has Comparable key and left/right set to nullptr.
          */
         BstNode() : data(nullptr),left(nullptr), right(nullptr) {};

         /**
          *  Overload Constructor BstNode
          *  @pre None
          *  @post BstNode has Comparable key and left/right set to nullptr.
          */
         BstNode(Comparable* datum) : data(datum), left(nullptr), right(nullptr) {};

         // Comparable object
         Comparable* data = nullptr;

         //Left subtree
         BstNode* left = nullptr;

         //Right subtree
         BstNode* right = nullptr;
      };

      int numNodes;//holds number of nodes.
      BstNode *root;// start of tree
      
      //copies tree
      BstNode* copyTree(const BstNode *oldTreePtr);
      
      //Traversal preorder
      void preorder(BstNode* nodePtr) const;

      //Traversal inorder
      void inorder(BstNode* nodePtr) const;

      //Traversal postorder
      void postorder(BstNode* nodePtr) const;
      
      //get height of tree
      int getHeight(BstNode* nodePtr) const;

      //clears the tree
      void makeEmpty(BstNode*& rootPtr);
   public:
      //Default constructor
      Bst();

      //Copy constructor
      Bst(const Bst& aTree);

      //assignment operator
      Bst& operator=(const Bst& aTree);

      //insert a value
      bool insert(Comparable* datum);
      
      //insert helper
      bool insert(BstNode *root, Comparable* datum);

      //removes a value from tree
      bool remove(Comparable* datum);
      
      //removes a value from tree
      bool remove(BstNode *&root, Comparable* datum);

      //removes a value from tree
      void deleteRoot(BstNode *&root);

      //removes a value from tree
      bool exists(Comparable* datum);
      
      //removes a value from tree
      bool exists(BstNode* root, Comparable* datum);

      //removes a value from tree
      Comparable* successor(BstNode *&root);
      
      //returns the node if a value exists
      Comparable* search(Comparable* datum);

      //helps search for nodes with value
      Comparable* search(BstNode *nodePtr, Comparable* datum);
      
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
      BstNode* getRoot() const;
      
      //get height of tree
      int getHeight();
      
      //get number of nodes
      int getNumNodes() const;
   
      //destructor
      virtual ~Bst();

      friend class Store;
   
};// end Bst 
