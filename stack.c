#include "stack.h"


STACK *Create_stack()
{
    STACK *ps;
    ps = (STACK *)malloc(sizeof(STACK));
    ps->first = 0;
    ps->len = 0;
    return ps;
}

void Push_front_stack(STACK *ps, int ch)
{
    NODE *temp = ps->first;
    if (ps->first == 0)
    {
        ps->first = (NODE *)malloc(sizeof(NODE));
        ps->first->c = ch;
        ps->first->next = 0;
    }
    else
    {
        ps->first = (NODE *)malloc(sizeof(NODE));
        ps->first->c = ch;
        ps->first->next = temp;
    }
    ps->len++;
}

int Pop_front_stack(STACK *ps)
{
    int x = ps->first->c;
    NODE *temp = ps->first;
    ps->first = temp->next;
    ps->len--;
    free(temp);
    temp = 0;
    return x;
}

int Is_empty_stack(STACK *ps)
{
    if (ps->len && ps->first)
        return 0;
    return 1;
}

void Show_stack(STACK *ps)
{
    NODE *temp = ps->first;
    if (Is_empty_stack(ps))
        printf("\nStack is empty!\n");
    else
    {
        while (temp)
        {
            printf("%d\t", temp->c);
            temp = temp->next;
        }
    }
    free(temp);
    temp = 0;
}

void Clear_stack(STACK *ps)
{
    while (!Is_empty_stack(ps))
        Pop_front_stack(ps);
}

