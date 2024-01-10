#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//【1822】数组元素积的符号
// 已知函数 signFunc(x) 将会根据 x 的正负返回特定值：
// 如果 x 是正数，返回 1 。
// 如果 x 是负数，返回 -1 。
// 如果 x 是等于 0 ，返回 0 。
// 给你一个整数数组 nums 。令 product 为数组 nums 中所有元素值的乘积。
// 返回 signFunc(product) 。

int arraySign(int* nums, int numsSize) {
    int sign_flag = 0;
    for(int i = 0; i < numsSize; i ++){
        if(nums[i] == 0){
            return 0;
        }
        else if(nums[i] < 0){
            sign_flag ++;
        }
    }
    return (sign_flag % 2 == 0) ? 1 : -1;
}
