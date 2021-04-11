#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct Node
{
    int c;
    struct Node *next;
}NODE;

typedef struct Stack
{
    NODE *first;
    int len;
}STACK;

STACK *Create_stack();
void Push_front_stack(STACK *ps,int ch);
int Pop_front_stack(STACK *ps);
int Is_empty_stack(STACK *ps);
void Show_stack(STACK *ps);
void Clear_stack(STACK *ps);

#endif
