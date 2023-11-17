#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// 【977】有序数的平方
// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
#define NUMS_SIZE 5
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int slow = 0;
    int high = numsSize - 1;
    int* ptr = (int*)malloc(sizeof(int)*numsSize);
    for(int i = numsSize - 1; i >= 0; i --)
    {
        int leftnum = nums[slow] * nums[slow];
        int rightnum = nums[high] * nums[high];
        if(leftnum > rightnum){
            ptr[i] = leftnum;
            slow ++;
        }
        else if(leftnum <= rightnum){
            ptr[i] = rightnum;
            high --;
        }
    }
    return ptr;
}

int main(void){
    int number[NUMS_SIZE] = {};
    int returnsize;
    for(int i = 0; i < NUMS_SIZE; i++)
    {
        scanf("%d", &number[i]);
    }
    int* num = sortedSquares(number, NUMS_SIZE, &returnsize);
    for(int i = 0; i < returnsize; i++)
        printf("%d ", num[i]);
    return 0;
}
