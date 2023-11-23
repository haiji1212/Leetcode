#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//【202】快乐数
// 编写一个算法来判断一个数 n 是不是快乐数。
// 「快乐数」 定义为：
// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// 如果这个过程 结果为 1，那么这个数就是快乐数。
// 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
int CalSumSqare(int n){
    int sum = 0;
    do{
        sum += (( n % 10 ) * ( n % 10 ) );
    }while( (n /= 10) > 0 );    //注意，/= 和 > 的优先级关系
    return sum;
}
bool isHappy(int n) {
    int fast = n, slow = n;
    do{
        slow = CalSumSqare(slow);
        fast = CalSumSqare(CalSumSqare(fast));
    }while(slow != fast);   //无限循环，直至个位数
    return (slow == 1);
}
int main()
{
    int num;
    scanf("%d", &num);
    if(isHappy(num) == 1)
        printf("Happy\n");
    else
        printf("Sad\n");
    return 0;
}