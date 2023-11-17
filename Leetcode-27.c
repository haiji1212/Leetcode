#include <stdio.h>
// 【27】移除元素
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
#define NUMS_SIZE 8
int removeElement(int* nums, int numsSize, int val) {
    int slow = 0;
    for(int fast = 0; fast < numsSize; fast++)
    {
        if(nums[fast] != val){
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}
int main(void){
    int a[NUMS_SIZE] = {0};
    for(int i = 0; i < NUMS_SIZE; i ++)
    {
        scanf("%d", &a[i]);
    }
    int tarnum;
    scanf("%d", &tarnum);
    int returnnum = removeElement(a, NUMS_SIZE, tarnum);
    printf("count is %d\n", returnnum);
    for(int i = 0; i < returnnum; i++)
        printf("%d ", a[i]);
    return 0;
}
