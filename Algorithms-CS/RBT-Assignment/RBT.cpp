// Implement following functions of a RBT in a proper C++ program.You should write your main function to test all other functions.Turn in your working code with outputs.Outputs should show
// inorder traversal of the RBT including color of the node.
#include <iostream>
using namespace std;

/* a red-black tree's node structure. you may write a class instead of a struct */
class t_red_black_node
{
public:
    enum class colour
    {
        red,
        black
    }; 
    int value = 0;
    t_red_black_node* left = NULL;
    t_red_black_node* right = NULL;
    t_red_black_node* parent = NULL;
    colour cvalue = t_red_black_node::colour::red;

    t_red_black_node(int x)
    {
        this->value = x;
    }
};

class redblackTree {
    public:
        t_red_black_node* root = NULL;
    
    redblackTree() {
        root = NULL;
    }


    t_red_black_node* tree_insert(t_red_black_node* x, t_red_black_node* z)
    {
        if (z == NULL)
        {
            x = z;
        }
        else if (x->value < z->value)
        {
            x->parent = z;
            z->left = tree_insert(x, z->left);
        }

        else if (x->value > z->value)
        {
            x->parent = z;
            z->right = tree_insert(x, z->right);
        }
        return z;
    }

    void insert(t_red_black_node* x) {
        root = tree_insert(x, root);
    }


};


void left_rotate(redblackTree* T, t_red_black_node* x)
{
    t_red_black_node* y;
    y = x->right;
    /* Turn y's left sub-tree into x's right sub-tree */
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    /* y's new parent was x's parent */
    y->parent = x->parent;
    /* Set the parent to point to y instead of x */
    /* First see whether we're at the root */
    if (x->parent == NULL) {
        T->root = y;
    }
    else { 
    if (x == (x->parent)->left)
        /* x was on the left of its parent */
        x->parent->left = y;
    else
        /* x must have been on the right */
        x->parent->right = y;
    }
    /* Finally, put x on y's left */
    y->left = x;
    x->parent = y;
}

void right_rotate(redblackTree* T, t_red_black_node* x)
{
    t_red_black_node* y;
    y = x->left;
    /* Turn y's left sub-tree into x's right sub-tree */
    x->left = y->right;
    if (y->right != NULL) {
        y->right->parent = x;
    }
    /* y's new parent was x's parent */
    y->parent = x->parent;
    /* Set the parent to point to y instead of x */
    /* First see whether we're at the root */
    if (x->parent == NULL) {
        T->root = y;
    }
    else { 
    if (x == (x->parent)->right)
        /* x was on the left of its parent */
        x->parent->right = y;
    else
        /* x must have been on the right */
        x->parent->left = y;
    }
    /* Finally, put x on y's left */
    y->right = x;
    x->parent = y;
}

void rb_insert(redblackTree* T, t_red_black_node* x)
{
    /* Insert in the tree in the usual way */
    T->insert(x);
    /* Now restore the red-black property */
    x->cvalue = t_red_black_node::colour::red;
    while ((x != T->root) && (x->parent->cvalue == t_red_black_node::colour::red))
    {
        if (x->parent == x->parent->parent->left)
        {
            /* If x's parent is a left, y is x's right 'uncle' */
            t_red_black_node* y = x->parent->parent->right;
            if (y != nullptr && y->cvalue == t_red_black_node::colour::red)
            {
                /* case 1 - change the colours */
                x->parent->cvalue = t_red_black_node::colour::black;
                y->cvalue = t_red_black_node::colour::black;
                x->parent->parent->cvalue = t_red_black_node::colour::red;
                /* Move x up the tree */
                x = x->parent->parent;
            }
            else
            {
                /* y is a black node */
                if (x == x->parent->right)
                {
                    /* and x is to the right */
                    /* case 2 - move x up and rotate */
                    x = x->parent;
                    left_rotate(T, x);
                }
                /* case 3 */
                x->parent->cvalue = t_red_black_node::colour::black;
                x->parent->parent->cvalue = t_red_black_node::colour::red;
                right_rotate(T, x->parent->parent);
            }
        }
    else 
    {
        /* If x's parent is a right, y is x's left 'uncle' */
            t_red_black_node* y = x->parent->parent->left;
            if (y != nullptr && y->cvalue == t_red_black_node::colour::red)
            {
                /* case 1 - change the colours */
                x->parent->cvalue = t_red_black_node::colour::black;
                y->cvalue = t_red_black_node::colour::black;
                x->parent->parent->cvalue = t_red_black_node::colour::red;
                /* Move x up the tree */
                x = x->parent->parent;
            }
            else
            {
                /* y is a black node */
                if (x == x->parent->left)
                {
                    /* and x is to the left */
                    /* case 2 - move x up and rotate */
                    x = x->parent;
                    right_rotate(T, x);
                }
                /* case 3 */
                x->parent->cvalue = t_red_black_node::colour::black;
                x->parent->parent->cvalue = t_red_black_node::colour::red;
                left_rotate(T, x->parent->parent);
            }
    }
}
    /* Colour the root black */
    T->root->cvalue = t_red_black_node::colour::black;
}

int main()
{
    // Tree Object with Nodes
    redblackTree* test = new redblackTree;
    cout << "Tree Created: " << endl;
    
    // creates the values:
    cout << "Adding Values to The Tree" << endl;
    Node*


}