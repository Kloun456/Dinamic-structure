#include <stdio.h>
#include <stdlib.h>
#include "Binary_tree.h"

int main()
{
    NODE *p, *root = 0;
    root = Add_node(8,root);
    root = Add_node(3,root);
    root = Add_node(6,root);
    root = Add_node(10,root);
    root = Add_node(1,root);
    root = Add_node(4,root);
    root = Add_node(7,root);
    Del_tree(root,6);
    printf("%d",root->left->right->key);


    /*QUEUE *pq = Create_queue();

    //1
    Fill_queue(pq);
    printf("Main queue:\n");
    Show_queue(pq);
    printf("\nQueue after operations:\n");
    Greatest_element(pq);
    Show_queue(pq);

    //2
    Section(pq);
    printf("\nQueue after operations:\n");
    Show_queue(pq);*/
}
