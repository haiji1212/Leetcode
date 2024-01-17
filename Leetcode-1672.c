#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// 【1672】最富有客户的资产总量
// 给你一个 m x n 的整数网格 accounts ，其中 accounts[i][j] 是第 i​​​​​​​​​​​​ 位客户在第 j 家银行托管的资产数量。返回最富有客户所拥有的 资产总量 。
// 客户的 资产总量 就是他们在各家银行托管的资产数量之和。最富有客户就是 资产总量 最大的客户。

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int maxsum = INT_MIN, count;
    for(int i = 0; i < accountsSize; i ++){
        count = 0;
        for(int j = 0; j < *accountsColSize; j ++){
            count += accounts[i][j];
        }
        maxsum = count > maxsum ? count : maxsum;
    }
    return maxsum;
}
int main(void){
    int count[3][2] = {{1,5}, {7,3}, {3,5}};
    int col[3] = {2, 2, 2};
    int* account[3];
    for (int i = 0; i < 3; i++) {
        account[i] = count[i];
    }
    printf("%d\n", maximumWealth(account, 3, col));
    return 0;
}