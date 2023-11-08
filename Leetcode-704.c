#include <stdio.h>

// 【704】二分查找
// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    if(target < nums[0] || target > nums[numsSize - 1])    
        return -1;
    else{
        while(left <= right)
        {
            int mid = (right + left) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
        }
        return -1;
    }
}

int main(void){
    int Nums[] = {-1,0,3,5,9,12};
    int Nums_Size = sizeof(Nums) / sizeof(Nums[0]);
    int Target_Num = 8;
    int search_num = search(Nums, Nums_Size, Target_Num);
    if(search_num == -1)
        printf("None\n");
    else
        printf("%d\n", search_num);
    return 0;
}
