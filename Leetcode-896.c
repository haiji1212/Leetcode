#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//【896】单调数列
// 如果数组是单调递增或单调递减的，那么它是 单调 的。
// 如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i]> = nums[j]，那么数组 nums 是单调递减的。
// 当给定的数组 nums 是单调数组时返回 true，否则返回 false。

bool isMonotonic(int* nums, int numsSize) {
    int flag = 2;   //0为递增，1为递减，2为相等
    for(int i = 1; i < numsSize; i ++){
        if(nums[i - 1] > nums[i]){
            if(flag == 0)
                return false;
            else
                flag = 1;
        }else if(nums[i - 1] < nums[i]){
            if(flag == 1)
                return false;
            else
                flag = 0;
        }
    }
    return true;
}

int main(){
    int num[5] = {6, 5, 4, 4, 1};
    printf("%d\n", isMonotonic(num, 5));
    return 0;
}
