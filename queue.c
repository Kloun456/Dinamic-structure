#include "queue.h"

QUEUE *Create_queue()
{
    QUEUE *pq;
    pq = (QUEUE *)malloc(sizeof(QUEUE));
    pq->first = 0;
    pq->last = 0;
    pq->len = 0;
    return pq;
}

void Push_back_queue(QUEUE *pq,char ch)
{
    NODE *temp = pq->first;
    if (pq->first == 0)
    {
        pq->first = (NODE *)malloc(sizeof(NODE));
        pq->first->c = ch;
        pq->first->next = 0;
        pq->last = pq->first;
    }
    else
    {
        while(temp->next)
        {
            temp = temp->next;
        }
        pq->last = (NODE *)malloc(sizeof(NODE));
        pq->last->next = 0;
        pq->last->c = ch;
        temp->next = pq->last;
    }
    pq->len++;
}

char Pop_front_queue(QUEUE *pq)
{
    char ch;
    NODE *temp = pq->first;
    ch = pq->first->c;
    pq->first = pq->first->next;
    free(temp);
    temp = 0;
    pq->len--;

    return ch;
}

int Is_empty_queue(QUEUE *pq)
{
    if (pq->len && pq->first)
        return 0;
    return 1;
}

void Show_queue(QUEUE *pq)
{
    NODE *temp = pq->first;
    if (Is_empty_queue(pq))
        printf("\nQueue is empty!\n");
    else
    {
        while(temp)
        {
            printf("%c\t",temp->c);
            temp = temp->next;
        }
    }
}

void Clear_queue(QUEUE *pq)
{
    while (!Is_empty_queue(pq))
        Pop_front_queue(pq);
}
