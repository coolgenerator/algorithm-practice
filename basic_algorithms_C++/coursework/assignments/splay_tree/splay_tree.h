#include "binary_tree_node.h"
#include <cstddef>
#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

template<typename T>
class splayTree {
public:
    splayTree() : root{nullptr}, count{0} { }
    ~splayTree() { clear(root); }
    // add
    void add(const T& item){
		root = insert(root, item);
    }
    // remove
    void remove(const T& item){
        root = remove(root, item);
    }
    // contains
    bool contains(const T& item){
        if(find(root, item) != nullptr) return true;
			return false;
    }
    // size
    size_t size(){
		return count;
    }
private:
    BinaryTreeNode<T>* root;
    size_t count;

    // left rotation - Tag
    BinaryTreeNode<T>* Zag(BinaryTreeNode<T>* N){
        BinaryTreeNode<T>* tmp = N->lchild;
        N->lchild = tmp->rchild;
        tmp->rchild = N;
        return tmp;
    }

    // right rotation - Tig
    BinaryTreeNode<T>* Zig(BinaryTreeNode<T>* N){
        BinaryTreeNode<T>* tmp = N->rchild;
        N->rchild = tmp->lchild;
        tmp->lchild = N;
        return tmp;
    }

    // find element
	BinaryTreeNode<T>* find(BinaryTreeNode<T>* node, const T& item){
			if(node->item == item) return node;
			if(node == nullptr) return nullptr;
			if(item < node->item) find(node->lchild, item);
			find(node->rchild, item);
	}

    // insert element
	BinaryTreeNode<T>* insert(BinaryTreeNode<T>* node, const T& item){
        if (node == nullptr){
            count++;
            return new BinaryTreeNode<T>(item);
        }
        if (item == node->item) return node;
        if (item < node->item){
            node->lchild = insert(node->lchild, item);
            node = Zag(node);
        } else {
            node->rchild = insert(node->rchild, item);
            node = Zig(node);
        }
        return node;
    }

    // remove element
	BinaryTreeNode<T>* remove(BinaryTreeNode<T>* node, const T& item){
        if (node == nullptr) return node;
        if (item < node->item)
            node->lchild = remove(node->lchild, item);
        else if (item > node->item)
            node->rchild = remove(node->rchild, item);
        else {
            BinaryTreeNode<T>* tmp;
            if (node->lchild == nullptr){
                tmp = node->rchild;
                delete node;
                count--;
                return tmp;
            } else if (node->rchild == nullptr){
                tmp = node->lchild;
                delete node;
                count--;
                return tmp;
            }
            tmp = node->rchild;
            while (tmp->lchild != nullptr) tmp = tmp->lchild;
            node->item = tmp->item;
            node->rchild = remove(node->rchild, tmp->item);
        }
        return node;
    }

    //delete all the nodes
	void clear(BinaryTreeNode<T>* node){
        if (node != nullptr) {
            clear(node->lchild);
            clear(node->rchild);
            delete node;
        }
    }
};

#endif