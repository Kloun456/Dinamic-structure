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
    STACK *del = Create_stack();
    while(st->len)
    {
        if(st->first->c % 2 != 0)
            Push_front_stack(del,Pop_front_stack(st));
        else
            Pop_front_stack(st);
    }
    while(del->len)
        Push_front_stack(st,Pop_front_stack(del));

}

STACK *Swap(STACK *st)
{
    STACK *del = Create_stack();
    int t = Pop_front_stack(st);
    Push_front_stack(del,t);
    for (int i = st->len; i > 0; i--)
        Push_front_stack(del,Pop_front_stack(st));
    return del;
}

void Delete_index(STACK *st) // удаляет каждый второй элемент
{
    STACK *del = Create_stack();
    for(int i = st->len; i > 0; i--)
    {
        if(i % 2 == 0)
            Push_front_stack(del,Pop_front_stack(st));
        else
            Pop_front_stack(st);
    }
    while(del->len)
        Push_front_stack(st,Pop_front_stack(del));
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
    neg = Swap(st);
    printf("\nMain stack after swap:\n");
    Show_stack(neg);*/

    //4
    /*printf("\nMain stack:\n");
    Show_stack(st);
    Delete_index(st);
    printf("\nMain stack after delete:\n");
    Show_stack(st);*/
}
