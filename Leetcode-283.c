#include <stdio.h>
// 【283】移动0
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
#define NUMS_SIZE 1
void moveZeroes(int* nums, int numsSize) {
    int slow = 0;
    int m = 0;
    for(int fast = 0; fast < numsSize ; fast++)
    {
        if(nums[fast] != 0)
        {
            nums[slow++] = nums[fast];
        }
        else{
            m ++;
        }
    }
    for(int i = numsSize - m; i < numsSize; i++)
    {
        nums[i] = 0;
    }
    for(int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
}

int main(void){
    int a[NUMS_SIZE] = {};
    for(int i = 0; i < NUMS_SIZE; i ++)
    {
        scanf("%d", &a[i]);
    }
    moveZeroes(a, NUMS_SIZE);
    return 0;
}
