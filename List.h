#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node
{
    int c;
    struct Node *next;

}NODE;

typedef struct List
{
    NODE *first;
    int len;
}LIST;


LIST *Create_list();
void Push_after_list(LIST *pl, NODE *pn, int ch);
NODE *Get_pointer_list(LIST *pl, int ch);
int Pop_list(LIST *pl, NODE *pn);
int Is_empty_list(LIST *pl);
void Show_list(LIST *pl);
void Clear_list(LIST *pl);
void Delete_list(LIST *pl);

#endif // LIST_H_INCLUDED
