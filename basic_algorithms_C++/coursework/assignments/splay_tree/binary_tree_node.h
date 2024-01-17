#ifndef BINARY_TREE_NODE
#define BINARY_TREE_NODE

template<typename T>
struct BinaryTreeNode
{
    T item;
    BinaryTreeNode<T>* parent;
    BinaryTreeNode<T>* lchild;
    BinaryTreeNode<T>* rchild;

    BinaryTreeNode(const T& item) : BinaryTreeNode<T>(item, nullptr, nullptr, nullptr) { } 

    BinaryTreeNode(const T& item, BinaryTreeNode<T>* parent) : BinaryTreeNode<T>(item, parent, nullptr, nullptr) { } 
    
    BinaryTreeNode(const T& item, BinaryTreeNode<T>* parent, BinaryTreeNode<T>* lchild, BinaryTreeNode<T>* rchild) 
        : item{item}, parent{parent}, lchild{lchild}, rchild{rchild} { } 
};

#endif /* BINARY_TREE_NODE */