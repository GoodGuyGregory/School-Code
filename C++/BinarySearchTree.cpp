#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template <class T>
class BinarySearchTree
{
private:
    class TreeNodeRecord
    {
    public:
        T value;
        TreeNodeRecord *left;
        TreeNodeRecord *right;
    }; //TreeNodeRecord class

    TreeNodeRecord *root;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    //void clear();
    //void transferFrom(BinarySearchTree& source);
    //BinarySearchTree& operator=(BinarySearchTree& rhs);
    //Operations to Write
    void add(T &x);
    bool find(T &x);
    void inorder();
    //Still to write
    //remove, preorder, postorder, balance
    //end Operations to Write
    //balances tree automatically if there is a unbalance on one side of two (left or right dominant)
    void treeBalance();
    bool needsBalancing();

private:
    //void reclaimAllNodes(TreeNodeRecord*& p);
    //void copyNodes(TreeNodeRecord*& toP, TreeNodeRecord*& fromP);
    //int countNodes(TreeNodeRecord* p);
    void insertAt(T &x, TreeNodeRecord *&p);
    void inorder(TreeNodeRecord *p, vector<TreeNodeRecord *> v);
    bool search(T &x, TreeNodeRecord *p);
    void traverseInorder(TreeNodeRecord *p);
    void balance(TreeNodeRecord *&p, vector<TreeNodeRecord *> &v, int start, int end);
    int height(TreeNodeRecord *&p);
    bool helperNeedsBalancing(TreeNodeRecord *&p);

}; //BinarySearchTree class

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
}
template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    delete (root);
    //reclaimAllNodes(root);
}

template <class T>
void BinarySearchTree<T>::balance(TreeNodeRecord *&p, vector<TreeNodeRecord *> &v, int start, int end)
{
    if (start <= end)
    {
        int mid = (start + end) / 2; //compute mid

        p = mid;
        p->left = NULL;  //recursive call to left of mid
        p->right = NULL; //recursive call to right of mid
    }                    //if
} //balance

/*template <class T>
    void BinarySearchTree<T>::clear()
    {
        reclaimAllNodes(root);
        root = NULL;
    }

template <class T>
    void BinarySearchTree<T>::transferFrom(BinarySearchTree& source)
    {
        reclaimAllNodes(root);//this deletes all values from q1
        root = source.root;
        source.root = NULL;
        
    }
template <class T>
    BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree& rhs)
    {
        reclaimAllNodes(root);
        copyNodes(root, rhs.root);
        return *this;
    }
 
template <class T>
    void BinarySearchTree<T>::reclaimAllNodes(TreeNodeRecord*& p)
    {
        if (p != NULL){
            reclaimAllNodes(p->left);
            
            reclaimAllNodes(p->right);
            delete(p);
        }//if
            
    }

template <class T>
    void BinarySearchTree<T>::copyNodes(TreeNodeRecord*& toP, TreeNodeRecord*& fromP)
    {
        if (fromP == NULL)
            toP = NULL;
        else{
            toP = new TreeNodeRecord;
            toP->value=fromP->value;
            copyNodes(toP->next, fromP->next);
        }//else
    }
template <class T>
    int BinarySearchTree<T>::countNodes(TreeNodeRecord* p)
    {
        if (p == NULL)
            return 0;
        else
            return 1 + countNodes(p->next);
    }
*/

template <class T>
int BinarySearchTree<T>::height(TreeNodeRecord *&p)
{
    if (p == NULL)
    {
        return 0;
    } //if
    else
    {
        return 1 + max(p->left + p->right);
    } //else

} //height

template <class T>
void BinarySearchTree<T>::treeBalance()
{
    vector<TreeNodeRecord *> v;
    inorder(root, v);
    balance(root, v, 0, v.size() - 1);

} //treeBalance

template <class T>
bool BinarySearchTree<T>::needsBalancing()
{

    return helperNeedsBalancing(root);

} //needsBalancing

template <class T>
bool BinarySearchTree<T>::helperNeedsBalancing(TreeNodeRecord *&p)
{
    if (p == NULL)
    {
        return false;
    } //if
    else
    {
        if (height(p) > 1)
        {
            return true;
        } //else
        else
        {
            return helperNeedsBalancing(p->left) && helperNeedsBalancing(p->right);
        }

    } //else
}

template <class T>
void BinarySearchTree<T>::insertAt(T &x, TreeNodeRecord *&p)
{
    if (p == NULL)
    {
        TreeNodeRecord *add = new TreeNodeRecord;
        add->value = x;
        add->right = NULL;
        add->left = NULL;
        p = add;
    } //if
    else
    {
        if (p->value > x)
            BinarySearchTree<T>::insertAt(x, p->left);
        else if (p->value < x)
            BinarySearchTree<T>::insertAt(x, p->right);
        else
            ;
    } //else
}

template <class T>
void BinarySearchTree<T>::add(T &x)
{
    insertAt(x, root);
} //add

template <class T>
bool BinarySearchTree<T>::find(T &x)
{
    return search(x, root);
} //find

template <class T>
void BinarySearchTree<T>::inorder(TreeNodeRecord *p, vector<TreeNodeRecord *> v)
{
    if (p != NULL)
    {
        //call inorder to left
        inorder(p->left, v);
        v.push_back(p);
        //call inorder to right
        inorder(p->right, v);

    } //if

} //inorder

template <class T>
bool BinarySearchTree<T>::search(T &x, TreeNodeRecord *p)
{
    if (p == NULL)
        return false;
    else
    {
        if (p->value == x)
            return true;
        else if (p->value < x)
            return search(x, p->right);
        else
            return search(x, p->left);
    } //else
} //search

template <class T>
void BinarySearchTree<T>::inorder()
{
    traverseInorder(root);
} //inorder

template <class T>
void BinarySearchTree<T>::traverseInorder(TreeNodeRecord *p)
{
    if (p != NULL)
    {
        traverseInorder(p->left);
        cout << p->value << " ";
        traverseInorder(p->right);
    } //if
} //inorder

int main()
{
    //For find, 1 = true, 0 = false

    BinarySearchTree<int> b1, b2;
    int x = 5;
    b1.add(x);
    x = 12;
    b1.add(x);
    x = 21;
    b1.add(x);
    x = 3;
    b1.add(x);
    x = 7;
    b1.add(x);
    x = 7;
    b1.add(x);
    x = 18;
    b1.add(x);
    x = 4;
    b1.add(x);
    x = 21;
    cout << "Found 21 in b1 = " << b1.find(x) << endl;
    x = 15;
    cout << "Found 15 in b2 = " << b1.find(x) << endl;
    b1.inorder();
    cout << endl;
    x = 34;
    b1.add(x);
    x = 25;
    b1.add(x);
    x = 14;
    b1.add(x);
    b1.inorder();
    cout << endl;
    x = 34;
    cout << "Found 34 in b1 = " << b1.find(x) << endl;
    x = 3;
    cout << "Found 3 in b1 = " << b1.find(x) << endl;
    x = 30;
    cout << "Found 30 in b1 = " << b1.find(x) << endl;

    b1.treeBalance();

    return 0;
} //main