#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    pStack st = Create_stack();
    char c;
    for (c = 'a'; c <= 'z'; c++)
        Push(st,c);
    Show_stack(st);
    Clear_stack(st);
    Show_stack(st);
}
