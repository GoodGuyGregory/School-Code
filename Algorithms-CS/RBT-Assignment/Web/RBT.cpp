#include <iostream>
using namespace std;

enum color { red, black };

class RBTNodeRecord {
public:
    int value;
    color color = red;
    RBTNodeRecord* left = NULL;
    RBTNodeRecord* right = NULL;
    RBTNodeRecord* parent = NULL;
};//RBTNodeRecord

class RBT {
public:
    RBTNodeRecord* root;
    RBT();
    ~RBT();
    RBTNodeRecord* insertNode(RBTNodeRecord* x, RBTNodeRecord* t);
    void inorderTraversal(RBTNodeRecord* root);
    void preorderTraversal(RBTNodeRecord* root);
    void insert(RBTNodeRecord* x);
};//RBT

RBT::RBT() {
    root = NULL;
}//RBT

RBT::~RBT() {
}//~RBT

RBTNodeRecord* RBT::insertNode(RBTNodeRecord* x, RBTNodeRecord* t) {
    if (t == NULL)
        t = x;
    else if (x->value < t->value) {
        x->parent = t;
        t->left = insertNode(x, t->left);
    }//else if
    else if (x->value > t->value) {
        x->parent = t;
        t->right = insertNode(x, t->right);
    }//else if
    return t;
}

void RBT::inorderTraversal(RBTNodeRecord* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    string nodeColor = "";
    if (root->color == black)
        nodeColor = "Black";
    else
        nodeColor = "Red";
    cout << root->value << "," << nodeColor << ",";
    inorderTraversal(root->right);
}//inorderTraversal

void RBT::preorderTraversal(RBTNodeRecord* root) {
    if (root == NULL)
        return;
    string nodeColor = "";
    if (root->color == black)
        nodeColor = "Black";
    else
        nodeColor = "Red";
    cout << root->value << ", " << nodeColor << ",";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}//preorderTraversal

void RBT::insert(RBTNodeRecord* x) {
    root = insertNode(x, root);
}

void left_rotate(RBT* T, RBTNodeRecord* x) {
    RBTNodeRecord* y;
    y = x->right;
    /* Turn y's left sub-tree into x's right sub-tree */
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    /* y's new parent was x's parent */
    y->parent = x->parent;
    /* Set the parent to point to y instead of x */
    /* First see whether we're at the root */
    if (x->parent == NULL) T->root = y;
    else
        if (x == (x->parent)->left)
            /* x was on the left of its parent */
            x->parent->left = y;
        else
            /* x must have been on the right */
            x->parent->right = y;
    /* Finally, put x on y's left */
    y->left = x;
    x->parent = y;
}//left_rotate

void right_rotate(RBT* T, RBTNodeRecord* x) {
    RBTNodeRecord* y;
    y = x->left;
    /* Turn y's right sub-tree into x's left sub-tree */
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    /* y's new parent was x's parent */
    y->parent = x->parent;
    /* Set the parent to point to y instead of x */
    /* First see whether we're at the root */
    if (x->parent == NULL) T->root = y;
    else
        if (x == (x->parent)->right)
            /* x was on the right of its parent */
            x->parent->right = y;
        else
            /* x must have been on the left */
            x->parent->left = y;
    /* Finally, put x on y's right */
    y->right = x;
    x->parent = y;
}//right_rotate

void rb_insert(RBT* T,  RBTNodeRecord* x) {
    /* Insert in the tree in the usual way */
    T->insert(x);
    /* Now restore the red-black property */
    x->color = red;
    while ((x != T->root) && (x->parent->color == red)) {
        if (x->parent == x->parent->parent->left) {
            /* If x's parent is a left, y is x's right 'uncle' */
            RBTNodeRecord* y = x->parent->parent->right;                    
            if (y != nullptr && y->color == red) {
                /* case 1 - change the colors */
                x->parent->color = black;
                y->color = black;
                x->parent->parent->color = red;
                /* Move x up the tree */
                x = x->parent->parent;
            }
            else {
                /* y is a black node */
                if (x == x->parent->right) {
                    /* and x is to the right */
                    /* case 2 - move x up and rotate */
                    x = x->parent;
                    left_rotate(T, x);
                }
                /* case 3 */
                x->parent->color = black;
                x->parent->parent->color = red;
                right_rotate(T, x->parent->parent);
            }
        }
        else {
            /* repeat the "if" part with right and left
             exchanged */
            RBTNodeRecord* y = x->parent->parent->left;
            if (y != nullptr && y->color == red) {
                /* case 1 - change the colors */
                x->parent->color = black;
                y->color = black;
                x->parent->parent->color = red;
                /* Move x up the tree */
                x = x->parent->parent;
            }
            else {
                /* y is a black node */
                if (x == x->parent->left) {
                    /* and x is to the left */
                    /* case 2 - move x up and rotate */
                    x = x->parent;
                    right_rotate(T, x);
                }
                /* case 3 */
                x->parent->color = black;
                x->parent->parent->color = red;
                left_rotate(T, x->parent->parent);
            }
        }
    }
    /* color the root black */
    T->root->color = black;
}

int main() {
    RBT tree;
    RBTNodeRecord treeNode;
    treeNode.value = 10;
    rb_insert(&tree, &treeNode);
    RBTNodeRecord treeNode2;
    treeNode2.value = 20;
    rb_insert(&tree, &treeNode2);
    tree.inorderTraversal(tree.root);
 }