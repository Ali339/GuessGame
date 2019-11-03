#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T>
class BinaryTreeNode
{
public:
	T data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

};

template <class T>
BinaryTreeNode<T>* create_node(T& entry, BinaryTreeNode<T>* l_ptr=nullptr, BinaryTreeNode<T>* r_ptr=nullptr);

template <class T>
bool is_leaf(const BinaryTreeNode<T>&);



#endif // BINARYTREE_H
