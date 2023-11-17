#include <stdio.h>
// 【26】删除有序数组中的重复项
// 给你一个非严格递增排列 的数组 nums ，
//请你原地删除重复出现的元素，使每个元素 只出现一次 ，
//返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
#define NUMS_SIZE 3
int removeDuplicates(int* nums, int numsSize) {
    int slow = 0;
    for(int fast = 0;fast < numsSize;fast++){
        if(fast < numsSize-1 && nums[fast] != nums[fast + 1])
        {
            nums[slow++] = nums[fast];
        }
        else if(fast == numsSize-1){
            if(nums[fast-1] != nums[fast]);
                nums[slow++] = nums[fast];
        }
    }
    return slow;
}

int main(void){
    int a[NUMS_SIZE] = {1, 1, 2};
    for(int i = 0; i < NUMS_SIZE; i ++)
    {
        scanf("%d", &a[i]);
    }
    int returnnum = removeDuplicates(a, NUMS_SIZE);
    printf("count is %d\n", returnnum);
    for(int i = 0; i < returnnum; i++)
        printf("%d ", a[i]);
    return 0;
}
