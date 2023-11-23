#include<stdio.h>
#include<stdlib.h>

//【349】两个数组的交集
// 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int Table_count[1000] = {0};
    int val = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* p = (int*)malloc(sizeof(int) * val);   //申请较小数大小的内存空间
    int count = 0;
    for(int i = 0; i < nums1Size; i++){
        Table_count[nums1[i]] ++;
    }
    for(int i = 0; i < nums2Size; i++){
        if(Table_count[nums2[i]] > 0){
            p[count++] = nums2[i];
            Table_count[nums2[i]] = 0;
        }
    }
    *returnSize = count;
    return p;
}

int main()
{
    int number1[] = {1, 2, 2, 1};
    int number2[] = {2, 2};
    int index;
    int num1_size = sizeof(number1) / sizeof(number1[0]);
    int num2_size = sizeof(number2) / sizeof(number2[0]);

    int* ptr = intersection(number1, num1_size, number2, num2_size, &index);
    for(int i = 0; i < index; i++){
        printf("%d ", ptr[i]);
    }
    printf("\n");
    return 0;
}