#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 【976】三角形的最大周长
// 给定由一些正数（代表长度）组成的数组 nums ，
// 返回 由其中三个长度组成的、面积不为零的三角形的最大周长 。如果不能形成任何面积不为零的三角形，返回 0。

// 比较函数，用于自定义排序规则。这里是从小到大。
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void sortArray(int nums[], int size)
{
    qsort(nums, size, sizeof(int), cmp);
}

int largestPerimeter(int *nums, int numsSize)
{
    sortArray(nums, numsSize);
    for (int i = numsSize - 1; i >= 2; i--)
    {
        if ((nums[i - 2] + nums[i - 1]) > nums[i])
        {
            return nums[i - 2] + nums[i - 1] + nums[i];
        }
    }
    return 0;
}

int main()
{
    int nums[] = {2, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", largestPerimeter(nums, size));
    return 0;
}