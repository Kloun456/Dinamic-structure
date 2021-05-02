#include "List.h"

LIST *Create_list()
{
    LIST *pl;
    pl = (LIST *)malloc(sizeof(LIST));
    pl->first = 0;
    pl->len = 0;
    return pl;
}

NODE *Get_pointer_list(LIST *pl, int ch)
{
    NODE *temp = pl->first;
    if (Is_empty_list(pl))
        return 0;
    if (temp->c >= ch)
        return temp;
    while(temp->c < ch && temp != 0)
        temp = temp->next;
    return temp;
}
void Push_after_list(LIST *pl, NODE *pn, int ch)
{
    NODE *new_date = (NODE *)malloc(sizeof(NODE));
    new_date->c = ch;
    if (!pn)
    {
        new_date->next = 0;
        pl->first = new_date;
    }
    else
    {
        if (pn==pl->first && ch <= pl->first->c)
        {
            new_date->next = pl->first;
            pl->first = new_date;
        }
        else
        {
            NODE *temp = pn->next;
            new_date->next = temp;
            pn->next = new_date;
        }
    }
    pl->len++;
}

int Pop_list(LIST *pl, NODE *pn)
{
    if(!pn)
        return 0;
    NODE *temp = pl->first;
    NODE *del = pn;
    if(pn == pl->first)
    {
        pl->first = temp->next;
        free(temp);
    }
    else
    {
        while (temp->next != pn)
            temp = temp->next;
        temp->next = pn->next;
        free(del);
    }
    pl->len--;
    return 1;
}

int Is_empty_list(LIST *pl)
{
    if (pl->len && pl->first)
        return 0;
    return 1;
}

void Show_list(LIST *pl)
{
    NODE *temp = pl->first;
    if (Is_empty_list(pl))
        printf("\nList is empty!\n");
    else
    {
        while(temp)
        {
            printf("%d\t",temp->c);
            temp = temp->next;
        }
    }
    free(temp);
    temp = 0;
}

void Clear_list(LIST *pl)
{
    while(pl->first->next)
        Pop_list(l,pl->first);
    free(pl->first);
    pl->len--;
}

void Delete_list(LIST *pl)
{
    if (!Is_empty_list(pl))
        Clear_list(pl);
    free(pl);
}
