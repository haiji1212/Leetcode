#include<stdio.h>
#include<stdlib.h>

//【1】两数之和
// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
// 你可以按任意顺序返回答案。

#define Size 2
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *result = (int*)malloc(sizeof(int) * 2);
    for(int i = 0; i < numsSize; i ++){
        for(int j = i + 1; j < numsSize; j ++)
        {
            if(*(nums + i) + *(nums + j) == target)
            {
                *result = i;
                *(result + 1) = j;
                *returnSize = 2;
            }
        }
    }
    return result;
}

int main()
{
    int NumSize = Size;
    int array[Size] = {3,3};
    int TarNum = 6;
    int *ptr = array;
    int return_size = 0;
    int *result = twoSum(ptr, NumSize, TarNum, &return_size);
    if(result != NULL)
    {
        printf("%d %d\n", *result, *(result + 1));
    }
    else
    {
        printf("NONE\n");
    }
    return 0;
}