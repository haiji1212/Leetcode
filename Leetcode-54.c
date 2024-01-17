#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// 【54】螺旋矩阵
// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if(matrixSize == 0){
        *returnSize = 0;
        return NULL;
    }
    int totalsize = matrixSize * (*matrixColSize);
    *returnSize = totalsize;
    int* res = (int*)malloc(sizeof(int) * totalsize);
    int up = 0, down = matrixSize - 1, left = 0, right = *matrixColSize - 1;
    int m = 0, n = 0;
    int dir = 0;    //right 0;  down 1;   left 2;   up 3;
    for(int i = 0; i < totalsize; i ++){
        switch(dir){
            case 0:
                res[i] = matrix[m][n];
                if(n == right){
                    up ++;
                    m ++;
                    dir = 1;
                }else{
                    n ++;
                }
                break;
            case 1:
                res[i] = matrix[m][n];
                if(m == down){
                    right --;
                    n --;
                    dir = 2;
                }else{
                    m ++;
                }
                break;           
            case 2:
                res[i] = matrix[m][n];
                if(n == left){
                    down --;
                    m --;
                    dir = 3;
                }else{
                    n --;
                }
                break;        
            case 3:
                res[i] = matrix[m][n];
                if(m == up){
                    left ++;
                    n ++;
                    dir = 0;
                }else{
                    m --;
                }
                break;   
            default:
                break;
        }
    }
    return res;
}
