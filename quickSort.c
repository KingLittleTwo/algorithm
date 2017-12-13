/*
快速排序(Quick Sort)使用分治法策略。
它的基本思想是：选择一个基准数，通过一趟排序将要排序的数据分割成独立的两部分；其中一部分的所有数据都比另外一部分的所有数据都要小。然后，再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

快速排序流程：
(1) 从数列中挑出一个基准值。
(2) 将所有比基准值小的摆放在基准前面，所有比基准值大的摆在基准的后面(相同的数可以到任一边)；在这个分区退出之后，该基准就处于数列的中间位置。
(3) 递归地把"基准值前面的子数列"和"基准值后面的子数列"进行排序。
*/
#include <stdio.h>
#include <stdlib.h>
// 数组长度
#define LENGTH(array) ((sizeof(array)) / (sizeof(array[0])))

/** 
 * @brief  
 * @note   快速排序
 * @param  a[]: 带排序数组
 * @param  l:   数组的左边界  例如：l = 0
 * @param  r:   数组的右边界  例如：r = a.length - 1
 * @retval None
 */
void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int tmp;        // 定义一个基准数，一般为第一个数
        tmp = a[l];
        while (l < r)
        {
            while (l < r && a[r] > tmp)
                r--; // 从右向左找第一个小于tmp的数
            if (l < r)
                a[l++] = a[r];
            while (l < r && a[l] < tmp)
                l++; // 从右向左找第一个大于tmp的数
            if (l < r)
                a[r--] = a[l];
        }
        a[l] = tmp;
        quickSort(a, l, l-1);
        quickSort(a, l+1, r);
    }
}