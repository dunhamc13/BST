#include <iostream>
#include "BST.h"
using namespace std;

int main ()
{
   BST aTree = BST();

   //create random values for 50 nodes with data between 1-100
  // for (int i = 0; i < 3; i++)
   {
      int five = 5;//rand() % 100 + 1;
      int four = 4;//rand() % 100 + 1;
      int six = 6;//rand() % 100 + 1;
      int three = 3;//rand() % 100 + 1;
      int seven = 7;//rand() % 100 + 1;
      int two = 2;//rand() % 100 + 1;
      int eight = 8;//rand() % 100 + 1;
      int dupe = 3;
      aTree.insert(five);
      aTree.insert(four);
      aTree.insert(six);
      aTree.insert(three);
      aTree.insert(seven);
      aTree.insert(two);
      aTree.insert(eight);

      cout << "test dupe value (next line should 0 for false," << endl;
      bool dupeV = aTree.insert(dupe);
      cout << dupeV << endl << endl;
   }//end for less than 50

   //test print
   cout<< "Preorder: " << endl;
   aTree.preorder();
   cout << endl << endl;
   cout << "Inorder: " << endl;
   aTree.inorder();      
   cout << endl << endl;
   cout << "Postorder: " << endl;
   aTree.postorder();
   cout << endl << endl;
   
   //test get heigth
   int height = aTree.getHeight();
   cout << "Height is: " << height << endl << endl;

   //test top of tree
   cout << "Test doesn't exist remove" << endl;
   bool remove = aTree.remove(0);
   cout << "Remove 0: " << remove << endl << endl;

   cout << "test leaf remove " << endl;
   aTree.remove(8);
   cout << "Remove 8: "  << endl << endl;
  
   cout << "Postorder: " << endl;
   aTree.postorder();
   cout << endl << endl;

   cout << "Inorder: " << endl;
   aTree.inorder();      
   cout << endl << endl;
   
   cout << "test middle remove" << endl;
   remove = aTree.remove(6);
   cout << "Remove 6: " << remove << endl << endl;

   cout << "Inorder: " << endl;
   aTree.inorder();      
   cout << endl << endl;
   
   cout << "test root" << endl;
  // remove = aTree.remove(5);
   cout << "Remove 5: " << remove << endl << endl;

   //test middle of tree
   remove = aTree.remove(50);
   cout << "Remove 1: " << remove << endl;
   remove = aTree.remove(51);
   cout << "Remove 2: " << remove << endl;
   remove = aTree.remove(52);
   cout << "Remove 3: " << remove << endl;

   //test bottom of tree
   remove = aTree.remove(98);
   cout << "Remove 1: " << remove << endl;
   remove = aTree.remove(99);
   cout << "Remove 2: " << remove << endl;
   remove = aTree.remove(100);
   cout << "Remove 3: " << remove << endl;

   return 0;
}//end main
