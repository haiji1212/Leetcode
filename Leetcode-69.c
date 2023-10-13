#include<stdio.h>

//【69】x的平方根
// 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
// 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
// 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
int mySqrt(int x);

int mySqrt(int x)
{
    long long i = 0;
    if(x == 1)
        return 1;
    while(i <= x)
    {
        if((i * i) <= x)
            i ++;
        else
            return (i - 1);
    }
    return 0;
}

int main()
{
    int a = 2;
    int num = 0;
    num = mySqrt(a);
    printf("the num is %d\n", num);
    return 0;
}