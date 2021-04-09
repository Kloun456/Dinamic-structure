#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*struct Point
{
    int x, y;
};*/

//2
/*struct Point
{
    int x, y;
}p1,p2;*/

//3
/*struct Point
{
    int x, y;
}p1 = {0,-3}, p2 = {0,1};*/

//4
typedef struct
{
    int x, y;
}Point;

int main()
{
    setlocale(0,"");
    double d;
    /*Point p1 = {0,-3};
    Point p2 = {0, 1};
    d = sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
    printf("d = %f", d);*/

    //2
    /*d = sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
    printf("d = %f", d);*/

    //3
    /*d = sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
    printf("d = %f", d);*/

    //4
    /*Point p1 = {0,-3}, p2 = {0,1};
    d = sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
    printf("d = %f", d);*/
}


