#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// 【1523】在区间范围内统计奇数数目
// 给你两个非负整数 low 和 high 。请你返回 low 和 high 之间（包括二者）奇数的数目。

//超时
// int countOdds(int low, int high){
//     int res = 0;
//     if(low > high)  return res;
//     for(int i = low; i <= high; i ++){
//         if(i % 2 == 1)
//             res++;
//     }
//     return res;
// }


// 如果low和high都是偶数，那么它们之间的奇数个数就等于(high-low)/2；
// 如果low和high都是奇数，那么它们之间的奇数个数就等于(high-low)/2+1；
// 如果low和high一个是奇数一个是偶数，那么它们之间的奇数个数就等于(high-low+1)/2。
// 可以将这个思路转化为代码实现：
int countOdds(int low, int high){
    int res = 0;
    if(low > high)  return res;
    //1表示奇数，0表示偶数
    int flag1 = low % 2 == 1 ? 1 : 0;
    int flag2 = high % 2 == 1 ? 1 : 0; 
    if(flag1 == 0 && flag2 == 0){
        res = (high - low) / 2;
    }else if(flag1 && flag2){
        res = (high - low) / 2 + 1;
    }else{
        res = (high - low + 1) / 2;
    }
    return res;
}

int main(){
    int lownum, highnum;
    printf("please input two numbers:");
    scanf("%d %d", &lownum, &highnum);
    printf("result is %d\n", countOdds(lownum, highnum));
}