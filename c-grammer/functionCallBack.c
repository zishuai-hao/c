#include <stdlib.h>
#include <stdio.h>

void populate_array(int *array, size_t arraySize, int (*callback)(void))
{
    for (size_t i = 0; i < arraySize; i++)
    {
        array[i] = callback();
    }
}

int getNextRandomValue()
{
    return rand();
}

int main(int argc, char const *argv[])
{
    int myarray[10];
    int random = getNextRandomValue();
    populate_array(myarray, 10, getNextRandomValue);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", myarray[i]);
    }
    // printf("随机数：%d", random);
    return 0;
}
