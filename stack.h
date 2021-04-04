#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct Node
{
    char c;
    struct Node *next;

}*pNode;

typedef struct Stack
{
    pNode first;
    int len;

}*pStack;

pStack Create_stack();
void Push_front_stack(pStack ps,char ch);
char Pop_front_stack(pStack ps);
int Is_empty_stack(pStack ps);
void Show_stack(pStack ps);
void Clear_stack(pStack ps);

#endif
