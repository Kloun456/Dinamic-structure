#include "List.h"

pList Create_list()
{
    pList pl;
    pl = (pList)malloc(sizeof(pList));
    pl->first = 0;
    pl->len = 0;
    return pl;
}

void Push_back_list(pList pl,char ch)
{
    pNode1 temp = pl->first;
    if (pl->first == 0)
    {
        pl->first = (pNode1)malloc(sizeof(pNode1));
        pl->first->c = ch;
        pl->first->next = 0;
    }
    else
    {
        while(temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = (pNode1)malloc(sizeof(pNode1));
        temp->next->c = ch;
        temp->next->next = 0;
    }
    pl->len++;
}

void Push_front_list(pList pl, char ch)
{
    pNode1 temp = pl->first;
    if (pl->first == 0)
    {
        pl->first = (pNode1)malloc(sizeof(pNode1));
        pl->first->c = ch;
        pl->first->next = 0;
    }
    else
    {
        pl->first = (pNode1)malloc(sizeof(pNode1));
        pl->first->c = ch;
        pl->first->next = temp;
    }
    pl->len++;

}

char Pop_front_list(pList pl)
{
    char ch;

    pNode1 temp = pl->first;
    ch = pl->first->c;
    pl->first = pl->first->next;
    free(temp);
    pl->len--;
    return ch;
}

int Is_empty_list(pList pl)
{
    if (pl->len && pl->first)
        return 0;
    return 1;
}

void Show_list(pList pl)
{
    pNode1 temp = pl->first;
    if (Is_empty(pl))
        printf("\nList is empty!\n");
    else
    {
        while(temp)
        {
            printf("%c\t",temp->c);
            temp = temp->next;
        }
    }
}

void Clear_list(pList pl)
{
    if (Is_empty(pl))
        printf("\nList is empty!");
    else
        while (!Is_empty(pl))
            Pop_front_list(pl);
}
