#include <stdio.h>
/**
 * @brief 选择排序
 * 冒泡排序升级版：挨个比较并交换有点浪费资源，专门开辟出来空间存储一个变量，
 * 存储未排序的最轻（重）的泡泡的索引，在一轮循环过后，放置到最后
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{   
    int arr[6] = {6,5,4,3,2,1};
    for (size_t i = 0; i < 6; i++)
    {
        int max = 0;
        for (size_t j = 1; j < 6 - 1 - j; j++)
        {
            if (arr[j] >= arr[max])
            {
                max = j;
            }
        }
        // if (max == 0){
        //     return;
        // }
        int temp = arr[max];
        arr[max] = arr[6 - 1 - i];
        arr[6 - 1 - i] = temp;
        // if (max )
    }
    
    for (int i = 0; i < 6; i++)
    {
        printf("%d,",arr[i]);
    }

    return 0;
}
