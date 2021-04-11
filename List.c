#include "List.h"

LIST *Create_list()
{
    LIST *pl;
    pl = (LIST *)malloc(sizeof(LIST));
    pl->first = 0;
    pl->len = 0;
    return pl;
}

void Push_back_list(LIST *pl,char ch)
{
    NODE *temp = pl->first;
    if (pl->first == 0)
    {
        pl->first = (NODE *)malloc(sizeof(NODE));
        pl->first->c = ch;
        pl->first->next = 0;
    }
    else
    {
        while(temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = (NODE *)malloc(sizeof(NODE));
        temp->next->c = ch;
        temp->next->next = 0;
    }
    pl->len++;
}

void Push_front_list(LIST *pl, char ch)
{
    NODE *temp = pl->first;
    if (pl->first == 0)
    {
        pl->first = (NODE *)malloc(sizeof(NODE));
        pl->first->c = ch;
        pl->first->next = 0;
    }
    else
    {
        pl->first = (NODE *)malloc(sizeof(NODE));
        pl->first->c = ch;
        pl->first->next = temp;
    }
    pl->len++;
}

char Pop_front_list(LIST *pl)
{
    char ch;
    NODE *temp = pl->first;
    ch = pl->first->c;
    pl->first = pl->first->next;
    free(temp);
    temp = 0;
    pl->len--;
    return ch;
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
            printf("%c\t",temp->c);
            temp = temp->next;
        }
    }
    free(temp);
    temp = 0;
}

void Clear_list(LIST *pl)
{
    while (!Is_empty_list(pl))
        Pop_front_list(pl);
}
