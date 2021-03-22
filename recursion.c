#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
const int n = 40;
int count = 0;  // for symbols
float eps = 1e-12;

void Print_array(int *x), Fill_array(int *x), Print_numb(int *x, int );
int min(int *x), min1(int *x, int , int), digits(FILE *my_file), symbols(FILE *my_file), sum(int *x, int );
float Solution(float , float), f(float );


int main()
{
    int x[10] = {1,-2,-3,4,5,6,-7,8,9,0}, i = 0;
    char c;
    FILE *my_file;

    // 1)
     /*Fill_array(x);
    Print_array(x);
    printf("\nmin = %d", min(x));*/

    // 2)
    /*while(i < n)
    {
        scanf("%d",&x[i]);
        if (x[i] < 0)
            break;
        i++;
    }
    printf("Sum of elements = %d",sum(x,0)); */

    // 3)
    /*if ((my_file = fopen("My_file.txt","r"))==0)
    {
        printf("\nFile is not open!\n");
    }
    else
    {
        printf("\nFile is open!\n");
    }
    printf("Quantity symbols = %d\t", symbols(my_file));
    count = 0;
    rewind(my_file);
    printf("quantity digits = %d\n", digits(my_file));
    fclose(my_file); */

    // 4)
    /*Print_numb(x,i);*/

    // 5)
    printf("%f", Solution(0.94721,0.94722));
}

float Solution(float a, float b)
{
    float x = (a + b) / 2.0;
    if (abs(a - b) < eps)
        return x;
    if (!f(x))
        return x;
    if (f(x) * f(a) > 0)
        return Solution(x, b);
    else
        return Solution(a, x);
}

float f(float x)
{
    return sin(1+pow(x,2))-x;
}

void Print_numb(int *x, int i)
{
    if (x[i] < 0)
    {
        printf("%d\t",x[i]);
        Print_numb(x,i+1);
    }
    else if (x[i] > 0)
    {
        Print_numb(x,i+1);
        printf("%d\t",x[i]);
    }
    else
        return 0;
}

int sum(int *x, int l)
{
    if (x[l] < 0)
        return 0;
    else
        return sum(x,l+1) + x[l];

}

int digits(FILE *my_file)
{
    char c;
    if((c = fgetc(my_file))!= EOF || isdigit(c = fgetc(my_file)) ) // проверка пока не конец файла или символ является цифрой
    {
        if (isdigit(c))
            count++;
        digits(my_file);
    }
    else
        return count;
}

int symbols(FILE *my_file)
{
    char c;
    if((c = fgetc(my_file))!= EOF)
    {
        count++;
        symbols(my_file);
    }
    else
        return count;
}

int min (int *x) // function min
{
    return min1(x,0,999999);    
}

int min1(int *x, int k, int minimum) // recursion min   можно улучшить наверно
{
    if (k == n-1)
        return minimum;
    if (minimum >= x[k])
        minimum = x[k];
    return min1(x,k + 1,minimum);
}

void Fill_array(int *x)
{
    srand(time(0));
    for (int i = 0; i < 40; i++)
    {
        x[i] = rand() % 32;
        if (x[i] == 0)
            x[i] = 21;
    }
}

void Print_array(int *x)
{
    for (int i = 0; i < 40; i++)
        printf("%d ", x[i]);
}
