using namespace std;

main ()
{
   BST aTree = BST();
   
   //create random values for 50 nodes with data between 1-100
   for (int i = 0; i < 50; i++)
   {
      int value = rand() % 100 + 1;
      aTree.insert(value);
   }//end for less than 50

   //test print
   cout<< "Preorder: " << endl;
   aTree.preorder();
   cout << endl;
   cout << "Inorder: " << endl;
   aTree.inorder();      
   cout << endl;
   cout << "Postorder: " << endl;
   aTree.postorder();
   
   //test get heigth
   int height = aTree.getHeight();
   cout << "Height is: " << height << endl;

   //test top of tree
   bool remove = aTree.remove(1);
   cout << "Remove 1: " << remove << endl;
   remove = aTree.remove(2);
   cout << "Remove 2: " << remove << endl;
   remove = aTree.remove(3);
   cout << "Remove 3: " << remove << endl;

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
