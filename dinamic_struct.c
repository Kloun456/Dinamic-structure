#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "stack.h"
#define N 20


void Fill(STACK *st)
{
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        Push_front_stack(st,rand() % 71 - 50);  // ãåíåðàòîð ÷èñåë îò -50 äî 50
}

void Sort(STACK *st, STACK *neg, STACK *pos)  // сортирует на два стека, один который содержит отрицательные числа, другой положительные
{
    while(!Is_empty_stack(st))
    {
        if (st->first->c < 0)
            Push_front_stack(neg, st->first->c);
        else
            Push_front_stack(pos, st->first->c);
        Pop_front_stack(st);
    }
}

void Delete(STACK *st)  // удаляет четные числа
{
    NODE *temp = st->first;
    NODE *previous, *del;
    while(temp->next != 0)
    {
        if (st->first->c % 2 == 0)
        {
            Pop_front_stack(st);
            temp = st->first;
            continue;
        }
        else if (temp->c % 2 == 0)
        {
            del = temp;
            previous->next = temp->next;
            temp = temp->next;
            free(del);
            st->len--;
            continue;
        }
        previous = temp;
        temp = temp->next;
    }
    if(temp->c % 2 == 0)
    {
        free(temp);
        st->len--;
        previous->next = 0;
    }
}

void Delete_index(STACK *st) // удаляет каждый второй элемент
{
    int i = 1;
    NODE *temp = st->first;
    NODE *previous, *del;
    while(temp->next != 0)
    {
        if (i % 2 == 0)
        {
            del = temp;
            previous->next = temp->next;
            temp = temp->next;
            st->len--;
            free(del);
            i++;
            continue;
        }
        previous = temp;
        temp = temp->next;
        i++;
    }
}

int main()
{
    STACK *st, *neg, *pos;
    st = Create_stack();
    neg = Create_stack();
    pos = Create_stack();
    Fill(st);

    // 1
    /*printf("\nMain stack:\n");
    Show_stack(st);
    Sort(st, neg, pos);
    printf("\nNegative stack:\n");
    Show_stack(neg);
    printf("\nPositive stack:\n");
    Show_stack(pos);*/

    //2
    /*printf("\nMain stack:\n");
    Show_stack(st);
    Delete(st);
    printf("\nMain stack after delete:\n");
    Show_stack(st);*/

    //3
    /*printf("\nMain stack:\n");
    Show_stack(st);
    Swap(st);
    printf("\nMain stack after swap:\n");
    Show_stack(st);*/

    //4
    /*printf("\nMain stack:\n");
    Show_stack(st);
    Delete_index(st);
    printf("\nMain stack after delete:\n");
    Show_stack(st);*/
}
