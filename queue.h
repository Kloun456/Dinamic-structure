#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct Node
{
    char c;
    struct Node *next;

}NODE;

typedef struct Queue
{
    NODE *first;
    int len;

}QUEUE;

QUEUE *Create_queue();
void Push_back_queue(QUEUE *pq, int ch);
int Pop_front_queue(QUEUE *pq);
int Is_empty_queue(QUEUE *pq);
void Show_queue(QUEUE *pq);
void Clear_queue(QUEUE *pq);
void Fill_queue(QUEUE *pq);
void Greatest_element(QUEUE *pq);
void Section(QUEUE *pq);

#endif // QUEUE_H_INCLUDED
