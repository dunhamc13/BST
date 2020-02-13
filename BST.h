#pramgma once

class BST
{
   public:
      
      //The Nodes for the tree
      struct BST_Node
      {
         int data;//data
         struct BST_Node* left;//left child
         struct BST_Node* right;//right child

         //default constructor
         BST_Node();
      }//

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
      bool insert(BST *node, int value);

      //removes a value from tree
      bool remove(int value);
      
      //removes a value from tree
      bool remove(BST_Node* root, int value);

      //returns the node if a value exists
      BST_Node* search(int value);

      //helps search for nodes with value
      BST_Node* search(BST_Node *nodePtr, int value);
      
      //Traversal preorder
      void preorder(const BST_Node *nodePtr) const;

      //Traversal inorder
      void preorder(const BST_Node *root) const;

      //Traversal postorder
      void preorder(const BST_Node *root) const;

      //add node to numNode
      void increaseNumNodes();

      //remove node to numNode
      void decreaseNumNodes();
   
      //get height of tree
      int getHeight();
   
      //destructor
      virtual ~BST();
   
   private:
      int numNodes;//holds number of nodes.
      BST_Node *root;// start of tree

      //copies tree
      BST_Node* copyTree(const BST_Node *oldTreePtr);
      
      //get height of tree
      int getHeight(BST_Node* nodePtr) const;

      //clears the tree
      void makeEmpty(BST_Node *root);
};// end BST 
