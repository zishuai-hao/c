#include <stdio.h>

int main(int argc, char const *argv[])
{
    int var_num = 10;
    int *p;

    p = &var_num;
    printf("varnum 的变量地址是：%p\n", &var_num);
    printf("p保存的的变量地址是： %p\n", p);
    printf("*p 变量值为：%d\n", *p);

    int *npt = NULL;
    printf("npt 的地址为： %p\n", npt);

    return 0;
}
