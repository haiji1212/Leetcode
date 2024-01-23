#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// 【50】Pow(x,n)
// 实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。

double myPow(double x, int n) {
    if(n == 0)  return 1;
    if(n == 1)  return x;
    if(n == -1) return 1/x;
    double temp = myPow(x, n/2);
    return temp * temp * myPow(x, n %2);
}