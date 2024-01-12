#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//【1502】判断能否形成等差数列
// 给你一个数字数组 arr 。
// 如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。
// 如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false 。

int* bubblesort(int* number, int numssize){
    for(int i = 0; i < numssize - 1; i++){
        for(int j = 0; j < numssize - i - 1; j++){
            if(number[j] < number[j + 1]){
                int temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }
    return number;
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    int* ret = bubblesort(arr, arrSize);
    for(int i = 0 ; i < arrSize; i ++){
        printf("%d ", ret[i]);
    }    
    printf("\n");
    int index = ret[1] - ret[0];
    for(int k = 1; k < arrSize - 1; k ++){
        if(ret[k + 1] - ret[k] != index){
            return 0;
        }
    }
    return 1;
}

int main(){
    int num[5] = {2, 1, 6, 9, 3};
    printf("%d\n", canMakeArithmeticProgression(num, 5));
    return 0;
}
