#include "queue.h"
#include <time.h>
#define N 20

QUEUE *Create_queue()
{
    QUEUE *pq;
    pq = (QUEUE *)malloc(sizeof(QUEUE));
    pq->first = 0;
    pq->last = 0;
    pq->len = 0;
    return pq;
}

void Push_back_queue(QUEUE *pq, int ch)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->next = 0;
    temp->c = ch;
    if (pq->last != 0)
        pq->last->next = temp;
    else
        pq->first = temp;
    pq->last = temp;
    pq->len++;
}

int Pop_front_queue(QUEUE *pq)
{
    int ch;
    NODE *temp = pq->first;
    ch = pq->first->c;
    pq->first = temp->next;
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
            printf("%d\t",temp->c);
            temp = temp->next;
        }
    }
}

void Clear_queue(QUEUE *pq)
{
    while (!Is_empty_queue(pq))
        Pop_front_queue(pq);
}

void Fill_queue(QUEUE *pq)
{
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        Push_back_queue(pq,rand() % 71 - 50);
}

void Greatest_element(QUEUE *pq)
{
    QUEUE *del = Create_queue();
    NODE *temp = pq->first;
    int t;
    t = pq->first->c;
    while(temp->next != 0)
    {
        temp = temp->next;
        if (temp->c > t)
            t = temp->c;
    }
    while(t != pq->first->c)
        Push_back_queue(del, Pop_front_queue(pq));
    while(!Is_empty_queue(del))
        Push_back_queue(pq,Pop_front_queue(del));
}

void Section(QUEUE *pq)
{
    QUEUE *ab = Create_queue();
    QUEUE *after_b = Create_queue();
    int a, b, number, n;
    printf("\nEnter a:");
    scanf("%d",&a);
    printf("\nEnter b:");
    scanf("%d",&b);
    printf("\nEnter quantity numbers:");
    scanf("%d",&n);
    printf("\nEnter numbers:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&number);
        if (number < a)
            Push_back_queue(pq,number);
        else if (number > b)
            Push_back_queue(after_b,number);
        else
            Push_back_queue(ab,number);
    }
    while(!Is_empty_queue(ab))
        Push_back_queue(pq,Pop_front_queue(ab));
    while(!Is_empty_queue(after_b))
        Push_back_queue(pq,Pop_front_queue(after_b));
}
