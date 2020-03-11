// queueFromLinkedList.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>
using namespace std;

template <class T>

class BinarySearchTree
{
private:
	class TreeNodeRecord
	{
	public:
		T value;
		TreeNodeRecord* left;
        TreeNodeRecord* right;
	};//TreeNodeRecord
	TreeNodeRecord* root = NULL;
     
public:
	BinarySearchTree();
	~BinarySearchTree();
	void clear();
	void transferFrom(BinarySearchTree& source);
	BinarySearchTree& operator = (BinarySearchTree& rhs);
	//writing these myself
	void add(T& x);
    bool find(T& x);
    void inorder();
    
    T& getRoot();
private:
    void add(TreeNodeRecord*& p,T& x);//helper
    void inorder(TreeNodeRecord* p);
    bool find(TreeNodeRecord* p,T& x);
}; //BinarySearchTree

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}//BinarySearchTree

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	delete root;
}//~BinarySearchTree

template<class T>
void BinarySearchTree<T>::clear()
{
	reclaimAllNodes(root);
	root = NULL;
}//clear

template<class T>
void BinarySearchTree<T>::transferFrom(BinarySearchTree& source)
{
	reclaimAllNodes(root);
	root = source.root;
	source.head = NULL;
}//transferFrom

template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree& rhs)
{
	reclaimAllNodes(root);
	copyNodes(root, rhs.root);
	return *this;
}//operator=

template<class T>
void BinarySearchTree<T>::add(T& x)
{
	add(root, x);
}//enqueue

template<class T>
void BinarySearchTree<T>::add(TreeNodeRecord*& p, T& x)
{
    if(p==NULL)
    {
        TreeNodeRecord* n = new TreeNodeRecord;
        n->value =x;
        n->left = NULL;
        n->right = NULL;
        p = n;
    }//if
    else if(p->value > x)
    {
    add(p->left,x);
    }//elseif
    else if(p->value < x)
    {
    add(p->right,x);
    }//elseif
    else;
}//enqueue

template<class T>
T& BinarySearchTree<T>::getRoot()
{
	return root->value;
}//front

template<class T>
bool BinarySearchTree<T>::find(T& x)
{
    return find(root,x);
    
}//find

template<class T>
bool BinarySearchTree<T>::find(TreeNodeRecord* p,T& x)
{
    if (p == NULL)
         return false;
    if(p->value == x)
        return true;
    else if(x < p->value)
        return find(p->left,x);
    else if(x > p->value)
        return find(p->right,x);
    else return false;
     
    
    
}//find

template<class T>
void BinarySearchTree<T>::inorder()
{
    inorder(root);
}//inorder

template<class T>
void BinarySearchTree<T>::inorder(TreeNodeRecord* p)//helper
{
    if