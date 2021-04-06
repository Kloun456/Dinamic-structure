#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node1
{
    char c;
    struct Node1 *next;

}*pNode1;

typedef struct List
{
    pNode1 first;
    int len;

}*pList;


pList Create_list();
void Push_back_list(pList pl, char ch);
void Push_front_list(pList pl, char ch);
char Pop_front_list(pList pl);
int Is_empty_list(pList pl);
void Show_list(pList pl);
void Clear_list(pList pl);

#endif // LIST_H_INCLUDED
