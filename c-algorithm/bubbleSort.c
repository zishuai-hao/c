#include <stdio.h>

/**
 * @brief 冒泡排序
 * 将元素化为重量为元素大小的泡泡，挨个比较，遵循较重的泡泡应该在下面（或上面）
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int sort(int arr[], int length) {

// len - 1: 大到小排序，从第一个元素之后的所有数字都排好序后，第一个元素已经是最小了
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%d,", arr[i]);
    }

    return 0;
}
