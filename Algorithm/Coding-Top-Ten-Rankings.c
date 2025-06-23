#include <stdio.h>

// 选择排序函数
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // 外层循环：依次选择未排序部分的最小元素
    for (i = 0; i < n - 1; i++)
    {
        // 假设当前i位置的元素是最小值
        min_idx = i;

        // 内层循环：在未排序部分中查找实际最小值的位置
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j; // 更新最小值的位置
            }
        }

        // 将找到的最小值与当前位置i交换
        if (min_idx != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// 打印数组函数
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前数组: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("排序后数组: \n");
    printArray(arr, n);

    return 0;
}

// 关键点解析：
// 时间复杂度：

// 最优 / 最差 / 平均情况均为 O(n²)
// （每次都要遍历剩余未排序元素）。

// 空间复杂度：

// O(1)
// （原地排序，仅需常数级额外空间）。

//     核心步骤：

//     每次从未排序部分选出最小元素，与当前未排序部分的第一个元素交换。

//     稳定性：

//     不稳定排序（例如[5, 5, 2] 排序后第一个 5 会移到第二个 5 之后）。