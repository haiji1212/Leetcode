#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// 【1572】矩阵对角线元素的和
// 给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。
// 请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。
int diagonalSum(int** mat, int matSize, int* matColSize){
    int sum = 0;
    for(int i = 0; i < *matColSize; i ++){
        sum += mat[i][i];
        sum += mat[i][*matColSize - i - 1];
    }
    if((*matColSize) % 2 == 0){
        return sum;
    }else
        return sum -= mat[(*matColSize) / 2][(*matColSize) / 2];
}
