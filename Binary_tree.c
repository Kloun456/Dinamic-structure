#include "Binary_tree.h"

NODE *Add_node(int x, NODE *root)
{
    if (!root)
    {
        root = (NODE *) malloc(sizeof(NODE));
        root->key = x;
        root->left = 0;
        root->right = 0;
    }
    else
    {
        if (x < root->key)
            root->left = Add_node(x,root->left);
        else
            root->right = Add_node(x,root->right);
    }
    return root;
}

void *Pre_order(NODE *root)
{
    if(root)
    {
        printf("%d; ", root->key);
        Pre_order(root->left);
        Pre_order(root->right);
    }
}

void *Post_order(NODE *root)
{
    if(root)
    {
        Pre_order(root->left);
        Pre_order(root->right);
        printf("%d; ", root->key);
    }
}

void *In_order(NODE *root)
{
    if(root)
    {
        Pre_order(root->left);
        printf("%d; ", root->key);
        Pre_order(root->right);
    }
}

NODE *Find_tree(NODE *root, int val)
{
    if (!root)
        return 0;
    if (val == root->key)
        return root;
    if (val < root->key)
        return Find_tree(root->left,val);
    else
        return Find_tree(root->right,val);
}

int Right_most(NODE *root)
{
    while (root->right)
        root = root->right;
    return root->key;
}

NODE *Del_tree(NODE *root, int val)
{
    if (!root)
        return 0;
    if (root->key == val)
    {
        if (!(root->left) && !(root->right))
        {
            free(root);
            return 0;
        }
        if (!(root->right) && root->left)
        {
            NODE *temp = root->left;
            free(root);
            return temp;
        }
        if (!(root->left) && root->right)
        {
            NODE *temp = root->right;
            free(root);
            return temp;
        }
        root->key = Right_most(root->left);
        root->left = Del_tree(root->left,root->key);
        return root;
    }
    if (val < root->key)
    {
        root->left = Del_tree(root->left,val);
        return root;
    }
    if (val >= root->key)
    {
        root->right = Del_tree(root->right,val);
        return root;
    }
    return root;
}

void Nnodes(NODE *root, int *p)
{
    if (!root)
        return;
    (*p)++;
    Nnodes(root->left,p);
    Nnodes(root->right,p);
}

void Del_all(NODE *root)
{


}
