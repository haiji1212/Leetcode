#include <stdio.h>

// 【35】搜索插入位置
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
#define STR_SIZE    4
int searchInsert(int* nums, int numsSize, int target){
    int* ptr = nums;
    int low = 0;
    int high = numsSize - 1;
    while(low <= high)
    {
        int mid = (low+high) / 2;
        if(target == ptr[mid])
            return mid;
        else if(target > ptr[mid])
            low = mid + 1;
        else if(target < ptr[mid])
            high = mid - 1;
    }
    return high + 1;
}

int main(){
    int a[STR_SIZE] = {0};
    for(int i = 0; i < STR_SIZE; i ++)
        scanf("%d", &a[i]);
    int target_num;
    scanf("%d", &target_num);
    int index = searchInsert(a, STR_SIZE, target_num);
    printf("%d\n", index);
    return 0;
}
