/*
 *  Binary Tree Header File
 *  Author: Jianzhong Liu, Xin Qin
 *  HW1, CS110 Computer Architecture, ShanghaiTech University
 *  Spring 2017
 */

#ifndef BINTREE_H
#define BINTREE_H

/*
 *  Struct for Tree Node
 *    Node Structure:
 *      - void * pointer to value
 *      - pointer to parent, NULL if root
 *      - pointer to left and right child, NULL if nonexistent
 */

typedef struct node{
  void * val;
  struct node * parent;
  struct node * left;
  struct node * right;
} Node;

/*

NOTICE: Please check for updates of associated files regularly.

WARNING: DO NOT MODIFY THIS HEADER FILE! We will not be using your header file during
grading so any modifications to pass compilation or simplify implementation will
NOT work. Please strictly abide by the instructions.

Instructions on Homework 1:


In this homework, you will implement a binary search tree using C.


The basics of binary search trees are readily available on the internet. Any ambiguity
on the instructions should be discussed on Piazza or during the discussion sessions. The
instructions in this header file will be constantly updated so please pay attention to
any notifications on source file updates.


We will use linked nodes to implement the BST. This BST will also offer generic programming
functionality by using general pointers (void *). This will be discussed later.


The structure of the node has been laid out for you. The fields in the struct should be of
interest to you:

  - "val" is a general purpose pointer holding the address of the value. Note that the
    value should be dynamically allocated to avoid use-after-free scenarios while using
    stack data.

  - "parent" is a pointer pointing to the parent of the current node. If the node is the root
    node of the tree, the "parent" pointer should be NULL.

  - "left" and "right" are pointers referring to the left and right child of the current node.
    If either child is nonexistent, the corresponding pointer should be NULL.


Note that we would use a root node to represent a BST. If the root node is represented by a
NULL pointer, then we would assume that the tree is empty.


You will have to implement the following functions:

  - "insertNode": A function to insert a new node with value determined by "val" into a BST
    with root node "root". "cmp" and "alloc" are two function pointers allowing for generics.
    "cmp" is a function tasked with comparing the values that two general purpose pointers point
    to. "alloc" is a function tasked with allocating the memory for a given type and transferring
    the data to the allocated memory.
    If NULL is passed as the root node the function should create a new tree.
    This function should return a pointer to the created node or the root node on error.

  - "searchNode": A function to search if a given value referred by "val" can be found in the
    BST with root node "root". As with "insertNode", "cmp" is a function pointer referring to
    a function to compare the two values for a predetermined type.
    This function should return a pointer to the found node or NULL on error.

  - "removeNode": A function to remove a node with value given by "val" from a BST with root
    node "root". "cmp" is a function pointer referring to a function to compare two values for
    a predetermined type. "del" is a function pointer pointing to a function that frees a
    piece of dynamically allocated memory for a predetermined type.
    This function should return ... tbd.

  - "freeTree": A function to free all the dynamically allocated memory used by the tree. "del"
    is a function pointer with the same functionality as the one in "removeNode".

  - "compareInt": The "cmp" function for comparing integer values.

  - "deleteInt": The "del" function for freeing memory allocated for integers.

  - "allocInt": The "alloc" function for allocating memory for integers.

Additional Requirements:

  - The comparison function with inputs a and b will return -1 if a < b, return 0 if a==b and
    return 1 if a > b.

  - You may not use any header file apart from "bintree.h" and <stdlib.h>. Any other library
    is unnecessary to complete the homework and will not be linked during compilation.

  - No memory leaks are allowed. We will deduct your scores for each and every memory leak found.


Compilation will be conducted using gcc with the compile flags given on the homework website. We
will not be using your copy of Makefile so your attempts to pass compilation through modifying
Makefile will not work.

*/

Node * insertNode(Node * root, void * val, int (*cmp)(const void * a, const void * b), void *(*alloc)(const void *));

Node * searchNode(Node * root, void * val, int (*cmp)(const void * a, const void * b));

Node * removeNode(Node * root, void * val, int (*cmp)(const void * a, const void * b), void (*del)(const void *));

void freeTree(Node * root, void (*del)(const void *));

int compareInt(const void * a, const void * b);

void deleteInt(const void * a);

void * allocInt(const void * a);

#endif
