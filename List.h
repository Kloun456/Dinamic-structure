#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node
{
    char c;
    struct Node *next;

}NODE;

typedef struct List
{
    NODE *first;
    int len;
}LIST;


LIST *Create_list();
void Push_back_list(LIST *pl, char ch);
void Push_front_list(LIST *pl, char ch);
char Pop_front_list(LIST *pl);
int Is_empty_list(LIST *pl);
void Show_list(LIST *pl);
void Clear_list(LIST *pl);

#endif // LIST_H_INCLUDED
