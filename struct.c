#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

typedef struct
{
    char s[20];
    int liga;
    int result;
}Club;

void Fill_club(Club *all)
{
    for (int i = 0; i < N; i++)
    {
        printf("\nEnter %d club name: ",i+1);
        gets(all[i].s);
    }
    for (int i = 0; i < N; i++)
    {
        printf("\nEnter lig for %d club: ",i+1);
        scanf("%d", &all[i].liga);
    }
    for (int i = 0; i < N; i++)
    {
        printf("\nEnter result %d club: ",i+1);
        scanf("%d", &all[i].result);
    }
}

void Show_club(Club *all, int lig)
{
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (all[i].liga == lig)
            printf("\n Club: %s, place: %d, result: %d",all[i].s,j+=1,all[i].result);
    }
}

void Sort(Club *all)
{
    int i , im;
    Club temp;
    for (i = 1; i < N; i++)
    {
        temp = all[i];
        im = i-1;
        while(im >= 0 && all[im].result > temp.result)
        {
            all[im + 1] = all[im];
            all[im] = temp;
            im--;
        }
    }
}


int main()
{
    int lig = 1;
    Club all[5];
    Fill_club(all);
    Sort(all);
    while(lig)
    {
        printf("\nEnter lig number: ");
        scanf("%d", &lig);
        Show_club(all,lig);
    }

}
