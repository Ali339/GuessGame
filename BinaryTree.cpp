// standard binary tree implementation

#include "BinaryTree.h"

template <class T>
BinaryTreeNode<T>* create_node(T& entry, BinaryTreeNode<T>* l_ptr, BinaryTreeNode<T>* r_ptr)
{
	BinaryTreeNode<T> *result_ptr;

	result_ptr = new BinaryTreeNode<T>;
	result_ptr->data    = entry;
	result_ptr->left    = l_ptr;
	result_ptr->right   = r_ptr;

	return result_ptr;
};

template <class T>
bool is_leaf(const BinaryTreeNode<T>& node)
{
	return (node.left == nullptr) && (node.right == nullptr);
};

