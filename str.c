#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[14] = "hzs";
    char str2[14] = "ccc";
    char str3[14];

    /* 复制 str1 到 str3 */
    strcpy(str3, str1);
    printf("strcpy(str3, str1) : %s \n", str3);

    /* 链接str2 到 str1 */
    strcat(str1, str2);
    printf(" strcat(str1, str2): %s \n", str1);

    /* 获取拼接后的str1 长度 */
    int len = strlen(str1);
    printf("strlen(str1) : %d\n", len);

    return 0;
}
