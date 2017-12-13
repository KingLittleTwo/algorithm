#include <stdio.h>
#include <stdlib.h>
/** 
 * 冒泡排序bubbleSort
 * 它是一种简单的排序算法，它会遍历若干次要排序的数列，每次遍历时，他都会从前往后依次的比较相邻两个数的大小；如果前者比后者大，
 * 则交换他们的位置，这样，依次遍历后，最大的元素就在数列的末尾，采用相同的方法再次遍历时，第二大的元素就排列在最大元素之前，
 * 重复此操作，直到整个数列都有序为止
 */
// 数组长度
#define LENGTH(array) ((sizeof(array)) / (sizeof(array[0])))
// 交换数值
#define swap(a, b) (a^=b, b^=a, a^=b)

void bubble_sort1(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i ++)
    {
        for (j = 0; j < i; j++)
        {
            // 如果前一位大于后一位就往后移
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// 改进版
// 添加一个标记，如果一趟遍历中发生了交换，则标记为true，否则为false。如果某一趟没有发生交换，说明排序已经完成！
void bubble_sort2(int a[], int n)
{
    int i, j, flag;
    for (i = 0; i < n; i ++)
    {
        flag = 0;   // 初始化标记
        for (j = 0; j < i; j++)
        {
            // 如果前一位大于后一位就往后移
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;   // 如果发生了交换，则标记为1
            }
        }
        if (flag == 0)
            break; // 若没发生交换，则说明数组已经有序
    }
}
int main()
{
    int i;
    int a[] = {20,40,30,10,60,50};
    int b[] = {20,40,30,10,60,50};
    int iLen = LENGTH(a);
    printf("len = %d\n", iLen);
    printf("before sort:\n");
    for(i = 0; i < iLen; i++)
        printf("%d\t",a[i]);
    printf("\n");

    bubble_sort1(a, iLen);

    printf("after sort:\n");
    for(i = 0; i < iLen; i++)
        printf("%d\t",a[i]);
    printf("\n");

    bubble_sort2(a, iLen);

    printf("after sort 2:\n");
    for(i = 0; i < iLen; i++)
        printf("%d\t",a[i]);
    printf("\n");
    return 0;
}