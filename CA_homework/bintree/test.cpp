/*
 *    CS110 Computer Architecture Homework 7
 *
 */

#include <iostream>
#include "bintree.h"


using namespace std;

int main(){

    binTree<int> tree;
    int nums[] = {3, 2 , -1 , 1 , 8 , 4 , 6,  5 , 9, -2};
    for(int i = 0; i < sizeof(nums) / sizeof(int); i++){
        tree.insert(nums[i]);
        cout<<"Inserted "<<nums[i]<<endl;
    }
    cout << 1<< endl;
    const int ARRAY_SIZE = 32;
    cout << 1<< endl;
    int arr[ARRAY_SIZE];
    cout << 1<< endl;
    printf("Postorder:\n");
    tree.postorder(arr,ARRAY_SIZE);
    for(int i = 0; i < tree.size(); i++){
        cout<<" "<< arr[i];
    }
    cout<<endl;
    return 0;
}
  /* cout<<"\nIterator Postorder:\n"<<endl;
   for(binTree<int>::postorder_iterator it = tree.post_begin(); it != tree.post_end(); it++){
       cout<<"Printing "<<*it<<endl;

       // editing is not really usefull because it might cause the bintree to not be a binary search tree anymore ...
       // but maybe a complex type is used where only one element (the "key") is not changed but the other is...
       *it += 5;

   }
   cout<<endl;*/


//
    /* Correct orders for the given example:

    Input:     int nums[] = {3, 2 , -1 , 1 , 8 , 4 , 6,  5 , 9, -2};

    Preorder:
    3 2 -1 -2 1 8 4 6 5 9
    Inorder:
    -2 -1 1 2 3 4 5 6 8 9
    Postorder:
    -2 1 -1 2 5 6 4 9 8 3

    */


    /* Uncomment to start testing the const correcness ...

    const binTree<int> treeConst(tree);

    cout<<"\nConst Iterator Preorder:\n"<<endl;
    for(binTree<int>::const_preorder_iterator it = treeConst.pre_begin(); it != treeConst.pre_end(); it++){
      cout<<"Printing "<<*it<<endl;
    //   *it += 5;    // this shouldn't work!!!
    }

    */
