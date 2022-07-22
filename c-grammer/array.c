#include <stdio.h>

const int MAX = 3;
int main(int argc, char const *argv[])
{

    int var[] = {5, 100, 200};

    int i, *ptr;

    i = 0;
    ptr = var;

    while (ptr <= &var[MAX - 1])
    {
        printf("地址： var[%d] = %p\n", i, ptr);
        printf("值： var[%d] = %d\n", i, *ptr);
        i++;
        ptr++;
    }

    return 0;
}
