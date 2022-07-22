//
// Created by hzs on 2022/7/19.
//
#include <stdlib.h>
#include <stdio.h>

void insert(int arr[6], size_t i);

void printArr(int arr[], size_t length);

void insertionSort(int length, int *arr);

void shellSort(int length, int *arr);

void shellInsert(int *arr, size_t i, int k);

void selectionSort(int length, int *arr);

void quickSort(int length, int *arr);


void quickerSort(int *arr, int left, int right);

void bubbleSort(int length, int *arr);

void mergeSort(int length, int *arr);

void heapSort(int length, int *arr);

void mergerSort(int *arr, int left, int right);

void mergeInsert(int *arr, int left, int right);

void buildHeap(int *arr, int length);

int parent(int point);

void swim(int *arr, int length);

void sink(int *arr, int point, int length);


void BucketSort(int length, int *arr);

void printArr(int arr[], size_t length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printScopeArr(int arr[], int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// insertionSort
// 直接插入排序，假设 当前元素之前的所有元素已经排好序，只是将当前元素插入之前排好序的数组中
int main() {
    int length = 6;
    int arr[6] = {30, 300, 100, 7, 9, 60};

//    bubbleSort(length, arr);
//    insertionSort(length, arr);
//    shellSort(length, arr);
//    selectionSort(length, arr);
//    quickSort(length, arr);
//    mergeSort(length, arr);
//    heapSort(length, arr);
    BucketSort(length, arr);

    printArr(arr, length);
//    printf("int[6] %d", arr[100]);
    return 0;
}

/**
 *
 * @param length
 * @param arr
 */
void BucketSort(int length, int *arr) {

}

/**
 * 堆排序
 * 数据结构：使用二叉堆（顺序表）的结构，分为"最小堆"与"最大堆" 该结构下父节点总小于（大于）自己的两个子节点（下面的算法使用"最大堆"）
 * 调整：二叉堆提供调整的功能，当父节点不遵循最大堆规则，小于两个子节点时，与较大子节点进行交换，并且递归检查到叶子节点
 * 删除：将堆顶与最后一个节点进行调换
 *
 * 将待排序数组视为一个完全二叉树，按照最大堆规则进行调整后，恰好最大值在堆顶，执行"删除"，然后重新"调整"此时新的堆顶就是原来数组中第二大值
 * 每次将最大值放置在数组末尾，则形成的就是一个从小到大的数组
 * @param length
 * @param arr
 */
void heapSort(int length, int *arr) {
    // 构建一个最大堆
    buildHeap(arr, length);

    for (int i = 0; i < length; i++) {
        // 交换堆顶与最后子节点
        swap(arr, 0, length - i - 1);
        // 下沉新子节点 产生新的堆顶
        sink(arr, 0, length - i - 1);
    }
}


void buildHeap(int *arr, int length) {
    // 从最后一个叶子节点开始 下沉
    for (int i = length / 2 - 1; i >= 0; --i) {
        sink(arr, i, length);
    }
}

/**
 * 元素下沉
 * @param arr
 * @param length
 */
void sink(int *arr, int point, int length) {
    while (2 * (point + 1) - 1 < length) {
        int maxChildPoint = 2 * (point + 1) - 1;

        // 寻找最大子节点
        if (maxChildPoint + 1 < length) {
            maxChildPoint = arr[maxChildPoint] < arr[maxChildPoint + 1] ? maxChildPoint + 1 : maxChildPoint;
        }

        if (arr[point] < arr[maxChildPoint]) {
            swap(arr, point, maxChildPoint);
        }
        point = maxChildPoint;
    }
}

/**
 * 新增元素 或构造堆时 ，元素浮动
 * @param arr
 * @param length
 */
void swim(int *arr, int length) {
    int point = length - 1;
    while (parent(point) >= 0) {
        if (arr[point] > arr[parent(point)]) {
            swap(arr, point, parent(point));
        }
        point = parent(point);
    }
}

int parent(int point) {
    return point == 0 ? -1 : (point - 1) / 2;
}


/**
 * 归并排序
 * 原理就是将数组尽可能从中间分开，直到不能再分，形成一个树形结构；
 * 然后自下而上进行合并排序，对叶子节点排序后，合并到父节点后再进行一次排序，以此类推
 * @param length
 * @param arr
 */
void mergeSort(int length, int *arr) {
    int left, right;
    left = 0, right = length - 1;
    mergerSort(arr, left, right);
}

void mergerSort(int *arr, int left, int right) {
    if (left == right) {
        return;
    }
    // 继续切分
    if (abs(left - right) > 1) {
        int mid = left + (right - left) / 2;
        mergerSort(arr, left, mid - 1);
        mergerSort(arr, mid, right);
    }
    //  插入排序
    for (int i = left; i < right; ++i) {
        if (arr[i + 1] > arr[i]) {
            mergeInsert(arr, left, i + 1);
        }
    }
}


void mergeInsert(int *arr, int left, int right) {
    swap(arr, right, right - 1);
    for (int i = right - 1; i > left; --i) {
        if (arr[i] > arr[i - 1]) {
            swap(arr, i, i - 1);
        }
    }
}

/**
 * 快速排序
 * 使用二分法，取一个随机中间值，对整体进行一个排序，大于中间值的都靠右，小于中间值的都靠左
 * 然后递归左右两个分组 使用同样的方式，令左右分组分别整体排序，各自产生两个的分组
 * 无法再继续分组时 退出，所有分组都完成后，排序完成
 * @param length
 * @param arr
 */
void quickSort(int length, int *arr) {
    int left, right;
    left = 0;
    right = length - 1;
    quickerSort(arr, left, right);
}

void quickerSort(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int left_copy = left;
    int right_copy = right;
    int pivot = 0;
    while (left < right) {
        if (arr[right] >= arr[pivot]) {
            right--;
            continue;
        }
        if (arr[left] <= arr[pivot]) {
            left++;
            continue;
        }
        // 说明存在right < pivot && left > pivot
        // 所以交换两个数的位置
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

    }
    // 将预设的中间值 从 0 放到数组中间位置
    int temp = arr[pivot];
    arr[pivot] = arr[left];
    arr[left] = temp;
    pivot = left;

    quickerSort(arr, left_copy, pivot - 1);
    quickerSort(arr, pivot + 1, right_copy);
}


void selectionSort(int length, int *arr) {
    for (size_t i = 0; i < length; i++) {
        size_t max = 0;
        for (size_t j = 1; j < length - i; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        printf("max value: %zu\n", max);

        int temp = arr[max];
        arr[max] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
}

/**
 * 插入排序
 * @param length
 * @param arr
 */
void insertionSort(int length, int *arr) {
    for (size_t i = 1; i < length; i++) {
        if (arr[i] > arr[i - 1]) {
            insert(arr, i);
        }
    }
}

void insert(int arr[6], size_t i) {
    for (size_t j = i; j > 0; j--) {
        if (arr[j] <= arr[j - 1]) {
            return;
        }
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
    }
}

/**
 * 希尔排序
 * 在插入排序中，数组在大多数元素有序的情况下，对比或移动的次数较少；当元素较少时，同样对比或移动的次数较少
 * 综合这两个特性 总结出改进方案1：
 *    1. 将完整需要排序的数组，依次划分为多个长度为n（上述结论2）的子序列（最后一个序列长度允许小于n），然后分别对多个子序列使用插入排序
 *    2. 当然 n < len(arr) 时，一次排序后只在多个子序列内部有序，将n递增, 继续进行插入排序
 *    3. 直到 n = len(arr) 时，进行一个完整的插入排序，此时数组有序
 * 当然 改进方案1 还是有缺点，由于子序列之间元素都是连续的，排序之后，依然对整体数组还是无序，提出改正方案2:
 *    1. 使用一个 增量（类似于step）k,根据这个增量划分元素 则数组被划分为 {{k,2k,3k...},{k+1,2K+1,3k+1...}...{k + k-1, 2k + k-1... }}多个子序列
 *    2. 分别对各个子序列进行直接插入排序，得到一个排序之后的新数组。
 *    3. 最后，原本是将完整数组进行一次插入排序，但是由于数组可能无限大，所以一次肯定不够，需要进行多次增量直接插入
 *    4. 减少增量 进行插入排序 直到增量为1时 进行完整的插入排序
 * 这就是希尔排序
 * @param length
 * @param arr
 */
void shellSort(int length, int *arr) {
    int k = 3;

    // 递减增量
    for (; k >= 1; k--) {
        // 循环处理各个序列
        for (size_t i = k; i < length; i++) {
            if (arr[i] > arr[i - k]) {
                shellInsert(arr, i, k);
                printArr(arr, length);
            }
        }
    }
}

void shellInsert(int *arr, size_t i, int k) {
    for (size_t j = i; j >= k; j -= k) {
        if (arr[j] <= arr[j - k]) {
            return;
        }
        int temp = arr[j];
        arr[j] = arr[j - k];
        arr[j - k] = temp;
    }
}

void bubbleSort(int length, int *arr) {

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
}






