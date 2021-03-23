#include "stack.h"



pStack Create_stack()
{
    pStack ps;
    ps = (pStack)malloc(sizeof(pStack));
    ps->first = 0;
    ps->len = 0;
    return ps;
}

void Push(pStack ps,char ch)
{
    pNode temp = ps->first;
    if (ps->first == 0)
    {
        ps->first = (pNode)malloc(sizeof(pNode));
        ps->first->c = ch;
        ps->first->next = 0;
    }
    else
    {
        ps->first = (pNode)malloc(sizeof(pNode));
        ps->first->c = ch;
        ps->first->next = temp;
    }
    ps->len++;
}

char Pop(pStack ps)
{
    char ch = ps->first->c;
    pNode temp = ps->first;
    ps->first = temp->next;
    ps->len--;
    free(temp);
    return ch;
}

int Is_empty(pStack ps)
{
    if (ps->len && ps->first)
        return 0;
    return 1;
}

void Show_stack(pStack ps)
{
    pNode temp = ps->first;
    if (Is_empty(ps))
        printf("\nStack is empty!\n");
    else
    {
        while(temp)
        {
            printf("%c\t",temp->c);
            temp = temp->next;
        }
    }
}

void Clear_stack(pStack ps)
{
    if (Is_empty(ps))
        printf("\nStack is empty!");
    else
        while (!Is_empty(ps))
            Pop(ps);
}
