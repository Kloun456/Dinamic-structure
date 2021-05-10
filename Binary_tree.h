#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

typedef struct Node
{
    int key;
    struct Node *left, *right;
}NODE;

NODE *Add_node(int x, NODE *root);
void *Pre_order(NODE *root);
void *Post_order(NODE *root);
void *In_order(NODE *root);
NODE *Find_tree(NODE *root, int val);
int Right_most(NODE *root);
NODE *Del_tree(NODE *root, int val);
void Nnodes(NODE *root, int *p);
void Del_all(NODE *root);

#endif
