

#include <iostream>
using namespace std;

template <class T>
binTree<T>::treeNode<T>::treeNode(){}
template <class T>
binTree<T>::treeNode<T>::treeNode(T & num, treeNode<T> parent, treeNode<T> left_child, treeNode<T> right_child){
	data = num;
	_parent = parent;
	_left_child = left_child;
	_right_child = right_child;
}

template <class T>
binTree<T>::treeNode<T>::~treeNode(){}


//
//
// The implementation for the treeNode subclass follows here!
//
//
//                T R E E   N O D E
//
//
//


    /* Fill in this part */

template <class T>
binTree<T>::binTree(){
	_size = 0;
	_root = NULL;
}

template <class T>
binTree<T>::binTree(binTree<T> & obj){
	_size = obj.size();
	_root = obj.show_root();
}

template <class T>
binTree<T>::~binTree(){}

template <class T>
treeNode<T> * binTree<T>::show_root(){
	return _root;
}

template <class T>
int binTree<T>::size(){
	return _size;
}


template <class T>
void binTree<T>::insert(const T & val){
	treeNode<T> * x = new treeNode<T>;
	X = treeNode(val);
	_size++;
	_insert(_root, x)
}

template <class T>
void binTree<T>::_insert(treeNode<T> * &tree, treeNode<T> * z){
	treeNode<T> *y = NULL;
	treeNode<T> *x = tree;
	while (x){
		y = x;
		if (z.show_data() < x.show_data())	x = x._left_child;
		else								x = x._right_child;
	}
	z._parent = y;
	if (y = NULL) tree = z;
	else if (z.show_data() < y.show_data())	y._left_child = z;
	else									y._right_child = z;
}


template <class T>
int binTree<T>::size() const{
	return _size;
}

template <class T>
bool binTree<T>::exists(const T & val) const{
	T * arr = new T[_size];
	_preorder(arr, _size, _root);
	for (int i = 0; i < _size, i++){
		if val = T[i] return true;
	}
	return false;
}

template <class T>
void binTree<T>::preorder(T * arr, int arr_size) const{
	_preorder(arr, arr_size, _root);
}

template <class T>
void binTree<T>::_preorder(T * arr, int arr_size, treeNode<T> * node){
	if (node){
		*arr = node.show_data();
		*arr++;
		_preorder(arr, arr_size, node._left_child);
		_preorder(arr, arr_size, node._right_child);
	}
}

template <class T>
void binTree<T>::inorder(T * arr, int arr_size) const{
	_inorder(arr, arr_size, _root);
}

template <class T>
void binTree<T>::_inorder(T * arr, int arr_size, treeNode<T> *node){
	if (node){
		_inorder(arr, arr_size, node._left_child);
		*arr = node.show_data();
		*arr++;
		_inorder(arr, arr_size, node._right_child);
	}
}

template <class T>
void binTree<T>::postorder(T * arr, int arr_size) const{
	_postorder(arr, arr_size, _root);
}

template <class T>
void binTree<T>::_postorder(T * arr, int arr_size, treeNode<T> node){
	if (node){
		_postorder(arr, arr_size, node._left_child);
		_postorder(arr, arr_size, node._right_child);
		*arr = node.show_data();
		*arr++;
	}
}

template <class T>
int binTree<T>::size(){
	return _size;
}
//
//
// The implementation for the binTree subclass follows here!
//
//
//                B I N    T R E E
//
//
//


// One possible implementation of the standard constructor of the binTree ...




// One possible implementation of pre_begin ...
template <class T>
  typename binTree<T>::preorder_iterator binTree<T>::pre_begin(){
  	return preorder_iterator(root);
  }


    /* Fill in this part */



//
//
// The implementation for the iterator subclasses follow here!
//
//
//                   I T E R A T O R S
//
//
//


// this might not be the correct solution yet....
template <class T>
	typename binTree<T>::preorder_iterator & binTree<T>::preorder_iterator::operator++(){

        /* Fill in this part */

        return *this;
    }



    /* Fill in this part */
