#include <stdio.h>
#include <stdarg.h>

double average(int num, ...)
{
    va_list valist;
    double sum = 0.0;
    int i;

    va_start(valist, num);

    for (i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }

    va_end(valist);

    return sum / num;
}

int main(int argc, char const *argv[])
{

    printf("1,2,4,5的平均数为: %f\n", average(2, 2, 4, 5));
    return 0;
}
