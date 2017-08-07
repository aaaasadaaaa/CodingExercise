/*
 *    CS110 Computer Architecture Homework 7
 *    Header File for binTree
 *    May 24, 2017
 *
 */

#ifndef BIN_TREE_H
#define BIN_TREE_H


/*
 *
 * The Binary Search Tree Class
 *
 */

template <class T>
class binTree {
private:
    treeNod<T> * _root;
    int _size;
    /* Fill in this part */

public:


  /* The treeNode that forms the search tree.
     Has to be implemented as subclass of the binTree.
     The .h file only contains declarations, the implementations
     go into the .hpp file!
  */
  class treeNode {
    private:

    // the data to be saved - do not change this declaration!
        T data;

    /* Fill in other missing items */
    public:
        treeNode<T> * _parent;
        treeNode<T> * _left_child;
        treeNode<T> * _right_child;
        treeNode();
        treeNode(T & num, treeNode<T> parent = NULL, treeNode<T> left_child = NULL, treeNode<T> right_child = NULL);
        ~treeNode();
        T show_data(){return data};
  };


  // For the iterators you have to implement the following functions:
  // - Two comparison operators (equal and not equal)
  // - The tow standard data access oerators (one returning T& and one T*)
  //      * The const iterators of course have to return const versions for data access
  // - The pre-increment and the post-increment operator (e.g. ++i  and  i++)
  //
  // Implement, as sub-classes of binTree:
  // preorder_iterator & const_preorder_iterator
  // inorder_iterator & const_inorder_iterator
  // postorder_iterator & const_postorder_iterator
  //
  // As those iterators share lots of functionality it might be good to use C++ techniques
  // to re-use the code - e.g. inheritance ( e.g. class preorder_iterator: public iterator{};)
  //


  /* Declare the iterator classes here - implement in .hpp file! */



  /* Constructors */

  binTree();
  binTree(const binTree<T> & obj);

  /* Destructor */
  ~binTree();


  /* Inserts a node with the value val into the tree. If a node with an identical value exists, simply exit. */
  void insert(const T &val);

  /* Returns if a node with a given value exists in the tree. */
  bool exists(const T &val) const;
  /* Returns the number of items in the tree. */
  int size() const;

  treeNode<T> * show_root();
  /* Generate an array with items organized in preorder order. */
  void preorder(T *, int) const;
  /* Generate an array with items organized in inorder order. */
  void inorder(T *, int) const;
  /* Generate and array with items orgainzed in postorder order. */
  void postorder(T *, int) const;
  /* Various functions returning iterators */
  preorder_iterator pre_begin();
  preorder_iterator pre_end();

  inorder_iterator in_begin();
  inorder_iterator in_end();

  postorder_iterator post_begin();
  postorder_iterator post_end();

  /* Add according const versions for returning the const iterators */

};


/* Here we automatically include the actual implementation ... */
#include "bintree.hpp"

#endif
