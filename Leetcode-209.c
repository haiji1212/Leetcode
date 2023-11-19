#include <stdio.h>
#include <stdlib.h>
// 【209】长度最小的数组
// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。
//如果不存在符合条件的子数组，返回 0。
#define NUM_SIZE    6
int minSubArrayLen(int target, int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return 0;
    int result = INT_MAX;
    int sum = 0;
    int j = 0;
    int temp = 0;
    for(int i = 0; i < numsSize; i ++){
        sum += nums[i];
        while(sum >= target){
            temp = (i - j + 1);
            result = result < temp ? result : temp;
            sum -= nums[j++];     
        }
    } 
    return result == INT_MAX ? 0 : result;   
}
int main(void){
    int number[NUM_SIZE] = {2,3,1,2,4,3};   //2,3,1,2,4,3   //1,4,4
    int targetNum = 7;
    int resultNum = minSubArrayLen(targetNum, number, NUM_SIZE);
    printf("result is %d\n", resultNum);
    return 0;
}

/*
 * 暴力求解 leetcode超时
 * int minSubArrayLen(int target, int* nums, int numsSize) {
    int result = INT_MAX;
    if(nums == NULL || numsSize == 0)
        result = 0;
    int tempNum;
    for(int i = 0; i < numsSize; i ++){
        int sum = 0;
        for(int j = i; j < numsSize; j ++){
            sum += nums[j];
            if(sum >= target){
                tempNum = (j - i + 1);
                result = tempNum < result ? tempNum : result;
                break;
            }
        }
    }
    return result == INT_MAX ? 0 : result;
}
*/
